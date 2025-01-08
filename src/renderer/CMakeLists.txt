cmake_minimum_required(VERSION 3.28)

project(Renderer)

set( EXTERNAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../external" )
set( VULKAN_VER "1.3.296.0" )

# setting below ENV VARs only works at build time, not runtime
set( ENV{VULKAN_SDK} "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}")
set( ENV{VK_ADD_LAYER_PATH} "$ENV{VULKAN_SDK}/share/vulkan/explicit_layer.d")
# run below script to make use of Validation Layers provided by Kronos
# export VULKAN_SDK=/home/<path_to_engine>/vkEngine/external/vulkan/1.3.296.0
# export VK_LAYER_PATH=$VULKAN_SDK/share/vulkan/explicit_layer.d

add_library( ${PROJECT_NAME} STATIC )

message( PROJECT_NAME="$ENV{VK_LAYER_PATH}" )

target_include_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/include"
    "${EXTERNAL_PATH}/glfw/include"
    "${EXTERNAL_PATH}/glm"
)
target_link_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/lib"
    "${EXTERNAL_PATH}/glfw/lib"
)

# while we already habe link directory for vulkan it will use libvulkan.so installed by system first - so we force using our version providing direct path instead
target_link_libraries( ${PROJECT_NAME} PUBLIC "libvulkan.so" "libglfw3.a" )

target_sources( ${PROJECT_NAME} PUBLIC "Renderer.cpp" "Renderer.hpp" )