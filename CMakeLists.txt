
##
# A Configuration file for Cpp and the different libraries
##

# Setting the minimum version for cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# the name of the exe
project(Kamil)

# using modern cpp cpp17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# check what the build type is. default is debug mode
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG 
        CACHE STRING "Choose the build type (Debug or Release)" FORCE)
endif()




# Tell cmake to use teh FetchContent module
include(FetchContent)

# can change this using ccmake.
# tell cmake to build SFML as a static library so no DLL's
set(BUILD_SHARED_LIBS OFF)
# Download SFML version 2.5.1
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
# make the library available
FetchContent_MakeAvailable(SFML)


# download fmt lib 10.0.0
FetchContent_Declare(
 fmt 
 GIT_REPOSITORY https://github.com/fmtlib/fmt.git
 GIT_TAG 10.0.0 
)
# make the library available
FetchContent_MakeAvailable(fmt)



#  for formatting the code using the LLVM style
add_custom_target(format
    COMMAND clang-format
    --style=LLVM
    -i
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Kamil/*.h
    )

# find OpenGL since its required by sfml so we need to find it too
# opengl is default on modern devices so no need to check and build it
find_package(OpenGL REQUIRED)

# add all cpp files to the project
add_executable(${PROJECT_NAME}
        ./src/kamil.cpp
        ./src/TextBox.cpp
        ./src/Editor.cpp
        ./src/Keyboard.cpp
        ./src/MyRect.cpp
        ./src/Document.cpp
    )

# @brief Allows us to use <> when including files
target_include_directories(${PROJECT_NAME}
    PUBLIC "include/" 
    PRIVATE "${PROJECT_BINARY_DIR}"
    )

#  Linking all libraries to the project
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} fmt::fmt sfml-window sfml-graphics)

# installng the program
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
