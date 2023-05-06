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



# include(ExternalProject)
# 
# set(SFML_VERSION "2.5.1")
# 
# ExternalProject_Add(SFML
#     URL "https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-windows-gcc-7.3.0-mingw-64-bit.zip"
#     URL_MD5 "abcd1234"
#     PREFIX "${CMAKE_CURRENT_BINARY_DIR}/SFML"
#     CMAKE_ARGS
#         -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/SFML-install
#         -DCMAKE_BUILD_TYPE=Release
#         -DSFML_BUILD_EXAMPLES=OFF
#         -DSFML_BUILD_TESTS=OFF
#         -DSFML_BUILD_DOC=OFF
#     )
# 
# # Add SFML include and library directories to the project
# set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/SFML-install/include")
# set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/SFML-install/lib")
# include_directories(${SFML_INCLUDE_DIR})
# link_directories(${SFML_LIBRARY_DIR})



# find the sfml 2.5 package that we locally installed
find_package(SFML 2.5
        COMPONENTS
            system window graphics network audio
        REQUIRED)

    # if(NOT SFML_FOUND)
    #     message("SFML has not been found, building SFML first...")
    #     add_dependencies(${PROJECT_NAME} SFML)
    # endif()



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
find_package(Python REQUIRED Development)

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
        ./src/Document.cpp
    )

# Allows us to use <> when including files
target_include_directories(${PROJECT_NAME}
    PUBLIC "include/" 
    PUBLIC "resource/"
    PRIVATE "${PROJECT_BINARY_DIR}"
    )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} Python::Python fmt::fmt sfml-window sfml-graphics)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
