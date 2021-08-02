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
#include <iomanip>
#include <fstream>
using namespace std;

bool LeerEtapasRally();
void ListadoCorredores();
void ListadoLargada();
void ListadoPuestosFinal();
void ListadoGanadoresxTipoVehic();

int Abrir();
void ProcEtapasRally();
void Cerrar();

void OrdxBur();
void IntCmb();
bool LeerEtapaRally();
short BusBinVec();
void BusSecMinTmpxTipoV();

//-----Variables-----
struct DB
{
    int nro_etapa;
    int tipo_vehiculo;
    int nro_vehiculo;
    string nombre_piloto[20];
    string nombre_copiloto[20];
    string marca_vehiculo[15];
    int tiempo;
};

DB linea[100];

main()
{
    Abrir();
    // Dentro del módulo ProcEtapasRally, invocar a LeeretapsRally.
    // Dentro de los módulos de los listados si corresponde
    // ProcEtapasRally();
    // ListadoCorredores();
    // ListadoLargada();
    // ListadoPuestosFinal();
    // ListadoGanadoresxTipoVehic();

    // Cerrar();

    return 0;
}

int Abrir()
{
    int x;

    ifstream inFile;

    inFile.open("./EtapasRally.txt");

    // si no puedo abrir el archivo
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }

    // si logro abrir el archivo
    else
    {

        while (inFile >> x)
        {
            linea[0].nro_etapa = x;
            cout << "x = " << x << endl;
        }
    }

    inFile.close();

    return 0;
}
