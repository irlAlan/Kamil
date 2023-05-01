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

# for documentation
# find_package(Doxygen REQUIRED)
# if(DOXYGEN_FOUND)
#     configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
#     add_custom_target(doc
#     COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Generating Doxygen documentation"
#     VERBATIM)
# endif()


find_package(fmt)


#for formatting
add_custom_target(format
    COMMAND clang-format
    --style=file
    -i
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Kamil/*.h
    )

# opengl is required by sfml so we need to find it too
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        ./src/kamil.cpp
        ./src/TextBox.cpp
        ./src/Editor.cpp
        ./src/Utils/Stack.cpp
        ./src/Keyboard.cpp
        ./src/MyRect.cpp
    )

# Allows us to use <> when including files
target_include_directories(${PROJECT_NAME}
    PUBLIC "include/" 
    PUBLIC "resource/"
    PRIVATE "${PROJECT_BINARY_DIR}"
    )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} fmt::fmt sfml-window sfml-graphics)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
