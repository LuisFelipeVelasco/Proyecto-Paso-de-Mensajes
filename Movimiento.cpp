// language: cpp
// File: `Visual.h` (reemplazar)
#include "Tablero.h"
#include "Movimiento.h"
#include "Visual.h"
#include <string>
#include <iostream>
#include "Visual.h"
/*
===============================================================================
                        IMPLEMENTACIÓN DE LA CLASE MOVIMIENTO
===============================================================================
La clase Movimiento representa las acciones que puede realizar el avatar,
modificando sus coordenadas para simular su desplazamiento

Se demuestra:
 - Paso de objetos por referencia
 - Asociar una posicion existente del tablero (por referencia)
 - Cambiar la posicion actual moviendose en distintas direcciones
 - Integración con la clase Visual para mostrar el progreso
===============================================================================
*/

Movimiento::Movimiento(int& x, int& y) : PosicionX(x), PosicionY(y) {}

std::string Movimiento::Moverse() {
    // Crear objeto Visual pasando punteros a las posiciones
    Visual vista(&PosicionX, &PosicionY);
    
    // Obtener referencia a la matriz del tablero
    int (&matriz)[10][10] = Tablero::GetMatrizStatic();
    
    // Mostrar estado inicial del laberinto
    vista.DibujarTablero(matriz);
    vista.Delay(2000);  // Pausa de 2 segundos al inicio
    
    while (PosicionY != 9 || PosicionX != 9) {
        bool der = DetectarVacioDerecha(matriz);
        bool izq = DetectarVacioIzquierda(matriz);
        bool arr = DetectarVacioArriba(matriz);
        bool abj = DetectarVacioAbajo(matriz);

        if (der==true && izq==true && arr==true) { 
            // Bloqueado a la derecha, izquierda y arriba: moverse abajo
            matriz[PosicionX][PosicionY]=0;
            PosicionX++;
        }
        else if (der==true && izq==true && abj==true) { 
            // Bloqueado a la derecha, izquierda y abajo: moverse arriba
            matriz[PosicionX][PosicionY]=0;
            PosicionX--;
        }
        else if (der==true && abj==true && arr==true) {
            // Bloqueado a la derecha, abajo y arriba: moverse a la izquierda
            matriz[PosicionX][PosicionY]=0;
            PosicionY--;
        }
        else if (izq==true && abj==true && arr==true) { 
            // Bloqueado a la izquierda, abajo y arriba: moverse a la derecha
            matriz[PosicionX][PosicionY]=0;
            PosicionY++;
        }
        else if(izq==true && der==true){ 
            // Bloqueado por derecha e izquierda
            int opcion= rand() % 2;
            if (opcion==1) PosicionX--;
            else PosicionX++;
        }
        else if(der==true && arr==true) { 
            // Bloqueado por derecha y por arriba
            int opcion= rand() % 2;
            if (opcion==1) PosicionY--;
            else PosicionX++;
        }
        else if(der==true && abj==true) { 
            // Bloqueado por derecha y por abajo
            int opcion= rand() % 2;
            if (opcion==1) PosicionY--;
            else PosicionX--;
        }
        else if(izq==true && arr==true) { 
            // Bloqueado por izquierda y por arriba
            int opcion= rand() % 2;
            if (opcion==1) PosicionY++;
            else PosicionX++;
        }
        else if(izq==true && abj==true) { 
            // Bloqueado por izquierda y por abajo
            int opcion= rand() % 2;
            if (opcion==1) PosicionY++;
            else PosicionX--;
        }
        else if(arr==true && abj==true) { 
            // Bloqueado por arriba y por abajo
            int opcion= rand() % 2;
            if (opcion==1) PosicionY++;
            else PosicionY--;
        }
        else if(arr==true){
            // Bloqueado por arriba: decidir entre bajar, izquierda o derecha
            int opcion= rand() % 3;
            if (opcion==1) PosicionX++;
            else if (opcion==2) PosicionY++;
            else PosicionY--;
        }
        else if(abj==true) {
            // Bloqueado por abajo: decidir entre subir, izquierda o derecha
            int opcion= rand() % 3;
            if (opcion==1) PosicionX--;
            else if (opcion==2) PosicionY--;
            else PosicionY++;
        }
        else if(der==true){
            // Bloqueado por derecha: decidir entre otras tres direcciones
            int opcion= rand() % 3;
            if (opcion==1) PosicionX++;
            else if (opcion==2) PosicionX--;
            else PosicionY--;
        }
        else if(izq==true){
            // Bloqueado por izquierda: decidir entre otras tres direcciones
            int opcion= rand() % 3;
            if (opcion==1) PosicionX--;
            else if (opcion==2) PosicionX++;
            else PosicionY++;
        }
        
        // ACTUALIZAR VISUALIZACIÓN después de cada movimiento
        vista.IncrementarPasos();
        vista.DibujarTablero(matriz);
        vista.Delay(500);  // Medio segundo entre movimientos
    }

    // Mostrar mensaje de victoria
    vista.MostrarVictoria();
    
    return "COMPLETADO";
}


void Movimiento::MoverseArriba() {
    PosicionX--;
}

void Movimiento::MoverseAbajo() {
    PosicionX++;
}

void Movimiento::MoverseDerecha() {
    PosicionY++;
}

void Movimiento::MoverseIzquierda() {
    PosicionY--;
}

// ====== Funciones de detección individuales ======

bool Movimiento::DetectarVacioDerecha(int (&matriz)[10][10]) {
    if (PosicionY < 9) {
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
    if (PosicionX > 0) {
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