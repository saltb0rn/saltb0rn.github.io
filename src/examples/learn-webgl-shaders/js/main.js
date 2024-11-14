const MAT4 = glMatrix.mat4;
const MAT3 = glMatrix.mat3;
const VEC4 = glMatrix.vec4;
const VEC3 = glMatrix.vec3;

let cubeRotation = 0.0;
let isPlaying = false;
let mask = 0b0;
let blinn = 0;

async function main() {

    const canvas = document.getElementById('glCanvas'),
          ctx = canvas.getContext('webgl2');
    if (ctx === null) {
        alert("Unable to initialize WEBGL. Your browser or machine may not support it.");
        return;
    }
    ctx.clear(ctx.COLOR_BUFFER_BIT);
    ctx.enable(ctx.DEPTH_TEST);

    /** Init buffers */
    // 位置 attribute
    const positions = [
        // Front face
        -1.0, -1.0, 1.0, 1.0,
        1.0, -1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        -1.0, 1.0, 1.0, 1.0,

        // Back face
        -1.0, -1.0, -1.0, 1.0,
        -1.0, 1.0, -1.0, 1.0,
        1.0, 1.0, -1.0, 1.0,
        1.0, -1.0, -1.0, 1.0,

        // Top face
        -1.0, 1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, -1.0, 1.0,

        // Bottom face
        -1.0, -1.0, -1.0, 1.0,
        1.0, -1.0, -1.0, 1.0,
        1.0, -1.0, 1.0, 1.0,
        -1.0, -1.0, 1.0, 1.0,

        // Right face
        1.0, -1.0, -1.0, 1.0,
        1.0, 1.0, -1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, -1.0, 1.0, 1.0,

        // Left face
        -1.0, -1.0, -1.0, 1.0,
        -1.0, -1.0, 1.0, 1.0,
        -1.0, 1.0, 1.0, 1.0,
        -1.0, 1.0, -1.0, 1.0,
    ];
    const positionBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ARRAY_BUFFER, positionBuffer);
    /** 把数据填充到 buffer 中 */
    ctx.bufferData(
        ctx.ARRAY_BUFFER,
        new Float32Array(positions),
        ctx.STATIC_DRAW
    );

    // 颜色 attribute
    const _colors = [
        .5, .5, .5, 1.0,   // Front face: white

        .5, 0.0, 0.0, 1.0,   // Back face: red

        0.0, .5, 0.0, 1.0,   // Top face: green

        0.0, 0.0, .5, 1.0,   // Bottom face: blue

        .5, .5, 0.0, 1.0,   // Right face: yellow

        .5, 0.0, .5, 1.0,   // Left face: purple
    ];
    let colors = [];
    for (let i = 0; i < _colors.length; i+=4) {
        let c = [ _colors[i], _colors[i+1], _colors[i+2], _colors[i+3] ];
        colors = colors.concat(c, c, c, c);
    }
    const colorBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ARRAY_BUFFER, colorBuffer);
    ctx.bufferData(ctx.ARRAY_BUFFER, new Float32Array(colors), ctx.STATIC_DRAW);

    //
    const _vertexNormals = [
        // Front
        0.0, 0.0, 1.0, 1.0,

        // Back
        0.0, 0.0, -1.0, 1.0,

        // Top
        0.0, 1.0, 0.0, 1.0,

        // Bottom
        0.0, -1.0, 0.0, 1.0,

        // Right
        1.0, 0.0, 0.0, 1.0,

        // Left
        -1.0, 0.0, 0.0, 1.0,
    ];
    let vertexNormals = [];
    for (let i = 0; i < _vertexNormals.length; i+=4) {
        let n = [
            _vertexNormals[i], _vertexNormals[i+1],
            _vertexNormals[i+2], _vertexNormals[i+3]
        ];
        vertexNormals = vertexNormals.concat(n, n, n, n);
    }
    const normalBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ARRAY_BUFFER, normalBuffer);
    ctx.bufferData(ctx.ARRAY_BUFFER, new Float32Array(vertexNormals), ctx.STATIC_DRAW);

    const indices = [
        0, 1, 2,     0, 2, 3,   // front
        4, 5, 6,     4, 6, 7,   // back
        8, 9, 10,    8, 10, 11,  // top
        12, 13, 14,    12, 14, 15,  // bottom
        16, 17, 18,    16, 18, 19,  // right
        20, 21, 22,    20, 22, 23,  // left
    ];
    const indexBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ELEMENT_ARRAY_BUFFER, indexBuffer);
    ctx.bufferData(ctx.ELEMENT_ARRAY_BUFFER, new Uint16Array(indices), ctx.STATIC_DRAW);

    /**/

    /* Init shader */
    let vshCode = await fetchShaderSource('assets/v-shader-light.vert');
    let fshCode = await fetchShaderSource('assets/f-shader-phong-interactive.frag');
    // let fshCode = await fetchShaderSource('assets/f-shader-phong.frag');
    let vsShader = loadShader(ctx, ctx.VERTEX_SHADER, vshCode);
    let fsShader = loadShader(ctx, ctx.FRAGMENT_SHADER, fshCode);

    const shaderProgram = ctx.createProgram();
    ctx.attachShader(shaderProgram, vsShader);
    ctx.attachShader(shaderProgram, fsShader);
    ctx.linkProgram(shaderProgram);
    ctx.useProgram(shaderProgram);

    if (!ctx.getProgramParameter(shaderProgram, ctx.LINK_STATUS)) {
        alert('Unable to initialize the shader program: ' + ctx.getProgramInfoLog(shaderProgram));
        return;
    }
    let webgl_debug_ext = ctx.getExtension('WEBGL_debug_shaders');
    if (webgl_debug_ext) {
        let vs = webgl_debug_ext.getTranslatedShaderSource(vsShader);
        let fs = webgl_debug_ext.getTranslatedShaderSource(fsShader);
        document.getElementById('compiled-vs').innerText = vs;
        document.getElementById('compiled-fs').innerText = fs;
    } else {
        document.getElementById('code').style.display = 'none';
    }
    // 设置shaders里面定义的 attribute 以及 uniform 变量,并且根据顶点数据进行绘制
    let then = 0;
    function animate() {
        if (isPlaying) {
            cubeRotation += 0.015;
            // return requestAnimationFrame(animate);
        }
        drawScene(ctx, shaderProgram, {
            positionBuffer,
            colorBuffer,
            indexBuffer,
            normalBuffer
        });
        return requestAnimationFrame(animate);
    }
    requestAnimationFrame(animate);

};

/**
   @param ctx: { WebGLRenderingContext || WebGLRenderingContext2 }
   @param type: { ctx.VERTEX_SHADER || ctx.FRAGMENT_SHADER }
   @param src: { String }
   @return { WebGLShader || null }
*/
function loadShader(ctx, type, src) {
    const shader = ctx.createShader(type);
    ctx.shaderSource(shader, src);
    ctx.compileShader(shader);
    if (!ctx.getShaderParameter(shader, ctx.COMPILE_STATUS)) {
        alert('An error occurred compiling the shaders' + ctx.getShaderInfoLog(shader));
        ctx.deleteShader(shader);
        return null;
    }
    return shader;
}

async function fetchShaderSource(res) {
    return await fetch(res).then(rsp => rsp.text());
}

async function drawObj1(
    ctx, shaderProgram,
    { positionBuffer, indexBuffer, colorBuffer, normalBuffer }
) {
    /**
      WebGLRenderingContext.ARRAY_BUFFER 一个数组,包含了所有顶点的某种属性,
      比如顶点的坐标,贴图的坐标,或者顶点的颜色.

      WebGLRenderingContext.bindBuffer(WebGLRenderingContext.ARRAY_BUFFER, buffer)
      把 buffer 绑定到当前上下文 WebGLRenderingContext 中
     */

    let cameraPosition = VEC3.fromValues(
        document.getElementById('vposx').value || 0,
        document.getElementById('vposy').value || 0,
        document.getElementById('vposz').value || 0,
    );
    {
        const numComponents = 3;
        const type = ctx.FLOAT;
        const normalize = false;
        const stride = 16;
        const offset = 0;
        const aVertexPosition = ctx.getAttribLocation(shaderProgram, 'aVertexPosition');
        ctx.bindBuffer(ctx.ARRAY_BUFFER, positionBuffer);
        ctx.vertexAttribPointer(
            aVertexPosition,
            numComponents,
            type,
            normalize,
            stride,
            offset
        );
        ctx.enableVertexAttribArray(aVertexPosition);
    }

    {
        const numComponents = 4;
        const type = ctx.FLOAT;
        const normalize = false;
        const stride = 16;
        const offset = 0;
        const aVertexColor = ctx.getAttribLocation(shaderProgram, 'aVertexColor');
        ctx.bindBuffer(ctx.ARRAY_BUFFER, colorBuffer);
        ctx.vertexAttribPointer(
            aVertexColor,
            numComponents,
            type,
            normalize,
            stride,
            offset
        );
        ctx.enableVertexAttribArray(aVertexColor);
    }

    {
        const numComponents = 3;
        const type = ctx.FLOAT;
        const normalize = false;
        const stride = 16;
        const offset = 0;
        const aVertexNormal = ctx.getAttribLocation(shaderProgram, 'aVertexNormal');

        // let attrs = ctx.getProgramParameter(shaderProgram, ctx.ACTIVE_ATTRIBUTES);
        // for (let i = 0; i < attrs; i++) {
        //     const info = ctx.getActiveAttrib(shaderProgram, i);
        //     console.log('name:', info.name, 'type:', info.type, 'size:', info.size);
        // }

        ctx.bindBuffer(ctx.ARRAY_BUFFER, normalBuffer);
        ctx.vertexAttribPointer(
            aVertexNormal,
            numComponents,
            type,
            normalize,
            stride,
            offset
        );
        ctx.enableVertexAttribArray(aVertexNormal);
    }

    {
        // ctx.useProgram(shaderProgram);
        const fov = 55 * Math.PI / 180;
        const aspect = ctx.canvas.clientWidth / ctx.canvas.clientHeight;
        const zNear = 0.3;
        const zFar = 100.0;
        const projectionMatrix = MAT4.create();
        const modelMatrix = MAT4.create();
        const viewMatrix = MAT4.create();
        const modelViewMatrix = MAT4.create();
        const normalMatrix = MAT4.create();
        MAT4.lookAt(
            viewMatrix,
            cameraPosition,
            VEC3.fromValues(0.0, 0.0, 0.0),
            VEC3.fromValues(0.0, 1.0, 0.0)
        );
        MAT4.rotate(
            modelMatrix,
            modelMatrix,
            cubeRotation,
            VEC3.fromValues(0.0, 0.0, 1.0)
        );
        MAT4.rotate(
            modelMatrix,
            modelMatrix,
            cubeRotation * .7,
            VEC3.fromValues(0.0, 1.0, 0.0)
        );

        // 不能让物体和相机靠太近,后者 shininess 为 0 的时候会出现黑影
        let T = MAT4.fromTranslation(
            MAT4.create(),
            VEC3.fromValues(0.0, 0.0, -5)
        );
        MAT4.mul(modelMatrix, T, modelMatrix);

        MAT4.mul(modelViewMatrix, viewMatrix, modelMatrix);
        MAT4.invert(normalMatrix, modelMatrix);
        MAT4.transpose(normalMatrix, normalMatrix);
        MAT4.perspective(projectionMatrix, fov, aspect, zNear, zFar);

        ctx.uniformMatrix4fv(
            ctx.getUniformLocation(shaderProgram, 'uProjectionMatrix'),
            false,
            projectionMatrix
        );

        ctx.uniformMatrix4fv(
            ctx.getUniformLocation(shaderProgram, 'uViewMatrix'),
            false,
            viewMatrix
        );

        ctx.uniformMatrix4fv(
            ctx.getUniformLocation(shaderProgram, 'uModelMatrix'),
            false,
            modelMatrix
        );

        ctx.uniformMatrix4fv(
            ctx.getUniformLocation(shaderProgram, 'uNormalMatrix'),
            false,
            normalMatrix
        );

        ctx.uniform4fv(
            ctx.getUniformLocation(shaderProgram, 'lightPosition'),
            VEC4.fromValues(
                document.getElementById('lposx').value || 0.0,
                document.getElementById('lposy').value || 0.0,
                document.getElementById('lposz').value || 0.0,
                document.getElementById('lposw').value || 0.0,
            )
        );

        ctx.uniform3fv(
            ctx.getUniformLocation(shaderProgram, 'cameraPosition'),
            VEC3.fromValues(cameraPosition[0], cameraPosition[1], cameraPosition[2])
        );


        ctx.uniform1f(
            ctx.getUniformLocation(shaderProgram, 'shininess'),
            document.getElementById('shininess').value || 0,
        );

        ctx.uniform1f(
            ctx.getUniformLocation(shaderProgram, 'ambientStrength'),
            document.getElementById('ambientLvl').value || 0.1,
        );

        ctx.uniform4fv(
            ctx.getUniformLocation(shaderProgram, 'lightColor'),
            VEC4.fromValues(
                document.getElementById('lcr').value || 0.0,
                document.getElementById('lcg').value || 0.0,
                document.getElementById('lcb').value || 0.0,
                document.getElementById('lca').value || 0.0,
            )
        );

        ctx.uniform1i(
            ctx.getUniformLocation(shaderProgram, 'blinn'),
            blinn
        );

        ctx.uniform1i(
            ctx.getUniformLocation(shaderProgram, 'lightMask'),
            mask
        );

        ctx.bindBuffer(ctx.ELEMENT_ARRAY_BUFFER, indexBuffer);
        const offset = 0;
        /*
          一个立方体有 24 个顶点,但是一个面需要 2 个三角形,一个三角形需要 3 个顶点,
          有 6 个面,所以这里 6 * 2 * 3 = 36.

          不过颜色属性为 6 个的时候,会警告说需要 24 个顶点属性,这十分有意思
         */
        const vertexCount = 36;
        ctx.drawElements(ctx.TRIANGLES, vertexCount, ctx.UNSIGNED_SHORT, offset);
    }

}

function drawScene(ctx, shaderProgram, buffers) {
    ctx.clearColor(0.0, 0.0, 0.0, 1.0);
    ctx.clearDepth(1.0);
    ctx.enable(ctx.DEPTH_TEST);
    ctx.depthFunc(ctx.LEQUAL);
    ctx.clear(ctx.COLOR_BUFFER_BIT | ctx.DEPTH_BUFFER_BIT);

    // 物体1
    drawObj1(ctx, shaderProgram, buffers);
}

main();
