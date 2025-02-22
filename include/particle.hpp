#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <glm/glm.hpp>

class Particle {
  public:

    // Constructor
    Particle(glm::vec2 position, glm::vec2 velocity, glm::vec2 acceleration, float radius, glm::vec3 color);

    //Setters for funny :)
    void setPosition(const glm::vec2& position);
    void setVelocity(const glm::vec2& velocity);
    void setAcceleration(const glm::vec2& acceleration);
    void setRadius(float radius);
    void setColor(const glm::vec3& color);

    //Getters for numerical methods and data :)
    glm::vec2 getPosition() const;
    glm::vec2 getVelocity() const;
    glm::vec2 getAcceleration() const;
    float getRadius() const;
    glm::vec3 getColor() const;

    void render();

  private:
    glm::vec2 m_position;
    glm::vec2 m_velocity;
    glm::vec2 m_acceleration;
    float m_radius;
    glm::vec3 m_color;

};

#endif
