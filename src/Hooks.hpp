#pragma once
#include "PerformanceOptimizer.hpp"

class $modify(PerfPlayLayer, PlayLayer) {
    void update(float dt);
    void postUpdate(float dt);
};

class $modify(PerfGameObject, GameObject) {
    void update(float dt);
};

class $modify(PerfParticle, CCParticleSystemQuad) {
    bool initWithTotalParticles(unsigned int numberOfParticles);
};