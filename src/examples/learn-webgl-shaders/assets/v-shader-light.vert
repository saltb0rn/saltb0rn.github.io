#version 300 es

in vec3 aVertexPosition;
in vec4 aVertexColor;
in vec3 aVertexNormal;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;
uniform mat4 uNormalMatrix;

out highp vec4 vColor;
out highp vec3 vNormal;
out highp vec3 vPosition;

void main() {
  gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(aVertexPosition.xyz, 1.0);

  vColor = aVertexColor;
  vNormal = vec3(uNormalMatrix * vec4(aVertexNormal.xyz, 1.0));
  vPosition =  vec3(uModelMatrix * vec4(aVertexPosition.xyz, 1.0));
}
