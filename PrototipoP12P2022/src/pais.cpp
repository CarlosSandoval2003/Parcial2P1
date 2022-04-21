#include "pais.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

pais::pais(int valorNumeroId,
   string valorNombre)
{
   establecerId( valorNumeroId );
   establecerNombre( valorNombre );
}

int pais::obtenerNumeroId() const
{
   return numeroId;

}

void pais::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

string pais::obtenerNombre() const
{
   return nombre;

}

void pais::establecerNombre( string nombreString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorNombre = nombreString.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 17 ? longitud : 16 );
   strncpy( nombre, valorNombre, longitud );

   // anexar caracter nulo al apellido
   nombre[ longitud ] = '\0';

}


void pais::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "ReportePuestos.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   pais player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, player );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( pais ) );

   } // fin de instrucción while

}


void pais::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el ID del Pais a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( pais ) );

   // leer el primer registro del archivo
   pais player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );
    int choice;
   // actualizar el registro
   if ( player.obtenerNumeroId() != 0 ) {

         cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"<< endl;
      mostrarLinea( cout, player );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Nombre"<<endl;
	  cout<<"2. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            {cout << "Ingrese el nuevo Nombre: "<<endl;
            string cambioNombre;
            cin >> cambioNombre;

      // actualizar el saldo del registro
            player.establecerNombre( cambioNombre );}
            break;
        case 2:
            cout << "Modificacion cancelada, empleado sin cambios "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( pais ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( pais ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else{
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;
         }

}


void pais::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo puesto: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( pais ) );

   // leer el registro del archivo
   pais player;
   insertarEnArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );

   // crear el registro, si éste no existe ya
   if ( player.obtenerNumeroId() == 0 ) {

      char nombre[ 16 ];


      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 16 ) >> nombre;

      // usar valores para llenar los valores de la cuenta
      player.establecerNombre( nombre );
      player.establecerId( numeroId );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( pais ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( pais ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}


void pais::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el ID del puesto a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( pais ) );

   // leer el registro del archivo
   pais player;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );

   // eliminar el registro, si es que existe en el archivo
   if ( player.obtenerNumeroId() != 0 ) {
      pais entrenadorEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( pais ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( pais ) );

      cout << "Puesto con ID #" << numeroId << " eliminado.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "No existe ningun puesto con el ID #" << numeroId<<endl;

}

void pais::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   pais player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(player);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( pais ) );

   } // fin de instrucción while

}


void pais::mostrarLinea( ostream &salida, const pais &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerNombre().data()<<endl;

} // fin de la función mostrarLinea
void pais::mostrarLineaPantalla( const pais &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerNombre().data()<<endl;
} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int pais::obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

} // fin de la función obtenerCuenta
void pais::crearArchivoPais()
{
    ofstream paisSalida( "paises.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !paisSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   pais entrenadorEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 1000; i++ )
      paisSalida.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( pais ) );
}

fstream pais::inicioArchivo(){
    pais player;
        fstream paisEntradaSalida( "paises.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !paisEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      player.crearArchivoPais();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return paisEntradaSalida;
}

void pais::busquedaRegistro(fstream &actualizarArchivo)
{

       int numeroId = obtenerId( "Escriba el ID del pais a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( pais ) );

   // leer el primer registro del archivo
   pais player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( pais ) );
if ( player.obtenerNumeroId() != 0 ) {
      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( pais ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
