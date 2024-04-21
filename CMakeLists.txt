cmake_minimum_required(VERSION 3.17)
project(sbrt_backend CXX)

set(SBRT_SDRPP_BASE_DIR "${PROJECT_SOURCE_DIR}/SDRPlusPlus" CACHE FILEPATH "The base directory for SDR++")
set(SDRPP_CORE_ROOT "${SBRT_SDRPP_BASE_DIR}/core/src" CACHE FILEPATH "The path to the SDR++ module CMake file")

add_subdirectory(SDRPlusPlus)
add_subdirectory(radioastro_hl)

add_subdirectory(baremetal)
