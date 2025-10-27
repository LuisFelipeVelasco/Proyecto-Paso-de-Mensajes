cmake_minimum_required(VERSION 4.0)
project(Paso_Mensajes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Paso_Mensajes main.cpp
        Movimiento.cpp
        Movimiento.h
        Tablero.cpp
        Tablero.h
        Avatar.cpp
        Avatar.h)
