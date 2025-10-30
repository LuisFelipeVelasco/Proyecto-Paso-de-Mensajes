//
// Created by luisf on 25/10/2025.
//

#include <iostream>
#include <string>
#include "Tablero.h"
#include "Avatar.h"
#include "Movimiento.h"
// X representa la fias y Y representa las columnas , es decir que y es el movimiento horizontal y  X el movimiento vertical
int main() {
    std::cout << "=========================================================================================" << std::endl;
    std::cout << "====================================  LABERINTO  ========================================" << std::endl;
    std::cout << "=========================================================================================" << std::endl;
    std::cout << std::endl;
    Tablero Laberinto;
    Laberinto.Definirposicion();
    int PosicionX=Laberinto.GetTableroX();
    int PosicionY=Laberinto.GetTableroY();
    //int PosicionX=4;
    //int PosicionY=1;
    Avatar AgenteI("Terminator :V " , PosicionX, PosicionY); //PASO POR REFERENCIA
    AgenteI.Posicion();
    Movimiento MovimientoAgente(AgenteI.GetPosicionX(),AgenteI.GetPosicionY()); // AQUI NOS SALIA UN ERROR Y LA SOLUCION FUE PONERLE COMO REFERENCIA LOS ATRIBUTOS DE Avatar
    MovimientoAgente.Moverse();








    return 0;
}