#version 130

// filename: dip-laplacian.frag
// run: glslViewer dip-laplacian.frag fallout-4k-game-artwork.jpg

#ifndef PLATFORM_WEBGL
uniform vec2 u_resolution;
uniform sampler2D u_tex0;

#define iResolution u_resolution
#define iChannel0 u_tex0
#endif

vec4 convolution(vec2 uv, float[9] kernel, vec4[9] pixels) {
  vec4 conv = vec4(0.0);
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      int index = j * 3 + i;
      conv += pixels[index] * kernel[index];
    }
  }
  return conv;
}

void main () {
  vec2 uv = gl_FragCoord.xy / iResolution.xy;
  vec2 steps = 1.0 / iResolution.xy;
  // Pixel Sampling
  vec4 pixels[9];
  for (int i = -1; i <= 1; i++) { // [-1, 1] => [0, 2]
    for (int j = 1; j >= -1; j--) { // [1, -1] => [0, 2]
      int index = (-j + 1) * 3 + (i + 1);
      vec4 c = texture(iChannel0, uv + vec2(float(i) * steps.x, float(j) * steps.y));
      pixels[index] = c;
    }
  }

  // GrayScale
  for (int i = 0; i < pixels.length(); i++) {
    float gray = dot(pixels[i].rgb, vec3(0.299, 0.587, 0.114));
    pixels[i] = vec4(vec3(gray), pixels[i].a);
  }

  // Laplacian
  float kernel[9] = float[9](0, 1, 0, 1, -4, 1, 0, 1, 0);
  vec4 conv = convolution(uv, kernel, pixels);
  gl_FragColor = vec4(1. - conv.rgb, 1.0);
}
