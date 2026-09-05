set(GAME_SOURCES

# Precompiled header
    PCH/Game.cpp

# Core
    Core/Core/Character/Character.cpp
    Core/Core/Player/Player.cpp
    Core/Core/Enemy/Enemy.cpp

# GamePlay
    Core/GamePlay/Movement/Movement.cpp

# Godot
    EngineAdapter/Godot/Node/Player/PlayerNode.cpp
    EngineAdapter/Godot/Godot/RegisterTypes.cpp

)

add_library(Game SHARED
    ${GAME_SOURCES}
)

target_include_directories(Game
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/PCH"
        "${CMAKE_CURRENT_SOURCE_DIR}/Core/Core"
        "${CMAKE_CURRENT_SOURCE_DIR}/Core/GamePlay"
        "${CMAKE_CURRENT_SOURCE_DIR}/EngineAdapter/Godot"

)

target_link_libraries(Game
    PRIVATE
        godot-cpp
)

target_precompile_headers(Game
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/PCH/Game.h"
)

set_target_properties(Game PROPERTIES
    OUTPUT_NAME "game"

    LIBRARY_OUTPUT_DIRECTORY
        "${GAME_EXTENSION_DIR}"
)
