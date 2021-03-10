#include <iostream>

#include <Error.h>
#include <Viewport.h>
#include <gfx/Shader.h>
#include <glad/glad.h>
#include <Input.h>
#include <math/Vector.h>
#include <world/World.h>
#include <VarkorMain.h>
#include <imgui/imgui.h>

float gHeight = 2.0f;
Vec2 gCenter = {0.0f, 0.0f};
int gIterations = 10;
Vec2 gC = {0.0f, 0.0f};
Gfx::Shader gMandelbrotShader;
Gfx::Shader gJuliaShader;
unsigned int gVao;

const int gMandelbrotIndex = 0;
const int gJuliaIndex = 1;
int gSelectedShader;

void PostRender()
{
  // Display the imgui window for modifying the fractal image.
  ImGui::Begin("Fractal Controls");
  ImGui::Combo("Selected Fractal", &gSelectedShader, "Mandelbrot\0Julia\0\0");
  ImGui::DragInt("Iterations", &gIterations, 1, 1, 2000);
  if (gSelectedShader == gJuliaIndex)
  {
    ImGui::DragFloat2("C", gC.Data(), 0.0001f, 0.0f, 0.0f, "%.4f");
  }
  ImGui::End();

  // Move the center using the mouse input and zoom in and out using the scroll
  // wheel.
  if (Input::MouseDown(Input::Mouse::Left))
  {
    gCenter[0] -= Input::MouseMotion()[0] * gHeight * 0.001f;
    gCenter[1] += Input::MouseMotion()[1] * gHeight * 0.001f;
  }
  float scroll = Input::MouseScroll()[1];
  gHeight = gHeight - scroll * gHeight * 0.1f;

  // Choose the active shader depending on the selection and update the shader
  // uniforms.
  Gfx::Shader* activeShader;
  if (gSelectedShader == gJuliaIndex)
  {
    gJuliaShader.SetVec2("uC", gC.CData());
    activeShader = &gJuliaShader;
  }
  else
  {
    activeShader = &gMandelbrotShader;
  }
  float width = gHeight * Viewport::Aspect();
  activeShader->Use();
  activeShader->SetVec2("uCenter", gCenter.CData());
  activeShader->SetFloat("uWidth", width);
  activeShader->SetFloat("uHeight", gHeight);
  activeShader->SetInt("uIterations", gIterations);

  // Draw the fullscreen quad using the fractal shader.
  glBindVertexArray(gVao);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

int main(void)
{
  VarkorInit();
  World::PostRender = PostRender;

  // Initialize the shaders.
  Gfx::Shader::InitResult initResult = gMandelbrotShader.Init(
      "res/shader/Fractal.vs", "res/shader/Mandelbrot.fs");
  LogAbortIf(!initResult.mSuccess, initResult.mError.c_str());
  initResult =
      gJuliaShader.Init("res/shader/Fractal.vs", "res/shader/Julia.fs");
  LogAbortIf(!initResult.mSuccess, initResult.mError.c_str());
  gSelectedShader = 0;

  // Upload the full screen quad vertex data.
  // clang-format off
  float verts[12] = {-1.0f,  1.0f,
                     -1.0f, -1.0f,
                      1.0f,  1.0f,
                      1.0f, -1.0f,
                      1.0f,  1.0f,
                     -1.0f, -1.0f};
  // clang-format on
  glGenVertexArrays(1, &gVao);
  glBindVertexArray(gVao);
  unsigned int vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  unsigned int vboSize = sizeof(float) * 12;
  glBufferData(GL_ARRAY_BUFFER, vboSize, verts, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
  glBindVertexArray(0);

  VarkorMain();
}
