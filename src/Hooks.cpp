#include "Hooks.hpp"

static CCRect g_cullRect = CCRectZero;

void PerfPlayLayer::update(float dt) {
    PlayLayer::update(dt);
    if (!perfopt::cullingEnabled()) return;
    auto win = CCDirector::sharedDirector()->getWinSize();
    float m = perfopt::cullMargin();
    g_cullRect = CCRect(-m, -m, win.width + m * 2.f, win.height + m * 2.f);
}

void PerfPlayLayer::postUpdate(float dt) {
    PlayLayer::postUpdate(dt);
    if (perfopt::hideBg() && m_background) {
        m_background->setVisible(false);
    }
}

void PerfGameObject::update(float dt) {
    GameObject::update(dt);
    if (!perfopt::cullingEnabled()) return;
    if (!g_cullRect.size.width) return;
    auto bb = this->boundingBox();
    auto origin = this->getParent()
        ? this->getParent()->convertToWorldSpace(bb.origin)
        : bb.origin;
    CCRect world(origin, bb.size);
    this->setVisible(g_cullRect.intersectsRect(world));
}

bool PerfParticle::initWithTotalParticles(unsigned int numberOfParticles) {
    if (perfopt::particlesEnabled()) {
        int cap = perfopt::particleLimit();
        if (cap > 0 && numberOfParticles > (unsigned)cap)
            numberOfParticles = cap;
    }
    if (!CCParticleSystemQuad::initWithTotalParticles(numberOfParticles))
        return false;
    if (perfopt::disableGlow()) {
        this->setBlendFunc({ GL_ONE, GL_ZERO });
    }
    return true;
}