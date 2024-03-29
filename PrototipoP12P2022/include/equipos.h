#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

class equipos
{
    public:
        equipos( int = 0, string = "", string = "", string = "", int = 0);

        void establecerId( int );
        int obtenerNumeroId() const;

   // funciones de acceso para apellido
        void establecerNombre( string );
        string obtenerNombre() const;

   // funciones de acceso para primerNombre
        void establecerDeporte( string );
        string obtenerDeporte() const;

   // funciones de acceso para el saldo
        void establecerEntrenador( string );
        string obtenerEntrenador() const;


        void establecerJugadores( int );
        int obtenerJugadores() const;

        void imprimirRegistro( fstream& );
        void actualizarRegistro( fstream& );
        void nuevoRegistro( fstream& );
        void eliminarRegistro( fstream& );
        void mostrarLinea( ostream&, const equipos & );
        int obtenerId( const char * const );
        void crearArchivoEquipos();
        void consultarRegistro( fstream& );
        void busquedaRegistro(fstream&);
        void mostrarLineaPantalla( const equipos &);
        fstream inicioArchivo();


    private:
        int numeroId;
        char nombre[ 15 ];
        char deporte[ 16 ];
        char entrenador[ 40 ];
        int jugadores;
};

#endif // EQUIPOS_H
