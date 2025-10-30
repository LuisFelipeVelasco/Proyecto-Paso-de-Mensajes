cmake_minimum_required(VERSION 4.0)
project(Proyecto_soldado_Clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto_soldado_Clion
        Avatar.cpp
        Avatar.h
        main.cpp
        Movimiento.cpp
        Movimiento.h
        Tablero.cpp
        Tablero.h
        Visual.cpp
        Visual.h)
