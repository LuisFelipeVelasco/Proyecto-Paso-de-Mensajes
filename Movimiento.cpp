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

std::string Movimiento::Moverse() {
    while (PosicionY !=9 or PosicionX!=9) {

        int (&matriz)[10][10] = Tablero::GetMatrizStatic();
        bool der = DetectarVacioDerecha(matriz);
        bool izq = DetectarVacioIzquierda(matriz);
        bool arr = DetectarVacioArriba(matriz);
        bool abj = DetectarVacioAbajo(matriz);

        if (der==true and izq==true and arr==true) { // si esta bloqueado a la derecha, izquierda y arriba : Volver esa casilla igual a 0 y moverse abajo
            matriz[PosicionX][PosicionY]=0;
            PosicionX++;
            std::cout<<"1";


        }
        else if (der==true and izq==true and abj==true) { //si esta bloqueado a la derecha, izquierda y abajo se mueve a arriba
            matriz[PosicionX][PosicionY]=0;
            PosicionX--;
            std::cout<<"2";
        }
        else if (der==true and abj==true and arr==true) {//si esta bloqueado a la derecha, abajo y arriba, debe moverse a la izquierda
            matriz[PosicionX][PosicionY]=0;
            PosicionY--;

            std::cout<<"3";
        }
        else if (izq==true and abj==true and arr==true) { //si esta bloqueado a la izquierda, abajo y arriba, debe moverse a la derecha
            matriz[PosicionX][PosicionY]=0;
            PosicionY++;
            std::cout<<matriz[PosicionX][PosicionY]<<std::endl;

            std::cout<<"4";
        }

        else if(izq==true and der==true){ // si esta bloqueado por derecha e izquierda
            int opcion= rand() % 2;
            std::cout<<"5";
            if (opcion==1) PosicionX--;
            else PosicionX++;
        }



        else if(der==true and arr==true) { //si esta bloqueado por derecha  y por arriba
            int opcion= rand() % 2;
            std::cout<<"6";
            if (opcion==1) PosicionY--;
            else PosicionX ++;}

        else if(der==true and abj==true) { //si esta bloqueado por derecha  y por abajo
            int opcion= rand() % 2;
            std::cout<<"7";
            if (opcion==1) PosicionY--;
            else PosicionX --;}

        else if(izq==true and arr==true) { //si esta bloqueado por izquierda  y por arriba
            int opcion= rand() % 2;
            std::cout<<"8";
            if (opcion==1) PosicionY++;
            else PosicionX ++;}

        else if(izq==true and abj==true) { //si esta bloqueado por izquierda  y por abajo
            int opcion= rand() % 2;
            std::cout<<"9";
            if (opcion==1) PosicionY++;
            else PosicionX --;}

        else if(arr==true and abj==true) { //si esta bloqueado por arriba  y por abajo
            int opcion= rand() % 2;
            std::cout<<"10";
            if (opcion==1) PosicionY++;
            else PosicionY --;}






       else  if(arr==true ){//si esta bloqueado por arriba debe tomar la decision de bajar, izquierda o derecha
            int opcion= rand() % 3;
            std::cout<<"11";
            if (opcion==1) PosicionX++;
            else if (opcion==2) PosicionY++;
            else PosicionY--;}

        else if(abj==true) {
            // Si esta bloqueado por abajo solo tiene 3 opciones
            int opcion= rand() % 3;
            std::cout<<"12";
            if (opcion==1) PosicionX--;
            else if (opcion==2) PosicionY--;
            else PosicionY ++;}

        else if(der==true){ //si esta bloqueado por derecha debe tomar la decision de
            int opcion= rand() % 3;
            std::cout<<"13";
            if (opcion==1) PosicionX++;
            else if (opcion==2) PosicionX--;
            else PosicionY--;}

        else if(izq==true){
            int opcion= rand() % 3;
            std::cout<<"14";
            if (opcion==1) PosicionX--;
            else if (opcion==2) PosicionX++;
            else PosicionY ++;}





















        std::cout<<"Paso a la linea:"<<std::endl;
        std::cout<<"["<<PosicionX<<"]["<<PosicionY<<"]"<<std::endl; //imprimir la posicion que se movio luego de marcar la anterior como cero
        //std::cout<<matriz[PosicionX][PosicionY-1]<<std::endl; // Para ver si cambio el valor de la celda a cero

    };

    std::cout<< "CHICOS LO HE CONSEGUIDO"<<std::endl;
};


void Movimiento::MoverseArriba() {
    PosicionX--;
};
void Movimiento::MoverseAbajo() {
    PosicionX++;
};
void Movimiento::MoverseDerecha() {
    PosicionY++;
};
void Movimiento::MoverseIzquierda() {
    PosicionY--;
};

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


