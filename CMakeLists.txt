cmake_minimum_required(VERSION 3.6)
project(Projet_cpp)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES game.cpp platforms/Platform.cpp platforms/Platform.h platforms/Platforms.cpp platforms/Platforms.h player/Player.cpp player/Player.h game/Game.cpp game/Game.h)
add_executable(game ${SOURCE_FILES})

# all source files
target_link_libraries(game sfml-audio sfml-graphics sfml-window sfml-system)
set(SRC ${SRCROOT}/game.cpp)

