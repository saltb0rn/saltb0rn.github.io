const MAT4 = glMatrix.mat4;
const MAT3 = glMatrix.mat3;
const VEC4 = glMatrix.vec4;
const VEC3 = glMatrix.vec3;

function main() {
    const canvas = document.getElementById('glCanvas'),
          gl = canvas.getContext('webgl');
    if (gl === null) {
        alert("Unable to initialize WEBGL. Your browser or machine may not support it.");
        return;
    }
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    // 设置 shaders,可以把每个看作是 (shader vertexAttr) => resultVertex
    const shaderProgram = initShaderProgram(gl);
    const programInfo = {
        program: shaderProgram,
              attribLocations: {
                  vertexPosition: gl.getAttribLocation(shaderProgram, 'aVertexPosition'),
                  vertexColor: gl.getAttribLocation(shaderProgram, 'aVertexColor')
                  /**
                     WebGLRenderingContext.getAttribLocation() 获取 vertex shader 里面特定的 attribute 声明的索引,
                   */
              },
              uniformLocations: {
                  projectionMatrix: gl.getUniformLocation(shaderProgram, 'uProjectionMatrix'),
                  modelViewMatrix: gl.getUniformLocation(shaderProgram, 'uModelViewMatrix')
              }
    };
    console.log(programInfo);
    // 设置顶点数据
    const buffers = initBuffers(gl);

    // 设置shaders里面定义的 attribute 以及 uniform 变量,并且根据顶点数据进行绘制
    render(gl, programInfo, buffers);

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

/**
   @param ctx: { WebGLRenderingContext || WebGLRenderingContext2 }
   @return { WebGLProgram || null }
*/
function initShaderProgram(ctx) {
    const vsShader = loadShader(ctx, ctx.VERTEX_SHADER, document.getElementById('vertex-shader').innerText);
    const fsShader = loadShader(ctx, ctx.FRAGMENT_SHADER, document.getElementById('fragment-shader').innerText);

    const shaderProgram = ctx.createProgram();
    ctx.attachShader(shaderProgram, vsShader);
    ctx.attachShader(shaderProgram, fsShader);
    ctx.linkProgram(shaderProgram);
    if (!ctx.getProgramParameter(shaderProgram, ctx.LINK_STATUS)) {
        alert('Unable to initialize the shader program: ' + ctx.getProgramInfoLog(shaderProgram));
        return null;
    }
    return shaderProgram;
}

function initBuffers(ctx) {
    const positionBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ARRAY_BUFFER, positionBuffer);
    /**
      WebGLRenderingContext.ARRAY_BUFFER 一个数组,包含了所有顶点的某种属性,
      比如顶点的坐标,贴图的坐标,或者顶点的颜色.
      WebGLRenderingContext.bindBuffer(WebGLRenderingContext.ARRAY_BUFFER, buffer)
      把 buffer 绑定到当前上下文 WebGLRenderingContext 中
     */
    const positions = [
        -1.0, 1.0,
        1.0, 1.0,
        -1.0, -1.0,
        1.0, -1.0
    ];
    /** 操作当前绑定的 buffer */
    ctx.bufferData(
        ctx.ARRAY_BUFFER,
        new Float32Array(positions),
        ctx.STATIC_DRAW
    );

    const colors = [
        1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0,
        0.0, 0.0, 0.1, 1.0
    ];
    const colorBuffer = ctx.createBuffer();
    ctx.bindBuffer(ctx.ARRAY_BUFFER, colorBuffer);
    ctx.bufferData(ctx.ARRAY_BUFFER, new Float32Array(colors), ctx.STATIC_DRAW);

    return {
        position: positionBuffer,
        color: colorBuffer
    };
}

function draw(ctx, programInfo, modelViewMatrix, projectionMatrix, buffers) {
    {
        const numComponents =  2;
        const type = ctx.FLOAT;
        const normalize = false;
        const stride = 0;
        const offset = 0;
        ctx.bindBuffer(ctx.ARRAY_BUFFER, buffers.position);
        ctx.vertexAttribPointer(
            programInfo.attribLocations.vertexPosition,
            numComponents,
            type,
            normalize,
            stride,
            offset
        );
        ctx.enableVertexAttribArray(
            programInfo.attribLocations.vertexPosition
        );
    }

    {
        const numComponents = 4;
        const type = ctx.FLOAT;
        const normalize = false;
        const stride = 0;
        const offset = 0;
        ctx.bindBuffer(ctx.ARRAY_BUFFER, buffers.color);
        ctx.vertexAttribPointer(
            programInfo.attribLocations.vertexColor,
            numComponents,
            type,
            normalize,
            stride,
            offset
        );
        ctx.enableVertexAttribArray(
            programInfo.attribLocations.vertexColor
        );
    }

    ctx.useProgram(programInfo.program);

    ctx.uniformMatrix4fv(
        programInfo.uniformLocations.projectionMatrix,
        false,
        projectionMatrix
    );

    ctx.uniformMatrix4fv(
        programInfo.uniformLocations.modelViewMatrix,
        false,
        modelViewMatrix
    );

    {
        const offset = 0;
        const vertexCount = 4;
        ctx.drawArrays(ctx.TRIANGLE_STRIP, offset, vertexCount);
    }

}

/** 绘制 */
function render(ctx, programInfo, buffers) {
    ctx.clearColor(0.0, 0.0, 0.0, 1.0);
    ctx.clearDepth(1.0);
    ctx.enable(ctx.DEPTH_TEST);
    ctx.depthFunc(ctx.LEQUAL);
    ctx.clear(ctx.COLOR_BUFFER_BIT | ctx.DEPTH_BUFFER_BIT);

    // 绘制第一个
    {
        const fov = 45 * Math.PI / 180;
        const aspect = ctx.canvas.clientWidth / ctx.canvas.clientHeight;
        const zNear = 0.1;
        const zFar = 100.0;
        const projectionMatrix = MAT4.create();
        const modelMatrix = MAT4.create();
        const viewMatrix = MAT4.create();
        const modelViewMatrix = MAT4.create();
        MAT4.lookAt(
            viewMatrix,
            VEC3.fromValues(0.0, 0.0, -6.0),
            VEC3.fromValues(0.0, 0.0, 0.0),
            VEC3.fromValues(0.0, 1.0, 0.0)
        );
        MAT4.rotate(
            modelMatrix,
            modelMatrix,
            45 * Math.PI / 180,
            VEC3.fromValues(0.0, 0.0, 1.0)
        );
        MAT4.mul(modelViewMatrix, viewMatrix, modelMatrix);
        MAT4.perspective(projectionMatrix, fov, aspect, zNear, zFar);

        draw(ctx, programInfo, modelViewMatrix, projectionMatrix, buffers);
    }


    // 绘制第二个
    {
        const fov = 45 * Math.PI / 180;
        const aspect = ctx.canvas.clientWidth / ctx.canvas.clientHeight;
        const zNear = 0.1;
        const zFar = 100.0;
        const projectionMatrix = MAT4.create();
        const modelMatrix = MAT4.create();
        const viewMatrix = MAT4.create();
        const modelViewMatrix = MAT4.create();
        MAT4.lookAt(
            viewMatrix,
            VEC3.fromValues(0.0, 0.0, -6.0),
            VEC3.fromValues(0.0, 0.0, 0.0),
            VEC3.fromValues(0.0, 1.0, 0.0)
        );
        MAT4.mul(modelViewMatrix, viewMatrix, modelMatrix);
        MAT4.perspective(projectionMatrix, fov, aspect, zNear, zFar);
        draw(ctx, programInfo, modelViewMatrix, projectionMatrix, buffers);
    }

}


main();
