cmake_minimum_required(VERSION 3.21)
project(PerformanceOptimizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED GEODE_SDK)
    message(FATAL_ERROR "GEODE_SDK not set")
endif()

include(${GEODE_SDK}/cmake/Geode.cmake)

add_library(${PROJECT_NAME} SHARED
    src/PerformanceOptimizer.cpp
    src/Hooks.cpp
    src/GlowHook.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
setup_geode_mod(${PROJECT_NAME})