#ifndef JUGADOR_H
#define JUGADOR_H
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

class jugador
{
    public:
        jugador( int = 0, string = "", string = "",int = 0, string = "", string = "");

        void establecerId( int );
        int obtenerNumeroId() const;

   // funciones de acceso para apellido
        void establecerApellido( string );
        string obtenerApellido() const;

   // funciones de acceso para primerNombre
        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerEdad( int );
        int obtenerEdad() const;

   // funciones de acceso para el saldo
        void establecerEquipo( string );
        string obtenerEquipo() const;

        void establecerPosicion( string );
        string obtenerPosicion() const;


        void imprimirRegistro( fstream& );
        void actualizarRegistro( fstream& );
        void nuevoRegistro( fstream& );
        void eliminarRegistro( fstream& );
        void mostrarLinea( ostream&, const jugador & );
        int obtenerId( const char * const );
        void crearArchivoJugador();
        void consultarRegistro( fstream& );
        void busquedaRegistro(fstream&);
        void mostrarLineaPantalla( const jugador &);
        fstream inicioArchivo();


    private:
        int numeroId;
        char apellido[ 15 ];
        char nombre[ 16 ];
        int edad;
        char equipo[ 17 ];
        char posicion[ 4 ];
};


#endif // JUGADOR_H
