# Install script for directory: /home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/AdolcForward"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/AlignedVector3"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/ArpackSupport"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/AutoDiff"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/BVH"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/EulerAngles"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/FFT"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/IterativeSolvers"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/KroneckerProduct"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/LevenbergMarquardt"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/MatrixFunctions"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/MoreVectorization"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/MPRealSupport"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/NonLinearOptimization"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/NumericalDiff"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/OpenGLSupport"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/Polynomials"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/Skyline"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/SparseExtra"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/SpecialFunctions"
    "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/Splines"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "/home/mprzystupa/git/cs526Project/eigen/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mprzystupa/git/cs526Project/eigen/build_dir/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

