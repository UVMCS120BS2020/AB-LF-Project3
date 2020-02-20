cmake_minimum_required(VERSION 3.8)
project(AB-LF-Project3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(AB-LF-Project3 main.cpp Lens.h Lens.cpp Rectilinear_Lens.h Rectilinear_Lens.cpp Camera.h Camera.cpp Photograph.h Photograph.cpp)
add_executable(Testing testing.cpp Lens.h Lens.cpp Rectilinear_Lens.h Rectilinear_Lens.cpp Camera.h Camera.cpp Photograph.h Photograph.cpp)