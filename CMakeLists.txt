cmake_minimum_required(VERSION 3.5.0)
project(2DSimulation)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/share/SFML/cmake/Modules") 
set(CMAKE_CXX_STANDARD 11)

find_package(Armadillo)
include_directories(${ARMADILLO_INCLUDE_DIRS})

find_package(SFML COMPONENTS network audio graphics window system)
find_package(Eigen3 3 REQUIRED)

add_executable(2DSimulation main.cpp)

include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(2DSimulation ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Eigen3::Eigen )


