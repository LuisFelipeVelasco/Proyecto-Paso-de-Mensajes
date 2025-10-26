//
// Created by luisf on 25/10/2025.
//

#ifndef PROYECTO_AGENTE_INTELIGENTE_TABLERO_H
#define PROYECTO_AGENTE_INTELIGENTE_TABLERO_H
/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Tablero
Responsabilidades:
    - Crear una matriz 10x10 con valores en las cerdas de 0 y 1
    - Definir la posicion aleotoria del soldado
Colaboradores:
    - Avatar
===============================================================================
*/

class Tablero {
private:
    int TableroX{};
    int TableroY{};
    int matriz[10][10];
public:
    Tablero();
    void Definirposicion();
    void DefinirposicionX(); //cuando empieza el juego
    void DefinirposicionY(); //cuando empieza el juego
    int GetTableroX();
    int GetTableroY();


};


#endif //PROYECTO_AGENTE_INTELIGENTE_TABLERO_H