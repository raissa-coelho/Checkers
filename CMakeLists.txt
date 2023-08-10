cmake_minimum_required(VERSION 3.22)
project(checkers C)

set(CMAKE_C_STANDARD 11)

# Find the required packages for OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Add the executable target
add_executable(checkers main.c renderer.h renderer.h checkers.h checkers.h gamestate.h gamestate.h player.h player.h input.h checkers.c checkers.c player.c)

# Link the executable with OpenGL/GLUT libraries
target_link_libraries(checkers PRIVATE ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# Include the required directories for OpenGL and GLUT headers
target_include_directories(checkers PRIVATE ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
