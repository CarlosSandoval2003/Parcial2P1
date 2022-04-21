#ifndef PUESTO_H
#define PUESTO_H
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

class puesto
{
    public:
        puesto( int = 0, string = "", int = 0);

        void establecerId( int );
        int obtenerNumeroId() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerSal( int );
        int obtenerSal() const;




        void imprimirRegistro( fstream& );
        void actualizarRegistro( fstream& );
        void nuevoRegistro( fstream& );
        void eliminarRegistro( fstream& );
        void mostrarLinea( ostream&, const puesto & );
        int obtenerId( const char * const );
        void crearArchivoPuesto();
        void consultarRegistro( fstream& );
        void busquedaRegistro(fstream&);
        void mostrarLineaPantalla( const puesto &);
        fstream inicioArchivo();


    private:
        int numeroId;
        char nombre[ 16 ];
        int salario;
};

#endif // PUESTO_H
