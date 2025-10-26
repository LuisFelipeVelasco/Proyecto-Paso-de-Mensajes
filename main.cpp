//
// Created by luisf on 25/10/2025.
//

#include <iostream>
#include <string>
#include "Tablero.h"
#include "Avatar.h"
#include "Movimiento.h"

int main() {
    std::cout << "=========================================================================================" << std::endl;
    std::cout << "====================================  LABERINTO  ========================================" << std::endl;
    std::cout << "=========================================================================================" << std::endl;
    std::cout << std::endl;
    Tablero Laberinto;
    Laberinto.Definirposicion();
    int PosicionX=Laberinto.GetTableroX();
    int PosicionY=Laberinto.GetTableroY();
    Avatar AgenteI("Terminator :V " , PosicionX, PosicionY); //PASO POR REFERENCIA
    AgenteI.Posicion();
    Movimiento MovimientoAgente(AgenteI.GetPosicionX(),AgenteI.GetPosicionY()); // AQUI NOS SALIA UN ERROR Y LA SOLUCION FUE PONERLE COMO REFERENCIA LOS ATRIBUTOS DE Avatar
    MovimientoAgente.MoverseArriba();
    MovimientoAgente.MoverseDerecha();
    MovimientoAgente.MoverseAbajo();
    MovimientoAgente.MoverseIzquierda();
    MovimientoAgente.MoverseArriba();
    AgenteI.Posicion();





    return 0;
}
