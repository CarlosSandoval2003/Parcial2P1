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

