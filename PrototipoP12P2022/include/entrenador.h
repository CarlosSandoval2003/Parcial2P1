#ifndef ENTRENADOR_H
#define ENTRENADOR_H
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

class entrenador
{
    public:
        entrenador( int = 0, string = "", string = "", string = "", string = "");

        void establecerId( int );
        int obtenerNumeroId() const;

   // funciones de acceso para apellido
        void establecerApellido( string );
        string obtenerApellido() const;

   // funciones de acceso para primerNombre
        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerNac( string );
        string obtenerNac() const;

   // funciones de acceso para el saldo
        void establecerEquipo( string );
        string obtenerEquipo() const;



        void imprimirRegistro( fstream& );
        void actualizarRegistro( fstream& );
        void nuevoRegistro( fstream& );
        void eliminarRegistro( fstream& );
        void mostrarLinea( ostream&, const entrenador & );
        int obtenerId( const char * const );
        void crearArchivoEntrenador();
        void consultarRegistro( fstream& );
        void busquedaRegistro(fstream&);
        void mostrarLineaPantalla( const entrenador &);
        fstream inicioArchivo();


    private:
        int numeroId;
        char apellido[ 15 ];
        char nombre[ 16 ];
        char fechaNac[ 12 ];
        char equipo[ 17 ];
};

#endif // ENTRENADOR_H
