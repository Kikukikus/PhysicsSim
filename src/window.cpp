#include "window.hpp"

GLFWwindow* create_window(int width, int height){
  glfwInit();
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  GLFWwindow* window = glfwCreateWindow(width, height, "Physics Engine", NULL, NULL);

  return window;
}

GLuint create_shader(){
  const char* vertexShaderSource = "#version 330 core \n"
  "layout (location = 0) in vec3 aPos; \n"
  "void main()\n"
  "{\n"
  "   gl_Position = vec4(aPos.x, aPos.y,aPos.z, 1.0);\n"
  "}\0";


  const char* fragmentShaderSource = "#version 330 core \n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "   FragColor = vec4(0.8f, 0.3f, 0.02f,1.0f);\n"
  "}\n\0";
  
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource,NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource,NULL);
  glCompileShader(fragmentShader);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  
  return shaderProgram;
}
