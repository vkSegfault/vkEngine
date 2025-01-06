cmake_minimum_required(VERSION 3.28)

project(Renderer)

set( VULKAN_VER "1.3.296.0" )

add_library( ${PROJECT_NAME} STATIC )
target_sources( ${PROJECT_NAME} PUBLIC "Renderer.cpp" "Renderer.hpp" )
target_include_directories( ${PROJECT_NAME} PUBLIC "../../external/vulkan/${VULKAN_VER}/include" )
target_link_directories( ${PROJECT_NAME} PUBLIC "../../external/vulkan/${VULKAN_VER}/lib" )
target_link_libraries( ${PROJECT_NAME} PUBLIC "vulkan" )