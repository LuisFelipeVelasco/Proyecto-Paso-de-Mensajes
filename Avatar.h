//
// Created by Janus on 26/10/2025.
//


#ifndef PROYECTO_AGENTE_INTELIGENTE_AVATAR_H
#define PROYECTO_AGENTE_INTELIGENTE_AVATAR_H
#include <string>
/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Avatar
Responsabilidades:
    - Definir un avatar con un nombre y la posicion en la matriz
    - imprimir la posicion actual del soldado
Colaboradores:
    - Tablero
    - Movimineto
===============================================================================
*/

class Avatar {
private:
    std::string Nombre{};
    int PosicionX{};
    int PosicionY{};
public:
    Avatar(std::string Nombre , int& PosicionX, int& PosicionY);
    std::string GetNombre();
    int& GetPosicionY() ;
    int& GetPosicionX() ;
    void SetPosicionX(int posicionX);
    void SetPosicionY(int posicionY);
    void Posicion();
};



#endif //PASO_MENSAJES_AVATAR_H