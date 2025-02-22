#include <iostream>
#include "numerical.hpp"
#include "particle.hpp"

void Solver::euler(Particle& p, float deltaTime) {
    p.setVelocity(p.getVelocity() + p.getAcceleration() * deltaTime);
    p.setPosition(p.getPosition() + p.getVelocity() * deltaTime);
}

void Solver::verlet(Particle& p, float deltaTime) {
    glm::vec2 tempPosition = p.getPosition();
    glm::vec2 newPosition = 2.0f * p.getPosition() - tempPosition + p.getAcceleration() * deltaTime * deltaTime;
    p.setPosition(newPosition); 
    glm::vec2 newVelocity = (p.getPosition() - tempPosition) / deltaTime;
    p.setVelocity(newVelocity);
}

glm::vec2 Solver::rk4_k1(const Particle& p, float deltaTime) {
    return p.getVelocity();
}

glm::vec2 Solver::rk4_k2(const Particle& p, const glm::vec2& k1, float deltaTime) {
    return p.getVelocity() + 0.5f * deltaTime * k1;
}

glm::vec2 Solver::rk4_k3(const Particle& p, const glm::vec2& k2, float deltaTime) {
    return p.getVelocity() + 0.5f * deltaTime * k2;
}

glm::vec2 Solver::rk4_k4(const Particle& p, const glm::vec2& k3, float deltaTime) {
    return p.getVelocity() + deltaTime * k3;
}

void Solver::update(Particle& p, float deltaTime, Method method) {
    switch (method) {
        case Method::Euler:
            euler(p, deltaTime); 
            break;
        case Method::Verlet:
            verlet(p, deltaTime);
            break;
        case Method::RungeKutta4:
            glm::vec2 k1 = rk4_k1(p, deltaTime);
            glm::vec2 k2 = rk4_k2(p, k1, deltaTime);
            glm::vec2 k3 = rk4_k3(p, k2, deltaTime);
            glm::vec2 k4 = rk4_k4(p, k3, deltaTime);

            p.setPosition(p.getPosition() + (k1 + 2.0f * k2 + 2.0f * k3 + k4) * deltaTime / 6.0f);
            p.setVelocity(p.getVelocity() + p.getAcceleration() * deltaTime);
            break;
    }
}

