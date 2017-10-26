# Install script for directory: /home/mprzystupa/git/cs526Project/eigen/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SPQRSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Eigen"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SparseCholesky"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Geometry"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Householder"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Eigenvalues"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/StdVector"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/PardisoSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/CholmodSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/UmfPackSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/LU"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SparseCore"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Core"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/OrderingMethods"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SVD"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SparseQR"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/PaStiXSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/StdList"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/StdDeque"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Jacobi"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/IterativeLinearSolvers"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SuperLUSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Cholesky"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/QR"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/QtAlignedMalloc"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Sparse"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/MetisSupport"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/SparseLU"
    "/home/mprzystupa/git/cs526Project/eigen/Eigen/Dense"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/mprzystupa/git/cs526Project/eigen/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

