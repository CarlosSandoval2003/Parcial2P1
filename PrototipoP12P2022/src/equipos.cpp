#include "equipos.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

equipos::equipos(int valorNumeroId,
   string valorNombre, string valorDeporte, string valorEntrenador, int valorJugadores )
{
   establecerId( valorNumeroId );
   establecerNombre( valorNombre );
   establecerDeporte( valorDeporte );
   establecerEntrenador( valorEntrenador );
   establecerJugadores(valorJugadores);
}

int equipos::obtenerNumeroId() const
{
   return numeroId;

}

void equipos::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

string equipos::obtenerNombre() const
{
   return nombre;

}

void equipos::establecerNombre( string nombreString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorNombre = nombreString.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 16 ? longitud : 15 );
   strncpy( nombre, valorNombre, longitud );

   // anexar caracter nulo al apellido
   nombre[ longitud ] = '\0';

}

string equipos::obtenerDeporte() const
{
   return deporte;

}

void equipos::establecerDeporte( string deporteString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorDeporte = deporteString.data();
   int longitud = strlen( valorDeporte );
   longitud = ( longitud < 17 ? longitud : 16 );
   strncpy( deporte, valorDeporte, longitud );

   // anexar caracter nulo al apellido
   deporte[ longitud ] = '\0';

}

string equipos::obtenerEntrenador() const
{
   return entrenador;

}

void equipos::establecerEntrenador( string entrenadorString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorEntrenador = entrenadorString.data();
   int longitud = strlen( valorEntrenador );
   longitud = ( longitud < 16 ? longitud : 15 );
   strncpy( entrenador, valorEntrenador, longitud );

   // anexar caracter nulo al apellido
   entrenador[ longitud ] = '\0';

}


int equipos::obtenerJugadores() const
{
   return jugadores;

}

void equipos::establecerJugadores( int valorJugadores )
{
   jugadores = valorJugadores;

}



void equipos::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "ReporteEquipos.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 16 )
       << "Nombre" << setw( 15 ) << "Deporte"
       << setw( 16 ) <<"Entrenador"<<setw( 6 )<<"Numero de Jugadores"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   equipos team;
   leerDeArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( team.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, team );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &team ),
         sizeof( equipos ) );

   } // fin de instrucción while

}


void equipos::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el ID del Equipo a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( equipos ) );

   // leer el primer registro del archivo
   equipos team;
   actualizarArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );
    int choice;
   // actualizar el registro
   if ( team.obtenerNumeroId() != 0 ) {

         cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Nombre" << setw( 15 ) << "Deporte"
       << setw( 16 ) <<"Entrenador"<<setw( 6 )<<"Numero de Jugadores" << endl;
      mostrarLinea( cout, team );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Nombre"<<endl;
	  cout<<"2. Deporte"<<endl;
	  cout<<"3. Entrenador"<<endl;
	  cout<<"4. Numero de Jugadores"<<endl;
	  cout<<"5. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            {cout << "Ingrese el nuevo nombre: "<<endl;
            string cambioNombre;
            cin >> cambioNombre;

        // actualizar el saldo del registro
            team.establecerNombre( cambioNombre );}
            break;
        case 2:
            {cout << "Ingrese el nuevo Deporte: "<<endl;
            string cambioDeporte;
            cin >> cambioDeporte;

      // actualizar el saldo del registro
            team.establecerDeporte( cambioDeporte );}
            break;
        case 3:
            {cout << "Ingrese el nombre del nuevo Entrenador: "<<endl;
            string cambioEntrenador; // cargo o abono
            cin >> cambioEntrenador;

      // actualizar el saldo del registro
            team.establecerEntrenador( cambioEntrenador );}
            break;
        case 4:
            {cout << "Ingrese la nueva cantidad de jugadores: "<<endl;
            int cambioJugadores; // cargo o abono
            cin >> cambioJugadores;

        // actualizar el saldo del registro
            team.establecerJugadores( cambioJugadores );}
            break;
        case 5:
            cout << "Modificacion cancelada, empleado sin cambios "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Nombre" << setw( 15 ) << "Deporte"
       << setw( 16 ) <<"Entrenador"<<setw( 6 )<<"Numero de Jugadores" << endl;
      mostrarLinea( cout, team );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( equipos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &team ),
         sizeof( equipos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}


void equipos::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo equipo: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( equipos ) );

   // leer el registro del archivo
   equipos team;
   insertarEnArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );

   // crear el registro, si éste no existe ya
   if ( team.obtenerNumeroId() == 0 ) {

      char nombre[ 15 ];
      char deporte[ 16 ];
      char entrenador[ 17 ];
      int jugadores;

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 15 ) >> nombre;
      cout << "Escriba el deporte: " << endl;
      cin >> setw( 16 ) >> deporte;
      cout << "Escriba el nombre del entrenador: "<<endl;
      cin >> setw( 17 ) >> entrenador;
      cout << "Escriba el numero de jugadores: "<<endl;
      cin >> setw(6)>> jugadores;

      // usar valores para llenar los valores de la cuenta
      team.establecerNombre( nombre );
      team.establecerDeporte( deporte );
      team.establecerEntrenador( entrenador );
      team.establecerJugadores( jugadores );
      team.establecerId( numeroId );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( equipos ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &team ),
         sizeof( equipos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}


void equipos::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el ID del equipo a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( equipos ) );

   // leer el registro del archivo
   equipos team;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( team.obtenerNumeroId() != 0 ) {
      equipos equipoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( equipos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &equipoEnBlanco ),
         sizeof( equipos ) );

      cout << "Equipo con ID #" << numeroId << " eliminado.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "No existe ningun equipo con el ID #" << numeroId<<endl;

}

void equipos::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Nombre" << setw( 15 ) << "Deporte"
       << setw( 16 ) <<"Entrenador"<<setw( 6 )<<"Numero de Jugadores" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   equipos team;
   leerDeArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( team.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(team);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &team ),
         sizeof( equipos ) );

   } // fin de instrucción while

}


void equipos::mostrarLinea( ostream &salida, const equipos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 15 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerDeporte().data()
          << setw( 17) << registro.obtenerEntrenador().data()
          << setw( 6 ) << registro.obtenerJugadores()<<endl;

} // fin de la función mostrarLinea
void equipos::mostrarLineaPantalla( const equipos &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 15 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerDeporte().data()
          << setw( 17) << registro.obtenerEntrenador().data()
          << setw( 6 ) << registro.obtenerJugadores()<<endl;
} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int equipos::obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

} // fin de la función obtenerCuenta
void equipos::crearArchivoEquipos()
{
    ofstream equiposSalida( "equipos.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !equiposSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   equipos equipoEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 1000; i++ )
      equiposSalida.write(
         reinterpret_cast< const char * >( &equipoEnBlanco ),
         sizeof( equipos ) );
}

fstream equipos::inicioArchivo(){
    equipos team;
        fstream equiposEntradaSalida( "equipos.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !equiposEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      team.crearArchivoEquipos();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return equiposEntradaSalida;
}

void equipos::busquedaRegistro(fstream &actualizarArchivo)
{

       int numeroId = obtenerId( "Escriba el ID del equipo a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( equipos ) );

   // leer el primer registro del archivo
   equipos team;
   actualizarArchivo.read( reinterpret_cast< char * >( &team ),
      sizeof( equipos ) );
if ( team.obtenerNumeroId() != 0 ) {
      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Nombre" << setw( 15 ) << "Deporte"
       << setw( 16 ) <<"Entrenador"<<setw( 6 )<<"Numero de Jugadores" << endl;
      mostrarLinea( cout, team );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( equipos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}


