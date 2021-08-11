//-----Estructura de base de datos
// a: N�mero de Etapa (1 d�g.)
// b: Tipo de Veh�culo (1 d�g.)
// c: N�mero de veh�culo (2 d�gs.)
// d: Nombre del Piloto (str20)
// e: Nombre del CoPiloto (str20)
// f: Marca del veh�culo (str15)
// g: Tiempo en minutos (3 d�gs.)
// La cantidad m�xima de registros est� indicada por la constante MAX_REGS = 500.
// Cantidad de Etapas cinco (5)
// Cantidad de Tipos de Veh�culos cuatro (4)
// M�xima cantidad de veh�culos cien (100).

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
