//
// Created by Janus on 26/10/2025.
//
#include "Tablero.h"
#include "Movimiento.h"
#include <string>
#include <iostream>
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
    PosicionX++;
}
void Movimiento::MoverseIzquierda() {
    PosicionX--;
}
std::string Movimiento::Detectar() {
    int (&matriz)[10][10] = Tablero::GetMatrizStatic();

    bool der = DetectarVacioDerecha(matriz);
    bool izq = DetectarVacioIzquierda(matriz);
    bool arr = DetectarVacioArriba(matriz);
    bool abj = DetectarVacioAbajo(matriz);


    std::string resultado = "Vacios detectados en: ";
    std::cout << "En detectar matriz[6][2] = " << matriz[6][2] << std::endl;
    std::cout << "En detectar matriz[7][3] = " << matriz[7][3] << std::endl;
    std::cout << "DEBUG: PosX=" << PosicionX << " PosY=" << PosicionY << std::endl;
    std::cout << "DEBUG: matriz[" << PosicionX << "][" << PosicionY << "]=" << matriz[PosicionX][PosicionY] << std::endl;
    std::cout << "DEBUG: matriz[" << PosicionX+1 << "][" << PosicionY << "] (derecha)=" << matriz[PosicionX+1][PosicionY] << std::endl;
    std::cout << "DEBUG: matriz[" << PosicionX-1 << "][" << PosicionY << "] (izquierda)=" << matriz[PosicionX-1][PosicionY] << std::endl;
    std::cout << "DEBUG: matriz[" << PosicionX << "][" << PosicionY-1 << "] (arriba)=" << matriz[PosicionX][PosicionY-1] << std::endl;
    std::cout << "DEBUG: matriz[" << PosicionX << "][" << PosicionY+1 << "] (abajo)=" << matriz[PosicionX][PosicionY+1] << std::endl;
    std::cout<<"DEBUG: "<<matriz[PosicionX][PosicionY] <<"(actual)"<< std::endl;
    std::cout<<"DEBUG: "<<matriz[PosicionX][PosicionY+1]<<" (derecha)"<<std::endl;
std::cout<<"DEBUG: "<<matriz[PosicionX][PosicionY-1]<<" (izquierda)"<<std::endl;
std::cout<<"DEBUG: "<<matriz[PosicionX-1][PosicionY]<<" (arriba)"<<std::endl;
std::cout<<"DEBUG: "<<matriz[PosicionX+1][PosicionY]<<" (abajo)"<<std::endl;


    if (der) resultado += "Derecha ";
    if (izq) resultado += "Izquierda ";
    if (arr) resultado += "Arriba ";
    if (abj) resultado += "Abajo ";

    if (!der && !izq && !arr && !abj)
        resultado += "ninguna dirección (todo libre).";

    return resultado;
}

// ====== Funciones de detección individuales ======

bool Movimiento::DetectarVacioDerecha(int (&matriz)[10][10]) {
    if (PosicionY < 9) {  // Derecha = mover en eje X (columna)
        return matriz[PosicionX][PosicionY + 1] == 0;
    }
    return true; // fuera del tablero = obstáculo
}

bool Movimiento::DetectarVacioIzquierda(int (&matriz)[10][10]) {
    if (PosicionY > 0) {
        return matriz[PosicionX][PosicionY - 1] == 0;
    }
    return true;
}

bool Movimiento::DetectarVacioArriba(int (&matriz)[10][10]) {
    if (PosicionX > 0) {  // Arriba = mover en eje Y (fila)
        return matriz[PosicionX - 1][PosicionY] == 0;
    }
    return true;
}

bool Movimiento::DetectarVacioAbajo(int (&matriz)[10][10]) {
    if (PosicionX < 9) {
        return matriz[PosicionX + 1][PosicionY] == 0;
    }
    return true;
}


