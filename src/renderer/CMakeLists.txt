cmake_minimum_required(VERSION 3.28)

project(Renderer)

set( EXTERNAL_PATH "../../external" )
set( VULKAN_VER "1.3.296.0" )

add_library( ${PROJECT_NAME} STATIC )
target_sources( ${PROJECT_NAME} PUBLIC "Renderer.cpp" "Renderer.hpp" )
target_include_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/include"
    "${EXTERNAL_PATH/glfw/include}"
    )
target_link_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/lib"
    "${EXTERNAL_PATH}/glfw/lib"
    )
target_link_libraries( ${PROJECT_NAME} PUBLIC "vulkan" "libglfw3.a" )