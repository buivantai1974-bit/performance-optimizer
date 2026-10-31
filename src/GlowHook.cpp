#include "PerformanceOptimizer.hpp"
#include <Geode/modify/CCGLProgram.hpp>

class $modify(PerfGLProgram, cocos2d::CCGLProgram) {
    bool initWithVertexShaderByteArray(const GLchar* v, const GLchar* f) {
        if (perfopt::disableGlow() && f) {
            std::string fs(f);
            if (fs.find("glow") != std::string::npos || fs.find("blur") != std::string::npos)
                return cocos2d::CCGLProgram::initWithVertexShaderByteArray(v, nullptr);
        }
        return cocos2d::CCGLProgram::initWithVertexShaderByteArray(v, f);
    }
};