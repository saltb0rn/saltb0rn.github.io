#version 130

// filename: dip-sobel.frag
// run: glslViewer dip-sobel.frag textures/2999645.jpg

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

  // Sobel
  float kernel_x[9] = float[9](-1, 0, 1, -2, 0, 2, -1, 0, 1);
  float kernel_y[9] = float[9](1, 2, 1, 0, 0, 0, -1, -2, -1);
  vec4 conv_x = convolution(uv, kernel_x, pixels);
  vec4 conv_y = convolution(uv, kernel_y, pixels);
  vec4 g = sqrt(conv_x * conv_x + conv_y * conv_y);

  // 相似度高, g 越亮, 我们这里想要黑色边缘线, 所以进行反转
  gl_FragColor = vec4(1. - g.rgb, 1.0);
}
