#ifndef PAIS_H
#define PAIS_H
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

class pais
{
    public:
        pais( int = 0, string = "");

        void establecerId( int );
        int obtenerNumeroId() const;

        void establecerNombre( string );
        string obtenerNombre() const;




        void imprimirRegistro( fstream& );
        void actualizarRegistro( fstream& );
        void nuevoRegistro( fstream& );
        void eliminarRegistro( fstream& );
        void mostrarLinea( ostream&, const pais & );
        int obtenerId( const char * const );
        void crearArchivoPais();
        void consultarRegistro( fstream& );
        void busquedaRegistro(fstream&);
        void mostrarLineaPantalla( const pais &);
        fstream inicioArchivo();


    private:
        int numeroId;
        char nombre[ 16 ];
};

#endif // PAIS_H
