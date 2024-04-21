cmake_minimum_required(VERSION 3.17)
project(radioastro_hl CXX)
set(CXX_STANDARD 20)

# Unfortunately clang-tidy doesn't like this project much. Force clang-tidy to only run on
# source files in this directory.
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" PATHS /home/linuxbrew/.linuxbrew/bin/ /usr/bin/)
set(CLANG_TIDY_COMMAND ${CLANG_TIDY_EXE} -p ${SBRT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp)

set(SRC
    src/main.cpp
)

include(${SBRT_SDRPP_BASE_DIR}/sdrpp_module.cmake)

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall" 
    "-Werror"
    # Requires serious refactoring we can do anything about
    "-Wno-overloaded-virtual"
    "-Wno-error=deprecated-declarations"
)

add_custom_target(${PROJECT_NAME}_clang-tidy COMMAND ${CLANG_TIDY_COMMAND})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_clang-tidy)
