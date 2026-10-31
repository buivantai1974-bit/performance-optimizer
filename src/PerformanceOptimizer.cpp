#include "PerformanceOptimizer.hpp"

namespace perfopt {
    bool cullingEnabled()   { return Mod::get()->getSettingValue<bool>("enable-culling"); }
    float cullMargin()      { return Mod::get()->getSettingValue<float>("cull-margin"); }
    bool particlesEnabled() { return Mod::get()->getSettingValue<bool>("enable-particles"); }
    int particleLimit()     { return Mod::get()->getSettingValue<int>("particle-limit"); }
    bool hideBg()           { return Mod::get()->getSettingValue<bool>("hide-background"); }
    bool disableGlow()      { return Mod::get()->getSettingValue<bool>("disable-glow"); }
}