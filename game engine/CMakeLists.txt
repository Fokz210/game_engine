cmake_minimum_required(VERSION 3.17)

project(gameengine CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "drawable_game_object.h"
    "game_object.h"
    "level.h"
    "level_loader.h"
    "light_source.h"
    "opaque_object.h"
    "render_manager.h"
    "sprite_game_object.h"
    "test_sprite.h"
    "test_wall.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "drawable_game_object.cpp"
    "game_object.cpp"
    "level.cpp"
    "level_loader.cpp"
    "light.frag"
    "light_source.cpp"
    "main.cpp"
    "opaque_object.cpp"
    "render_manager.cpp"
    "sprite_game_object.cpp"
    "test_sprite.cpp"
    "test_wall.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

add_executable(game_engine ${ALL_FILES})
target_link_libraries(game_engine sfml-graphics sfml-system sfml-window)
