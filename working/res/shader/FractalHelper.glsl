vec2 FindUv(vec2 fragPerc, vec2 center, float width, float height)
{
  vec2 bottomLeftUv = center;
  bottomLeftUv.x = center.x - width / 2.0;
  bottomLeftUv.y = center.y - height / 2.0;
  vec2 uv;
  uv.x = bottomLeftUv.x + width * fragPerc.x;
  uv.y = bottomLeftUv.y + height * fragPerc.y;
  return uv;
}

vec3 ColorEvergreen(int iteration, int maxIterations)
{
  float splitIter = float(maxIterations) / 3.0;
  vec3 color;
  color.g = clamp(float(iteration) / splitIter, 0.0, 1.0);
  color.b = clamp((float(iteration) - splitIter) / splitIter, 0.0, 1.0);
  color.r = clamp((float(iteration) - splitIter * 2.0) / splitIter, 0.0, 1.0);
  return color;
}

vec3 ColorOil(int iteration)
{
  float pi = 3.1415926535;
  float hue = float(iteration) / 2.0;
  vec3 color;
  color.r = (cos(hue) + 1.0) / 2.0;
  color.g = (cos(hue + 2.0 * pi / 3.0) + 1.0) / 2.0;
  color.b = (cos(hue + 4.0 * pi / 3.0) + 1.0) / 2.0;
  return color;
}
