cmake_minimum_required(VERSION 3.17)
project(radioastro_hl CXX)
set(CXX_STANDARD 20)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" PATHS /home/linuxbrew/.linuxbrew/bin/ /usr/bin/)
set(CLANG_TIDY_COMMAND ${CLANG_TIDY_EXE} -p ${SBRT_BINARY_DIR})

set(SRC
    src/main.cpp
)

include(${SBRT_SDRPP_BASE_DIR}/sdrpp_module.cmake)

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall" 
    "-Werror"
    # We can't do much about the following errors
    "-Wno-sign-compare"
    "-Wno-error=overloaded-virtual"
    "-Wno-error=unused-variable"
    "-Wno-error=deprecated-declarations"
)
if (CLANG_TIDY_EXE)
    # TODO: unfortunately clang-tidy doesn't like this project much
    # set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
endif()
