cmake_minimum_required(VERSION 3.28)
project(Calculator LANGUAGES CXX)

set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SFML)

add_executable(calculator WIN32 calculator.cpp)
target_link_libraries(calculator PRIVATE SFML::Graphics SFML::Main dwmapi)

add_custom_command(TARGET calculator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:calculator>/assets"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/assets/tuffy.ttf"
        "$<TARGET_FILE_DIR:calculator>/assets/tuffy.ttf"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/assets/calculator-logo.png"
        "$<TARGET_FILE_DIR:calculator>/assets/calculator-logo.png"
)