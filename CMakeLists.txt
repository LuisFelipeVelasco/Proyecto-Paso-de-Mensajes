cmake_minimum_required(VERSION 4.0)
project(PROYECTO_AGENTE_INTELIGENTE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PROYECTO_AGENTE_INTELIGENTE
        Avatar.cpp
        Avatar.h
        main.cpp
        Tablero.cpp
        Tablero.h
        Movimiento.cpp
        Movimiento.h)
