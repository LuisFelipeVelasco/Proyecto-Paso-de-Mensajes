//
// Created by luisf on 25/10/2025.
//

#include "Movimiento.h"

/*
===============================================================================
                        IMPLEMENTACIÓN DE LA CLASE MOVIMIENTO
===============================================================================
La clase Movimiento repsresenta las acciones que puede realizar el avatar ,
modificando sus coordenadas para simular su desplazamiento

Se demuestra:
 - Paso de objetos por referencia.
 -Asociar una posicion existente del tablero (por referencia)
 - Cambiar la posicion actual moviendose en distintas dirreciones
===============================================================================
*/

Movimiento::Movimiento(  int& x,  int& y) : PosicionX(x), PosicionY(y) {} // Aqui nos salia un error si usabamos this en vez de definirlo asi Atributo(Parametro) y no hay necesidad de poner &en estos atributos pero si en los de .h

void Movimiento::MoverseArriba() {
    PosicionY++;
};
void Movimiento::MoverseAbajo() {
    PosicionY--;
}
void Movimiento::MoverseDerecha() {
    PosicionX;
}
void Movimiento::MoverseIzquierda() {
    PosicionX--;
}