#include <iostream>
//#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include <sstream>
using namespace std;

const MAX_REGS = 500;
const MAX_ETAPAS = 5;
const MAX_TIPOS = 4;
typedef unsigned short ushort;
typedef char str20[21];
typedef char str15[16];

struct sEtapasRally {
    string nombre_piloto,
        nombre_copiloto,
        marca_vehiculo;
    ushort tiempo,
        nro_etapa,
        tipo_vehiculo,
        nro_vehiculo;
};

struct sTiempoTotal {
    string nombre_piloto,
        nombre_copiloto,
        marca_vehiculo;
    ushort tiempo,
        tipo_vehiculo,
        nro_vehiculo,
        tiempo_total;
};
typedef sEtapasRally tblEtapasRally[MAX_REGS];
typedef sTiempoTotal tblTiemposTotales[MAX_REGS];
typedef sEtapasRally tblEtapasTipos[MAX_ETAPAS][MAX_TIPOS];


//Métodos auxiliares

string trim(string str, int a, int b)
{
    string ret;

    for (int i = a; i <= b; i++)
    {
        ret = ret + str[i];
    }
    return ret;
} // Funcion para recortar un string

void IntCmb(sEtapasRally &linea_1, sEtapasRally &linea_2) {
    sEtapasRally aux = linea_1;
    linea_1 = linea_2;
    linea_2 = aux;
} // IntCmb

void OrdxBur(tblEtapasRally linea_tabla,ushort card) {
    bool ordenado;
    ushort  k = 0;

    do{
        ordenado = true;
        k++;
        for (ushort i = 0; i < card - k; i++){
            if (linea_tabla[i].tipo_vehiculo > linea_tabla[i + 1].tipo_vehiculo) {
            ordenado = false;
            IntCmb(linea_tabla[i],linea_tabla[i + 1]);
            }
        }
    }
    while (!ordenado);
} // OrdxBur

void OrdxBur(ushort card, tblEtapasRally linea_tabla) {
    bool ordenado;
    ushort  k = 0;

    do{
        ordenado = true;
        k++;
        for (ushort i = 0; i < card - k; i++){
            if (linea_tabla[i].nro_etapa > linea_tabla[i + 1].nro_etapa){
            ordenado = false;
            IntCmb(linea_tabla[i],linea_tabla[i + 1]);
            }
        }
    }
    while (!ordenado);
} // OrdxBur

ushort BusBinVec(tblEtapasRally linea_tabla, ushort ult, ushort valor_buscado) {
  ushort pri = 1,
       med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (linea_tabla[med].tipo_vehiculo == valor_buscado)
	  return med;
  else
	  if (linea_tabla[med].tipo_vehiculo< valor_buscado)
		pri = med + 1;
    else
		  ult = med - 1;
  }
  return 0;
} // BusBinVec

ushort BusBinVec1(tblEtapasRally linea_tabla, ushort valor_buscado,ushort ult) {
  ushort pri = 1,
       med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (linea_tabla[med].nro_etapa == valor_buscado)
	  return med;
  else
	  if (linea_tabla[med].nro_etapa < valor_buscado)
		pri = med + 1;
    else
		  ult = med - 1;
  }
  return 0;
} // BusBinVec

//Metodos principales
void Abrir (FILE **file){
    *file = fopen("EtapasRally.txt", "r");
}

bool LeerEtapaRally (tblEtapasRally linea_tabla, FILE **file, ushort &counter){
    string data_line[MAX_REGS];
    counter = 0;
    char data[69];


    if (*file==NULL) return false;
    while (!feof(*file))
    { // Mientras el archivo no acabe
        fgets(data, 100, *file);
        data_line[counter] = data;
        counter++;
    }

    for (int i = 0; i < counter; i++)
    { // En cada linea, asigno a el array linea_tabla[] su respectiva variable

        ushort x;
        stringstream etapa(trim(data_line[i], 0, 0)); // Como tienen que ser de tipo int, los transformo y despues los asigno
        etapa >> x;
        linea_tabla[i].nro_etapa = x;

        stringstream tipo(trim(data_line[i], 2, 2));
        tipo >> x;
        linea_tabla[i].tipo_vehiculo = x;

        stringstream numero(trim(data_line[i], 4, 5));
        numero >> x;
        linea_tabla[i].nro_vehiculo = x;

        stringstream tiempo(trim(data_line[i], 65, 67));
        tiempo >> x;
        linea_tabla[i].tiempo = x;


        linea_tabla[i].nombre_piloto = trim(data_line[i], 7, 26); // Como estos tienen que ser un string, los asigno asi nomas al toque perro

        linea_tabla[i].nombre_copiloto = trim(data_line[i], 28, 47);

        linea_tabla[i].marca_vehiculo = trim(data_line[i], 49, 63);
    }

    return true;
}

void ProcEtapasRally(tblEtapasRally linea_tabla, FILE **file,ushort &counter){
    if (!LeerEtapaRally(linea_tabla, file, counter)){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
}

void ListadoCorredores(tblEtapasRally linea_tabla, ushort counter){
    freopen("ListadoRally.txt", "w", stdout);
    cout << "   Listado de Corredores de Etapas y Tipos de Vehículos"<< endl;
    cout << "   ----------------------------------------------------"<< endl;
    cout << "Etp. TpVehic. Nombre del Piloto        Nombre del CoPiloto          Marca Vehic.    Tiempo mins"<< endl;
    for (ushort i = 0 ; i<counter; i++){
        cout <<" "<< linea_tabla[i].nro_etapa <<"     "<< linea_tabla[i].tipo_vehiculo <<"      "
            << linea_tabla[i].nombre_piloto <<"     "<< linea_tabla[i].nombre_copiloto <<"         "
            << linea_tabla[i].marca_vehiculo <<"    "<< linea_tabla[i].tiempo << endl;
    }
    cout << endl;
}

void ListadoLargada(tblEtapasRally linea_tabla, ushort counter){
    OrdxBur(linea_tabla,counter);
    OrdxBur(counter,linea_tabla);
    ushort z = 0;

    cout << "   Listado de largada"<< endl;
    cout << "   ------------------"<< endl;

    for(ushort x = 1; x <= MAX_ETAPAS; x++){
        cout << "Nro. Etapa: " << x << endl;
        for(ushort y = 1; y <= MAX_TIPOS; y++){
             cout << "   Tipo Vehiculo: " << y << endl;
             cout << "       Nro. Vehic.  Nom. Piloto          Nom. CoPiloto        Marca Vehic." << endl;
             for(z; z < counter; z++){
                if (linea_tabla[z].nro_etapa == x & linea_tabla[z].tipo_vehiculo == y){
                    cout <<"          "<<setw(2)<< linea_tabla[z].nro_vehiculo<<"        "<<linea_tabla[z].nombre_piloto
                        <<" "<< linea_tabla[z].nombre_copiloto <<" "<< linea_tabla[z].marca_vehiculo << endl;

                } else {
                break;
                }
             }
        }
    }


}


void Cerrar(FILE **file){
    fclose(*file);
}




int main() {
    FILE *file;
    tblEtapasRally linea_tabla;
    ushort counter;

    Abrir(&file);
    ProcEtapasRally(linea_tabla, &file, counter);
    ListadoCorredores(linea_tabla,counter);
    ListadoLargada(linea_tabla, counter);
    /*
    Falta hacer ListadoPuestosFinal(argumentos…);  // En el módulo ListadoGanadoresxTipoVehic debe
    Falta hacer ListadoGanadoresxTipoVehic(argumentos…);  // volverse el freopen a la consola.
    */
    Cerrar(&file);
    return 0;
} //main





