//
// Created by Janus on 26/10/2025.
//

#ifndef PROYECTO_AGENTE_INTELIGENTE_MOVIMIENTO_H
#define PROYECTO_AGENTE_INTELIGENTE_MOVIMIENTO_H

#include <string>
#include <vector>

/*
===============================================================================
                                MOVIMIENTO CRC
===============================================================================
Nombre de la clase:       Movimiento
Responsabilidades:
    - Movimiento del soldado (arriba, abajo, izquierda, derecha)
Colaboradores:
    - Avatar
===============================================================================
*/
class Movimiento {
private:
    int& PosicionX ;
    int& PosicionY ;

public:
    Movimiento( int& posicionX ,  int& posicionY); // el personaje tiene un metodo , get position , ese se le passa a este constructor y HAY QUE HACER QUE
    bool DetectarVacioDerecha(int (&matriz)[10][10]);
    bool DetectarVacioIzquierda(int (&matriz)[10][10]);
    bool DetectarVacioArriba(int (&matriz)[10][10]);
    bool DetectarVacioAbajo(int (&matriz)[10][10]);
    void MoverseArriba();
    void MoverseAbajo();
    void MoverseDerecha();
    void MoverseIzquierda();
    std::string Moverse();



};
// valor avatar y = 3 , //vaor avatar x = 4
//LLamo detectar abajo

//casilla = laberinto[x][y+1]
//if casilla==1 {return true};
// else { return false}


//LLamo detectar arriba
//casilla = laberinto[x][y]
//if casilla==1 {return true};


//LLamo detectar derecha
//casilla = laberinto[x][y]
//if casilla==1 {return true};


//LLamo detectar izquierda
//casilla = laberinto[x][y]
//if casilla==1 {return true};




// dependiendo de los true o false de detectar se llama uno o dos de movimiento al azar


#endif //PASO_MENSAJES_MOVIMIENTO_H