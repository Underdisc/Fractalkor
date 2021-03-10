float ComplexAbs(vec2 val)
{
  return sqrt(val.x * val.x + val.y * val.y);
}

vec2 ComplexMul(vec2 a, vec2 b)
{
  vec2 result;
  result.x = a.x * b.x - a.y * b.y;
  result.y = a.x * b.y + a.y * b.x;
  return result;
}

vec2 ComplexAdd(vec2 a, vec2 b)
{
  vec2 result;
  result.x = a.x + b.x;
  result.y = a.y + b.y;
  return result;
}

vec2 ComplexSub(vec2 a, vec2 b)
{
  vec2 result;
  result.x = a.x - b.x;
  result.y = a.y - b.y;
  return result;
}
