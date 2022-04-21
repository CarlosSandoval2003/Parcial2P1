#include "entrenador.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

entrenador::entrenador(int valorNumeroId,
   string valorApellido, string valorNombre, string valorNac, string valorEquipo)
{
   establecerId( valorNumeroId );
   establecerApellido( valorApellido );
   establecerNombre( valorNombre );
   establecerNac(valorNac);
   establecerEquipo( valorEquipo );
}

int entrenador::obtenerNumeroId() const
{
   return numeroId;

}

void entrenador::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

string entrenador::obtenerApellido() const
{
   return apellido;

}

void entrenador::establecerApellido( string apellidoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorApellido = apellidoString.data();
   int longitud = strlen( valorApellido );
   longitud = ( longitud < 16 ? longitud : 15 );
   strncpy( apellido, valorApellido, longitud );

   // anexar caracter nulo al apellido
   apellido[ longitud ] = '\0';

}

string entrenador::obtenerNombre() const
{
   return nombre;

}

void entrenador::establecerNombre( string nombreString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorNombre = nombreString.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 17 ? longitud : 16 );
   strncpy( nombre, valorNombre, longitud );

   // anexar caracter nulo al apellido
   nombre[ longitud ] = '\0';

}

string entrenador::obtenerNac() const
{
   return fechaNac;

}

void entrenador::establecerNac( string nacString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorNac = nacString.data();
   int longitud = strlen( valorNac );
   longitud = ( longitud < 13 ? longitud : 12 );
   strncpy( fechaNac, valorNac, longitud );

   // anexar caracter nulo al apellido
   fechaNac[ longitud ] = '\0';

}


string entrenador::obtenerEquipo() const
{
   return equipo;

}

void entrenador::establecerEquipo( string equipoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorEquipo = equipoString.data();
   int longitud = strlen( valorEquipo );
   longitud = ( longitud < 18 ? longitud : 17 );
   strncpy( equipo, valorEquipo, longitud );

   // anexar caracter nulo al apellido
   equipo[ longitud ] = '\0';

}




void entrenador::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "ReporteEntrenadores.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 17 ) << "Nombre"
       << setw( 25) <<"Fecha de Nacimiento"<<setw( 18 )<<"Equipo"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   entrenador player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, player );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( entrenador ) );

   } // fin de instrucción while

}


void entrenador::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el ID del Entrenador a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( entrenador ) );

   // leer el primer registro del archivo
   entrenador player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );
    int choice;
   // actualizar el registro
   if ( player.obtenerNumeroId() != 0 ) {

         cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 17 ) << "Nombre"
       << setw( 25 ) <<"Fecha de Nacimiento"<<setw( 18 )<<"Equipo"<< endl;
      mostrarLinea( cout, player );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Apellido"<<endl;
	  cout<<"2. Nombre"<<endl;
	  cout<<"3. Fecha de Nacimiento"<<endl;
	  cout<<"4. Equipo"<<endl;
	  cout<<"5. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            {cout << "Ingrese el nuevo apellido: "<<endl;
            string cambioApellido;
            cin >> cambioApellido;

        // actualizar el saldo del registro
            player.establecerApellido( cambioApellido );}
            break;
        case 2:
            {cout << "Ingrese el nuevo Nombre: "<<endl;
            string cambioNombre;
            cin >> cambioNombre;

      // actualizar el saldo del registro
            player.establecerNombre( cambioNombre );}
            break;
        case 3:
            {cout << "Ingrese la nueva fecha: "<<endl;
            string cambioFecha; // cargo o abono
            cin >> cambioFecha;
      // actualizar el saldo del registro
            player.establecerNac(cambioFecha);}
            break;
        case 4:
            {cout << "Ingrese el nombre del nuevo equipo: "<<endl;
            string cambioEquipo; // cargo o abono
            cin >> cambioEquipo;

        // actualizar el saldo del registro
            player.establecerEquipo( cambioEquipo );}
            break;
        case 5:
            cout << "Modificacion cancelada, empleado sin cambios "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 17 ) << "Nombre"
       << setw( 25 ) <<"Fecha de Nacimiento"<<setw( 18 )<<"Equipo"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( entrenador ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( entrenador ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else{
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;
         }

}


void entrenador::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo entrenador: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( entrenador ) );

   // leer el registro del archivo
   entrenador player;
   insertarEnArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );

   // crear el registro, si éste no existe ya
   if ( player.obtenerNumeroId() == 0 ) {

      char apellido[ 15 ];
      char nombre[ 16 ];
      char fechaNac[ 12 ];
      char equipo[ 17 ];
      char posicion[ 4 ];


      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el apellido: " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 16 ) >> nombre;
      cout << "Escriba la fecha de nacimiento: "<<endl;
      cin >> setw( 12 ) >> fechaNac;
      cout << "Escriba el nombre del equipo: "<<endl;
      cin >> setw(17)>> equipo;

      // usar valores para llenar los valores de la cuenta
      player.establecerApellido( apellido );
      player.establecerNombre( nombre );
      player.establecerNac( fechaNac );
      player.establecerEquipo( equipo );
      player.establecerId( numeroId );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( entrenador ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( entrenador ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}


void entrenador::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el ID del equipo a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( entrenador ) );

   // leer el registro del archivo
   entrenador player;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );

   // eliminar el registro, si es que existe en el archivo
   if ( player.obtenerNumeroId() != 0 ) {
      entrenador entrenadorEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( entrenador ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( entrenador ) );

      cout << "Entrenador con ID #" << numeroId << " eliminado.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "No existe ningun jugador con el ID #" << numeroId<<endl;

}

void entrenador::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 17 ) << "Nombre"
       << setw( 25 ) <<"Fecha de Nacimiento"<<setw( 18 )<<"Equipo"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   entrenador player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(player);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( entrenador ) );

   } // fin de instrucción while

}


void entrenador::mostrarLinea( ostream &salida, const entrenador &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 15 ) << registro.obtenerApellido().data()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 12 ) << registro.obtenerNac().data()
          << setw( 17 ) << registro.obtenerEquipo().data()<<endl;

} // fin de la función mostrarLinea
void entrenador::mostrarLineaPantalla( const entrenador &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 15 ) << registro.obtenerApellido().data()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 25 ) << registro.obtenerNac().data()
          << setw( 17 ) << registro.obtenerEquipo().data()<<endl;
} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int entrenador::obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

} // fin de la función obtenerCuenta
void entrenador::crearArchivoEntrenador()
{
    ofstream entrenadorSalida( "entrenadores.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !entrenadorSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   entrenador entrenadorEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 1000; i++ )
      entrenadorSalida.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( entrenador ) );
}

fstream entrenador::inicioArchivo(){
    entrenador player;
        fstream entrenadorEntradaSalida( "entrenadores.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !entrenadorEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      player.crearArchivoEntrenador();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return entrenadorEntradaSalida;
}

void entrenador::busquedaRegistro(fstream &actualizarArchivo)
{

       int numeroId = obtenerId( "Escriba el ID del entrenador a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( entrenador ) );

   // leer el primer registro del archivo
   entrenador player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( entrenador ) );
if ( player.obtenerNumeroId() != 0 ) {
      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 17 ) << "Nombre"
       << setw( 25 ) <<"Fecha de Nacimiento"<<setw( 18 )<<"Equipo"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( entrenador ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
