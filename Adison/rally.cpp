//-----Estructura de base de datos
// a: Número de Etapa (1 díg.)
// b: Tipo de Vehículo (1 díg.)
// c: Número de vehículo (2 dígs.)
// d: Nombre del Piloto (str20)
// e: Nombre del CoPiloto (str20)
// f: Marca del vehículo (str15)
// g: Tiempo en minutos (3 dígs.)
// La cantidad máxima de registros está indicada por la constante MAX_REGS = 500.
// Cantidad de Etapas cinco (5)
// Cantidad de Tipos de Vehículos cuatro (4)
// Máxima cantidad de vehículos cien (100).

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

void lectura();

int main(){
    lectura();

    system("pause");
    return 0;
}

void lectura(){
    ifstream archivo;
    string texto;
    archivo.open("Erally.txt",ios::in);//para abrir el archivo

    if (archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){//mientras no sea el final final del archivo, sigue recorriendo
            getline(archivo, texto);
            cout <<texto<<endl;
    }
    archivo.close();
}
