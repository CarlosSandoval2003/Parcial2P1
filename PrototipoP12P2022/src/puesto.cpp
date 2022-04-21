#include "puesto.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

puesto::puesto(int valorNumeroId,
   string valorNombre, int valorSal)
{
   establecerId( valorNumeroId );
   establecerNombre( valorNombre );
   establecerSal(valorSal);
}

int puesto::obtenerNumeroId() const
{
   return numeroId;

}

void puesto::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

string puesto::obtenerNombre() const
{
   return nombre;

}

void puesto::establecerNombre( string nombreString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorNombre = nombreString.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 17 ? longitud : 16 );
   strncpy( nombre, valorNombre, longitud );

   // anexar caracter nulo al apellido
   nombre[ longitud ] = '\0';

}

int puesto::obtenerSal() const
{
   return salario;

}

void puesto::establecerSal(int valorSal)
{
    salario = valorSal;
}




void puesto::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "ReportePuestos.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"
       << setw( 10 )<<"Salario"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   puesto player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, player );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( puesto ) );

   } // fin de instrucción while

}


void puesto::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el ID del Entrenador a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( puesto ) );

   // leer el primer registro del archivo
   puesto player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );
    int choice;
   // actualizar el registro
   if ( player.obtenerNumeroId() != 0 ) {

         cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"
       <<setw( 10 )<<"Salario"<< endl;
      mostrarLinea( cout, player );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Nombre"<<endl;
	  cout<<"2. Salario"<<endl;
	  cout<<"3. Cancelar"<<endl;
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
            {cout << "Ingrese el nuevo salario: "<<endl;
            int cambioSal; // cargo o abono
            cin >> cambioSal;
      // actualizar el saldo del registro
            player.establecerSal(cambioSal);}
            break;
        case 3:
            cout << "Modificacion cancelada, empleado sin cambios "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"
       <<setw( 10 )<<"Salario"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( puesto ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( puesto ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else{
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;
         }

}


void puesto::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo puesto: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( puesto ) );

   // leer el registro del archivo
   puesto player;
   insertarEnArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );

   // crear el registro, si éste no existe ya
   if ( player.obtenerNumeroId() == 0 ) {

      char nombre[ 16 ];
      int salario;


      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 16 ) >> nombre;
      cout << "Escriba el nuevo salario(Q): "<<endl;
      cin >> setw( 10 ) >> salario;

      // usar valores para llenar los valores de la cuenta
      player.establecerNombre( nombre );
      player.establecerSal( salario );
      player.establecerId( numeroId );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( puesto ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &player ),
         sizeof( puesto ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}


void puesto::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el ID del puesto a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( puesto ) );

   // leer el registro del archivo
   puesto player;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );

   // eliminar el registro, si es que existe en el archivo
   if ( player.obtenerNumeroId() != 0 ) {
      puesto entrenadorEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( puesto ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( puesto ) );

      cout << "Puesto con ID #" << numeroId << " eliminado.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "No existe ningun puesto con el ID #" << numeroId<<endl;

}

void puesto::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"
       <<setw( 10 )<<"Salario"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   puesto player;
   leerDeArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( player.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(player);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &player),
         sizeof( puesto ) );

   } // fin de instrucción while

}


void puesto::mostrarLinea( ostream &salida, const puesto &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 10 ) << registro.obtenerSal()<<endl;

} // fin de la función mostrarLinea
void puesto::mostrarLineaPantalla( const puesto &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 10 ) << registro.obtenerSal()<<endl;
} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int puesto::obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

} // fin de la función obtenerCuenta
void puesto::crearArchivoPuesto()
{
    ofstream puestoSalida( "puestos.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !puestoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   puesto entrenadorEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 1000; i++ )
      puestoSalida.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( puesto ) );
}

fstream puesto::inicioArchivo(){
    puesto player;
        fstream puestoEntradaSalida( "puestos.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !puestoEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      player.crearArchivoPuesto();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return puestoEntradaSalida;
}

void puesto::busquedaRegistro(fstream &actualizarArchivo)
{

       int numeroId = obtenerId( "Escriba el ID del puesto a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( puesto ) );

   // leer el primer registro del archivo
   puesto player;
   actualizarArchivo.read( reinterpret_cast< char * >( &player ),
      sizeof( puesto ) );
if ( player.obtenerNumeroId() != 0 ) {
      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 17 ) << "Nombre"
       <<setw( 10 )<<"Salario"<< endl;
      mostrarLinea( cout, player );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( puesto ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
