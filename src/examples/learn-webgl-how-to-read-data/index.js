const MAT4 = glMatrix.mat4;
const MAT3 = glMatrix.mat3;
const VEC4 = glMatrix.vec4;
const VEC3 = glMatrix.vec3;

function main() {

    const canvas = document.getElementById('webgl-canvas');

    const gl = canvas.getContext('webgl');

    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height); // 告诉 WebGL 执行 NDC 坐标到屏幕坐标的变换
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    const vertexShaderSrc = `
    attribute vec4 aVertexPosition;
    attribute vec4 aVertexColor;

    uniform mat4 uModelViewMatrix;
    uniform mat4 uProjectionMatrix;

    varying lowp vec4 vColor;

    void main() {
      gl_Position = uProjectionMatrix * uModelViewMatrix * aVertexPosition;
      vColor = aVertexColor;
    }
`;

    const fragmentShaderSrc = `
    varying lowp vec4 vColor;

    void main() {
      gl_FragColor = vColor;
    }
`;

    const vertexShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertexShader, vertexShaderSrc);
    gl.compileShader(vertexShader);
    if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
        console.error(`An error occurred compiling the vertex shader ${gl.getShaderInfoLog(vertexShader)}`);
        gl.deleteShader(vertexShader);
    }

    const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, fragmentShaderSrc);
    gl.compileShader(fragmentShader);
    if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
        console.error(`An error occurred compiling the vertex shader ${gl.getShaderInfoLog(fragmentShader)}`);
        gl.deleteShader(fragmentShader);
    }

    const shaderProgram = gl.createProgram();
    gl.attachShader(shaderProgram, vertexShader);
    gl.attachShader(shaderProgram, fragmentShader);
    gl.linkProgram(shaderProgram);
    gl.useProgram(shaderProgram);

    if (!gl.getProgramParameter(shaderProgram, gl.LINK_STATUS)) {
        console.error(`Unable to initialize the shader program: ${gl.getProgramInfoLog(shaderProgram)}`);
    }

    const fov = 120 * Math.PI / 180;
    const aspect = gl.canvas.clientWidth / gl.canvas.clientHeight;
    const zNear = 0.3;
    const zFar = 100.0;
    const projectionMatrix = MAT4.create();
    MAT4.perspective(projectionMatrix, fov, aspect, zNear, zFar);
    const modelViewMatrix = MAT4.create();
    MAT4.translate(modelViewMatrix, modelViewMatrix, [10.0, 0.0, -10.0]);

    const uProjectionMatrix = gl.getUniformLocation(shaderProgram, 'uProjectionMatrix');
    const uModelViewMatrix = gl.getUniformLocation(shaderProgram, 'uModelViewMatrix');

    gl.uniformMatrix4fv(uProjectionMatrix, false, projectionMatrix);
    gl.uniformMatrix4fv(uModelViewMatrix, false, modelViewMatrix);

    const vertexData = [

        0, -100, -90, 1, 1, 0, 0, 1,    // 前4位是顶点坐标,后4位是颜色
        150, 125, -90, 1, 0, 1, 0, 1,
        -175, 100, -90, 1, 0, 0, 1, 1

    ];

    const buffer = gl.createBuffer();

    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);

    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertexData), gl.STATIC_DRAW);

    const a_vertexPosition = gl.getAttribLocation(shaderProgram, 'aVertexPosition');
    gl.vertexAttribPointer(
        a_vertexPosition,
        4,
        gl.FLOAT,
        false,
        32,
        0
    );
    gl.enableVertexAttribArray(a_vertexPosition);

    const a_vertexColor = gl.getAttribLocation(shaderProgram, 'aVertexColor');
    gl.vertexAttribPointer(
        a_vertexColor,
        4,
        gl.FLOAT,
        false,
        32,
        16
    );
    gl.enableVertexAttribArray(a_vertexColor);

    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 3);

}

main();
