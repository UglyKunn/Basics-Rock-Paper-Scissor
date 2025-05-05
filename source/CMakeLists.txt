cmake_minimum_required(VERSION 3.30.2)

project(RPSgame VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file(RPSgameConfig.h.in RPSgameConfig.h)

add_executable(RPSgame main.cpp gameLogic.cpp)

target_include_directories(RPSgame PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/Headers"
  )
