varying lowp vec4 vColor;
varying lowp vec4 vNormal;
varying lowp vec4 vPosition;

uniform lowp vec4 lightPosition;
uniform lowp vec4 lightColor;
uniform lowp vec4 cameraPosition;
uniform lowp float shininess;
uniform lowp float ambientStrength;

void main() {

  lowp vec4 ambient = ambientStrength * lightColor;

  lowp vec4 lightDirection = normalize(lightPosition - vPosition);
  lowp vec4 normal = normalize(vNormal);

  lowp vec4 diffuse = max(dot(lightDirection, normal), 0.0) * lightColor;

  lowp vec4 reflectDirection = normalize(-lightDirection + 2.0 * dot(lightDirection, normal) * normal);
  lowp vec4 viewDirection = normalize(cameraPosition - vPosition);
  lowp vec4 specular = pow(max(dot(reflectDirection, viewDirection), 0.0), shininess) * lightColor;

  lowp vec4 result_color = (ambient + diffuse + specular) * vColor;
  // lowp vec4 result_color = (ambient + diffuse) * vColor + specular;
  gl_FragColor = vec4(vec3(result_color), vColor.a);
}
