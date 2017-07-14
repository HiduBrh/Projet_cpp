cmake_minimum_required(VERSION 3.6)
project(Projet_cpp)

set(CMAKE_CXX_STANDARD 11)
#include_directories("/home/idu/Documents/ESGI/cpp/SFML-2.4.2/include")
set(SOURCE_FILES game.cpp)
add_executable(game ${SOURCE_FILES})
#set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/pong)

# all source files
target_link_libraries(game sfml-audio sfml-graphics sfml-window sfml-system)
set(SRC ${SRCROOT}/game.cpp)

