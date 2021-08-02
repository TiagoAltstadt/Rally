//Cambio

main() {
    //declare ud. las variables de esta función y su inicialización, si corresponde.
    Abrir (EtapasRally);	    // Dentro del módulo ProcEtapasRally, invocar a LeeretapsRally.
                                                       // Dentro de los módulos de los listados si corresponde     
    ProcEtapasRally(argumentos…);   // se deberá invocar al módulo de OrdxBur.
    ListadoCorredores(argumentos…);  // En el módulo ListadoCorredores debe existir un 
    ListadoLargada(argumentos…);      // freopen(nomFisArchivo, modo, stdout);
    ListadoPuestosFinal(argumentos…);  // En el módulo ListadoGanadoresxTipoVehic debe
    ListadoGanadoresxTipoVehic(argumentos…);  // volverse el freopen a la consola.
    Cerrar (EtapasRally);   
    return 0;
} //main