#version 330 core

layout(location = 0) in vec2 aPos;

out vec2 iFragPerc;

void main()
{
  gl_Position = vec4(aPos, 0.0, 1.0);
  iFragPerc.x = (aPos.x + 1.0) / 2.0;
  iFragPerc.y = (aPos.y + 1.0) / 2.0;
}
