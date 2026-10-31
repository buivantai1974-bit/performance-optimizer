#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/CCParticleSystemQuad.hpp>

using namespace geode::prelude;

namespace perfopt {
    bool cullingEnabled();
    float cullMargin();
    bool particlesEnabled();
    int particleLimit();
    bool hideBg();
    bool disableGlow();
}