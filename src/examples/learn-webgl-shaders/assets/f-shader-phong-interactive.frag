#version 300 es

in highp vec4 vColor;
in highp vec3 vNormal;
in highp vec3 vPosition;

uniform highp vec4 lightPosition;
uniform highp vec4 lightColor;
uniform highp vec3 cameraPosition;
uniform highp float shininess;
uniform highp float ambientStrength;
uniform int lightMask;
uniform int blinn;

out highp vec4 outColor;

void main() {

  if (lightMask == 0) {
    outColor = vColor;
  } else {
    highp vec3 lightDirection;
    if (lightPosition.w == 0.0) {
      lightDirection = normalize(lightPosition.xyz);
    } else {
      lightDirection = normalize(lightPosition.xyz - vPosition.xyz);
    }
    highp vec3 normal = normalize(vNormal);
    highp vec4 result_color = vec4(0.0);

    if ((lightMask & 1) == 1) {
      highp vec4 ambient = ambientStrength * lightColor;
      result_color += ambient;
    }

    if ((lightMask >> 1 & 1) == 1) {
      highp vec4 diffuse = max(dot(lightDirection, normal), 0.0) * lightColor;
      result_color += diffuse;
    }

    if ((lightMask >> 2 & 1) == 1) {
      highp vec4 specular;
      highp vec3 viewDirection = normalize(cameraPosition - vPosition);

      if ((blinn & 1) == 1) {
        highp vec3 halfwayDirection = normalize(lightDirection + viewDirection);
        specular = pow(max(dot(halfwayDirection, normal), 0.0), shininess) * lightColor;
      } else {
        // highp vec3 reflectDirection = normalize(-lightDirection + 2.0 * dot(lightDirection, normal) * normal);
        highp vec3 reflectDirection = normalize(reflect(-lightDirection, normal));
        specular = pow(max(dot(reflectDirection, viewDirection), 0.0), shininess) * lightColor;
      }
      result_color += specular;
    }
    result_color *= vColor;

    outColor = vec4(result_color.xyz, vColor.a);
  }
}
