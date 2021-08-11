//-----Estructura de base de datos
// a: NÃºmero de Etapa (1 dÃ­g.)
// b: Tipo de VehÃ­culo (1 dÃ­g.)
// c: NÃºmero de vehÃ­culo (2 dÃ­gs.)
// d: Nombre del Piloto (str20)
// e: Nombre del CoPiloto (str20)
// f: Marca del vehÃ­culo (str15)
// g: Tiempo en minutos (3 dÃ­gs.)
// La cantidad mÃ¡xima de registros estÃ¡ indicada por la constante MAX_REGS = 500.
// Cantidad de Etapas cinco (5)
// Cantidad de Tipos de VehÃ­culos cuatro (4)
// MÃ¡xima cantidad de vehÃ­culos cien (100).

#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <string>  

using namespace std;

// Al pedo

bool LeerEtapasRally();
void ListadoCorredores();
void ListadoLargada();
void ListadoPuestosFinal();
void ListadoGanadoresxTipoVehic();
void ProcEtapasRally();
void OrdxBur();
void IntCmb();
bool LeerEtapaRally();
short BusBinVec();
void BusSecMinTmpxTipoV();

// Utilizadas
int Abrir();
string splitString(string str, string delimiter);
string trim(string, int, int);

//-----Variables-----
struct DB
{
    int nro_etapa;
    int tipo_vehiculo;
    int nro_vehiculo;
    string nombre_piloto;
    string nombre_copiloto;
    string marca_vehiculo;
    int tiempo;
};
DB linea[500];

int MAX_REGS = 500;
int etapas = 5;
int tipos_vehiculo = 4;
int max_vehiculosxtipo = 100;

main()
{
    Abrir();
    // Dentro del mÃ³dulo ProcEtapasRally, invocar a LeeretapsRally.
    // Dentro de los mÃ³dulos de los listados si corresponde
    // ProcEtapasRally();
    // ListadoCorredores();
    // ListadoLargada();
    // ListadoPuestosFinal();
    // ListadoGanadoresxTipoVehic();


    return 0;
}

int Abrir()
{
    string data_line[500];
    int counter = 0;
    int x;
    int arrSize = 0;
    string data;

    ifstream file; // Nombre que le asignamos al archivo

    file.open("./EtapasRally.txt", ios::in); // Abrimos el archivo en modo lectura

    // si no puedo abrir el archivo
    if (file.fail())
    {
        cout << "No se pudo abrir el archivo master";
    }

    // Si logro abrir el archivo
    while (!file.eof())
    { // Mientras el archivo no acabe
        getline(file, data);
        data_line[counter] = data;
        counter++;
    }
    counter--;
	cout<<counter<<endl;
    for (int i = 0; i < counter; i++)
    { // En cada linea, asigno a el array linea[] su respectiva variable

        int x = 0;

        stringstream etapa(trim(data_line[i], 0, 1)); // Como tienen que ser de tipo int, los transformo y despues los asigno
        etapa >> x;
        linea[i].nro_etapa = x;

        stringstream tipo(trim(data_line[i], 2, 3));
        tipo >> x;
        linea[i].tipo_vehiculo = x;

        stringstream numero(trim(data_line[i], 3, 5));
        numero >> x;
        linea[i].nro_vehiculo = x;

        stringstream tiempo(trim(data_line[i], 65, 67));
        tiempo >> x;
        linea[i].tiempo = x;

        linea[i].nombre_piloto = trim(data_line[i], 7, 25); // Como estos tienen que ser un string, los asigno asi nomas al toque perro

        linea[i].nombre_copiloto = trim(data_line[i], 28, 45);

        linea[i].marca_vehiculo = trim(data_line[i], 49, 63);
    }

	cout << "Numero de etapa | Tipo de vehiculo | Nro. Vehiculo | Nombre Piloto | |Nombre Co-piloto | Marca Vehiculo |  Tiempo (mins)"<<endl;
    for (int i = 0; i < counter; i++)
    { // Esto simplemente devuelve por consola la data
	
		cout 	<< linea[i].nro_etapa << "               | " 
				<< linea[i].tipo_vehiculo << "                | " 
				<< linea[i].nro_vehiculo << "        | " 
				<< linea[i].nombre_piloto + " | " 
				<< linea[i].nombre_copiloto + " | " + linea[i].marca_vehiculo + " | "  
				<< linea[i].tiempo << endl;
		
        cout << endl;
    }
    
	cout << "Cantidad de lineas -> " << counter <<endl;
    file.close(); // Cerramos el programa para que no quede abierto y porque lo dice el de youtube

    return 0;
}


string trim(string str, int a, int b)
{ // Funcion para recortar un string
    string ret;

    for (int i = a; i <= b; i++)
    {
        ret = ret + str[i];
    }
    return ret;
}
