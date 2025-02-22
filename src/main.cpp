#include "numerical.hpp"
#include "particle.hpp"
#include "window.hpp"

int main(){
  int width = 800;
  int height = 800;

  GLFWwindow* window = create_window(width,height);

  glfwMakeContextCurrent(window);

  gladLoadGL();
  glViewport(0,0,width,height);
  GLuint shaderProgram = create_shader();

  Particle p(glm::vec2(0.0f,0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(0.0f, -2.0f), 0.2f ,glm::vec3(1.0f,0.0f,0.0f));
  float dt = 0.0016f;

  while (!glfwWindowShouldClose(window)) {
    
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    p.render();
    glfwSwapBuffers(window);

    glfwPollEvents();

    Solver::update(p,dt, Method::RungeKutta4);
  }

  glDeleteShader(shaderProgram);

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
