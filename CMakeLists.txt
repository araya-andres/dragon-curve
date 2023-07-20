cmake_minimum_required(VERSION 3.21)
project(dragon CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML REQUIRED)

add_compile_options(
  -g
  -pedantic
  -Wall)

add_executable(app
    main.cc
    turtle.cc
)
target_link_libraries(app sfml-graphics)
