#ifndef NUMERICAL_HPP
#define NUMERICAL_HPP

#include <glm/glm.hpp>

class Particle;

enum class Method {
  Euler,
  Verlet,
  RungeKutta4
};

class Solver {

  public:
  static void euler(Particle& p, float deltaTime);

  static void verlet(Particle& p, float deltaTime);

  static glm::vec2 rk4_k1(const Particle& p, float deltaTime);
  static glm::vec2 rk4_k2(const Particle& p, const glm::vec2& k1, float deltaTime);
  static glm::vec2 rk4_k3(const Particle& p, const glm::vec2& k2, float deltaTime);
  static glm::vec2 rk4_k4(const Particle& p, const glm::vec2& k3, float deltaTime);

  static void update(Particle& p, float deltaTime, Method method);
};

#endif 
