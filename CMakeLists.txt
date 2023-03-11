cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(Kamil)

# set basic things
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# check if build type is set default is debug mode
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG 
        CACHE STRING "Choose the build type (Debug or Release)" FORCE)
endif()

# find the sfml 2.5 package that we locally installed
find_package(SFML 2.5
        COMPONENTS
            system window graphics network audio
        REQUIRED)
# opengl is required by sfml so we need to find it too
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        ./src/kamil.cpp
        ./src/TextBox.cpp
        ./src/EditorWindow.cpp
    )

# Allows us to use <> when including files
target_include_directories(${PROJECT_NAME}
    PUBLIC "include/" 
    PUBLIC "resource/"
    PRIVATE "${PROJECT_BINARY_DIR}"
    )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} sfml-window sfml-graphics)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
