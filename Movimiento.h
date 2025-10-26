//
// Created by luisf on 25/10/2025.
//

#ifndef PROYECTO_AGENTE_INTELIGENTE_MOVIMIENTO_H
#define PROYECTO_AGENTE_INTELIGENTE_MOVIMIENTO_H

#include <string>

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
    std::string Detectar(); // llamo al metodo Detectar , el llama a todas los metodos de detectacion y toma una decisicion respecto al booleano que me den , ¿Cual descision?, llamar a un metodo de movimiento y devuelve un string que sera la posicion en consola
    bool DetectarVacioDerecha();
    bool DetectarVacioIzquierda();
    bool DetectarVacioArriba();
    bool DetectarVacioAbajo();
    void MoverseArriba();
    void MoverseAbajo();
    void MoverseDerecha();
    void MoverseIzquierda();

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

#endif //PROYECTO_AGENTE_INTELIGENTE_MOVIMIENTO_H


// dependiendo de los true o false de detectar se llama uno o dos de movimiento al azar
