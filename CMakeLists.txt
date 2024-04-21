cmake_minimum_required(VERSION 3.17)
project(sbrt_backend CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SBRT_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(SBRT_BINARY_DIR ${PROJECT_BINARY_DIR})
set(SBRT_SDRPP_BASE_DIR "${PROJECT_SOURCE_DIR}/SDRPlusPlus" CACHE FILEPATH "The base directory for SDR++")
set(SDRPP_CORE_ROOT "${SBRT_SDRPP_BASE_DIR}/core/src" CACHE FILEPATH "The path to the SDR++ module CMake file")
set(SDRPP_MODULE_COMPILER_FLAGS -O3)

add_subdirectory(SDRPlusPlus)
add_subdirectory(radioastro_hl)

add_subdirectory(baremetal)
