//
// Created by luisf on 25/10/2025.
//

#include "Avatar.h"
#include <iostream>
/*
===============================================================================
                        IMPLEMENTACIÓN DE LA CLASE AVATAR
===============================================================================
La calse Avatar representa un personaje dentro del tablero del juego. Cada avatar
posee un nombre y una posicion (PosicionX y PosicionY) que indica su ubicacion
actual dentro de la matriz
Se demuestra:
 - Uso de constructores con argumentos de referencia
 - Encapsulamiento y acceso controlado a los atributos mediante metodos getter
 - impresion de informacion en consola
===============================================================================
*/

Avatar::Avatar(std::string Nombre , int& PosicionX, int& PosicionY) {
    this -> Nombre = Nombre;
    this -> PosicionX = PosicionX;
    this -> PosicionY = PosicionY;
}
std::string Avatar::GetNombre()  {
    return Nombre;
}
int& Avatar::GetPosicionX()  {
    return PosicionX;
}

int& Avatar::GetPosicionY()  {
    return PosicionY;
}

void Avatar::Posicion() {
    std::cout<<Nombre<<"esta en la posicion"<<std::endl;
    std::cout<<"["<<PosicionX<<"]["<<PosicionY<<"]"<<std::endl;
}
