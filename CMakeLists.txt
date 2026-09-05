cmake_minimum_required(VERSION 3.25)

project(Game
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Game GDExtension runtime destination
set(GAME_EXTENSION_DIR
    "${CMAKE_SOURCE_DIR}/Game/Godot/Extensions"
    CACHE PATH "Game GDExtension output directory"
)

# Godot C++ bindings
set(GODOTCPP_API_VERSION "4.6" CACHE STRING
    "Godot API version targeted by Game"
)

set(GODOTCPP_TARGET "template_debug" CACHE STRING
    "godot-cpp build target"
)

add_subdirectory(
    "${CMAKE_SOURCE_DIR}/External/Dependencies/godot-cpp"
)

add_subdirectory(
    "${CMAKE_SOURCE_DIR}/Source"
)
