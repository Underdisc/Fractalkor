#version 330 core

#include "ComplexOps.glsl"
#include "FractalHelper.glsl"

in vec2 iFragPerc;

out vec4 iFinalColor;

uniform int uIterations;
uniform vec2 uCenter;
uniform float uWidth;
uniform float uHeight;

void main()
{
  vec2 uv = FindUv(iFragPerc, uCenter, uWidth, uHeight);
  vec3 color = vec3(0.0, 0.0, 0.0);
  vec2 z = vec2(uv.x, uv.y);
  vec2 c = z;
  for (int i = 0; i < uIterations; i += 1)
  {
    z = ComplexAdd(ComplexMul(z,z), c);
    if (ComplexAbs(z) > 2)
    {
      color = ColorOil(i);
      break;
    }
  }
  iFinalColor = vec4(color, 1);
}
