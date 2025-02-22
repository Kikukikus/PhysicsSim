#include <glad/glad.h>
#include <vector>


#include "particle.hpp"


Particle::Particle(glm::vec2 position, glm::vec2 velocity, glm::vec2 acceleration, float radius, glm::vec3 color)
  : m_position(position), m_velocity(velocity), m_acceleration(acceleration), m_radius(radius), m_color(color) {}

void Particle::setPosition(const glm::vec2& position){
  m_position = position;
}
void Particle::setVelocity(const glm::vec2& velocity){
  m_velocity = velocity;
}
void Particle::setAcceleration(const glm::vec2& acceleration){
  m_acceleration = acceleration;
}
void Particle::setRadius(float radius){
  m_radius = radius;
}
void Particle::setColor(const glm::vec3& color){
  m_color = color;
}

glm::vec2 Particle::getPosition() const {return m_position;}
glm::vec2 Particle::getVelocity() const {return m_velocity;}
glm::vec2 Particle::getAcceleration() const {return m_acceleration;}
float Particle::getRadius() const {return m_radius;}
glm::vec3 Particle::getColor() const {return m_color;}

void Particle::render() {
  float x = m_position.x;
  float y = m_position.y;
  float pi = 3.14159265358979323846;
  float radius = m_radius;
  int segments = 30;

  std::vector<glm::vec2> vertices;
  vertices.push_back(glm::vec2(x,y));

  for(int i = 0; i <= segments; i++){
    float angle = (i/ (float)segments) * 2.0f * pi;
    float vx = x + radius * cos(angle);
    float vy = y + radius * sin(angle);
    vertices.push_back(glm::vec2(vx,vy));
  }

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}
