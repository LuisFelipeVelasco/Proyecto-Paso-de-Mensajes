//
// Created by Janus on 26/10/2025.
//


#include "Tablero.h"
#include <cstdlib>
#include <iostream>
/*
========================================================================================
                        IMPLEMENTACIÓN DE LA CLASE TABLERO
========================================================================================
La clase Tablero representa un tablero de 10x10 con valores 0 y 1, tambien almacena la
posicion actual en coordenadas TableroX y TableroY, tambien define una posicion valida
(donde la celda es diferente de cero) y tambien provee acceso a las coordenadas actuales
mediante getters

Se demuestra:
 - Uso de constructores mediante atributod y estructuras bidimmensionales
 - Uso de metodos para la generacion de coordenadas aleatorias
 - Impresion de matrices en consola con bucles anidados
========================================================================================
*/
Tablero::Tablero() {

    this->TableroX = 0;
    this->TableroY = 0;
    matriz[0][0] = 0;
    matriz[0][1] = 0;
    matriz[0][2] = 1;
    matriz[0][3] = 0;
    matriz[0][4] = 1;
    matriz[0][5] = 1;
    matriz[0][6] = 0;
    matriz[0][7] = 0;
    matriz[0][8] = 0;
    matriz[0][9] = 1;

    matriz[1][0] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 0;
    matriz[1][4] = 1;
    matriz[1][5] = 0;
    matriz[1][6] = 0;
    matriz[1][7] = 1;
    matriz[1][8] = 0;
    matriz[1][9] = 1;

    matriz[2][0] = 0;
    matriz[2][1] = 0;
    matriz[2][2] = 1;
    matriz[2][3] = 0;
    matriz[2][4] = 1;
    matriz[2][5] = 1;
    matriz[2][6] = 1;
    matriz[2][7] = 1;
    matriz[2][8] = 1;
    matriz[2][9] = 1;

    matriz[3][0] = 0;
    matriz[3][1] = 1;
    matriz[3][2] = 1;
    matriz[3][3] = 0;
    matriz[3][4] = 0;
    matriz[3][5] = 0;
    matriz[3][6] = 0;
    matriz[3][7] = 0;
    matriz[3][8] = 0;
    matriz[3][9] = 1;

    matriz[4][0] = 0;
    matriz[4][1] = 1;
    matriz[4][2] = 0;
    matriz[4][3] = 1;
    matriz[4][4] = 1;
    matriz[4][5] = 1;
    matriz[4][6] = 0;
    matriz[4][7] = 1;
    matriz[4][8] = 1;
    matriz[4][9] = 1;

    matriz[5][0] = 1;
    matriz[5][1] = 1;
    matriz[5][2] = 0;
    matriz[5][3] = 1;
    matriz[5][4] = 0;
    matriz[5][5] = 1;
    matriz[5][6] = 0;
    matriz[5][7] = 1;
    matriz[5][8] = 0;
    matriz[5][9] = 1;

    matriz[6][0] = 1;
    matriz[6][1] = 0;
    matriz[6][2] = 0;
    matriz[6][3] = 1;
    matriz[6][4] = 0;
    matriz[6][5] = 1;
    matriz[6][6] = 0;
    matriz[6][7] = 1;
    matriz[6][8] = 1;
    matriz[6][9] = 0;

    matriz[7][0] = 1;
    matriz[7][1] = 1;
    matriz[7][2] = 1;
    matriz[7][3] = 0;
    matriz[7][4] = 1;
    matriz[7][5] = 1;
    matriz[7][6] = 0;
    matriz[7][7] = 1;
    matriz[7][8] = 0;
    matriz[7][9] = 0;

    matriz[8][0] = 0;
    matriz[8][1] = 0;
    matriz[8][2] = 1;
    matriz[8][3] = 0;
    matriz[8][4] = 0;
    matriz[8][5] = 1;
    matriz[8][6] = 1;
    matriz[8][7] = 1;
    matriz[8][8] = 1;
    matriz[8][9] = 1;

    matriz[9][0] = 0;
    matriz[9][1] = 1;
    matriz[9][2] = 1;
    matriz[9][3] = 1;
    matriz[9][4] = 1;
    matriz[9][5] = 1;
    matriz[9][6] = 0;
    matriz[9][7] = 0;
    matriz[9][8] = 0;
    matriz[9][9] = 1;
    srand(time(0));
    // for (int i=0; i < 10; i++) {
    //     for (int j=0; j < 10; j++) {
    //
    //         std::cout<<"["<<i<<"]"<<"["<<j<<"]"<<"="<<matriz[i][j]<<" ";
    //     }
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }

}



void Tablero::Definirposicion() {

    int aux=0;
    while (aux ==0 or (TableroX==9 and TableroY==9)) {
        DefinirposicionX();
        DefinirposicionY();
        aux=matriz[TableroX][TableroY];
    }

//establezco una veriable para el condicional = 0
    //el condicional se va a repetir mientras que la posicion x , y sea igual a 0 matriz[x][y]= 0
//llamo a los dos metodos
    //definiriposicionx me guarda cualquier numero en el atributo x
    //definiposcion y me guarda cualquier nuemro el atributo y

}

void Tablero::DefinirposicionX() {
    // Inicializa la semilla (solo se hace una vez)
    TableroX = rand() % 10; // Genera número entre 0 y 9


}

void Tablero::DefinirposicionY() {
              // Inicializa la semilla (solo se hace una vez)
    TableroY = rand() % 10; // Genera número entre 0 y 9

}
//necesito uno solo que me devuelve dos cosas
//creamos un metodefinirgeneral , metemos definir posicion y , y definiri poscion x en un bucle dentro de ese metodo general , hasta que me cumplan condicion de que matriz[i][j] !=0;

int Tablero::GetTableroX() {
    return TableroX;
}
int Tablero::GetTableroY() {
    return TableroY;
}
//Se añadio el getter para poder leer la matriz en movimiento.cpp
int Tablero::matriz[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int (&Tablero::GetMatrizStatic())[10][10] {
    return matriz;
}
