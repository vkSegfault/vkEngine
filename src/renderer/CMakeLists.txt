cmake_minimum_required(VERSION 3.28)

project(Renderer)

set( EXTERNAL_PATH "../../external" )
set( VULKAN_VER "1.3.296.0" )

add_library( ${PROJECT_NAME} STATIC )

message( PROJECT_NAME="${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/lib" )

target_include_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/include"
    "${EXTERNAL_PATH}/glfw/include"
    "${EXTERNAL_PATH}/glm"
)
target_link_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/lib"
    "../../external/vulkan/1.3.296.0/lib"
    "${EXTERNAL_PATH}/glfw/lib"
)
target_link_libraries( ${PROJECT_NAME} PUBLIC "libvulkan.so.1" "libglfw3.a" )

target_sources( ${PROJECT_NAME} PUBLIC "Renderer.cpp" "Renderer.hpp" )