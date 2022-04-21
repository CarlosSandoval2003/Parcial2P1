#include <iostream>
#include "menus.h"
#include "equipos.h"
#include "jugador.h"
#include "entrenador.h"
#include "puesto.h"
#include "pais.h"
using namespace std;

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}

menus::menuGeneral(){

int choice;
	char x;
	do
    {
	system("cls");
	cout<<"Carlos Javier Sandoval Catalan"<<endl;
	cout<<"Carnet No. 9959-21-1324"<<endl;
	cout<<"\t\t\t    CORPORACION DE DEPORTES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Procesos"<<endl;
	cout<<"\t\t\t 3. Reportes"<<endl;
	cout<<"\t\t\t 4. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        menuCatalogos();
		break;
	case 2:
	    menuProcesos();
		break;
	case 3:
	    menuReportes();
		break;
	case 4:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 4);
    return 0;

}

menus::menuCatalogos(){

int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    CATALOGOS     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Paises"<<endl;
	cout<<"\t\t\t 2. Puestos"<<endl;
	cout<<"\t\t\t 3. Equipos"<<endl;
	cout<<"\t\t\t 4. Jugadores"<<endl;
	cout<<"\t\t\t 5. Entrenadores"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        catalogoPaises();
		break;
	case 2:
        catalogoPuestos();
		break;
	case 3:
	    catalogoEquipos();
		break;
	case 4:
	    catalogoJugadores();
        break;
    case 5:
	    catalogoEntrenadores();
        break;
    case 6:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 6);
    return 0;

}

menus::menuProcesos()
    {
    equipos team;
    fstream equiposEntradaSalida = team.inicioArchivo();
    jugador player;
    fstream jugadorEntradaSalida = player.inicioArchivo();
    entrenador trainer;
    fstream entrenadorEntradaSalida = trainer.inicioArchivo();
    puesto puest;
    fstream puestoEntradaSalida = puest.inicioArchivo();
    pais p1;
    fstream paisEntradaSalida = p1.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    PROCESOS     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Equipos"<<endl;
	cout<<"\t\t\t 2. Consulta Jugadores"<<endl;
	cout<<"\t\t\t 3. Consulta Entrenadores"<<endl;
	cout<<"\t\t\t 4. Consulta Puestos"<<endl;
    cout<<"\t\t\t 5. Consulta Paises"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        team.consultarRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        player.consultarRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    trainer.consultarRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    puest.consultarRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 5:
        p1.consultarRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    equiposEntradaSalida.clear();
    jugadorEntradaSalida.clear();
    entrenadorEntradaSalida.clear();
    puestoEntradaSalida.clear();
    paisEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;

}

menus::menuReportes(){

    equipos team;
    fstream equiposEntradaSalida = team.inicioArchivo();
    jugador player;
    fstream jugadorEntradaSalida = player.inicioArchivo();
    entrenador trainer;
    fstream entrenadorEntradaSalida = trainer.inicioArchivo();
    puesto puest;
    fstream puestoEntradaSalida = puest.inicioArchivo();
    pais p1;
    fstream paisEntradaSalida = p1.inicioArchivo();


int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    REPORTES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Paises"<<endl;
	cout<<"\t\t\t 2. Puestos"<<endl;
	cout<<"\t\t\t 3. Equipos"<<endl;
	cout<<"\t\t\t 4. Jugadores"<<endl;
	cout<<"\t\t\t 5. Entrenadores"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        p1.imprimirRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout<<"Reporte de paises impreso satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        puest.imprimirRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout<<"Reporte de puestos impreso satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    team.imprimirRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout<<"Reporte de equipos impreso satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    player.imprimirRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout<<"Reporte de jugadores impreso satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
	case 5:
        trainer.imprimirRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout<<"Reporte de entrenadores impreso satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    equiposEntradaSalida.clear();
    jugadorEntradaSalida.clear();
    entrenadorEntradaSalida.clear();
    puestoEntradaSalida.clear();
    paisEntradaSalida.clear();
    getch();
    }while(choice!= 6);
    return 0;

}

menus::catalogoEquipos()
{
    equipos team;
    fstream equiposEntradaSalida = team.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    EQUIPOS     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultar"<<endl;
	cout<<"\t\t\t 2. Agregar"<<endl;
	cout<<"\t\t\t 3. Eliminar"<<endl;
	cout<<"\t\t\t 4. Modificar"<<endl;
    cout<<"\t\t\t 5. Buscar"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        team.consultarRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        team.nuevoRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout<<"Equipo agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    team.eliminarRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    team.actualizarRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout<<"Equipo modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 5:
        team.busquedaRegistro(equiposEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    equiposEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;



}


menus::catalogoJugadores()
{
    jugador player;
    fstream jugadorEntradaSalida = player.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    JUGADORES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultar"<<endl;
	cout<<"\t\t\t 2. Agregar"<<endl;
	cout<<"\t\t\t 3. Eliminar"<<endl;
	cout<<"\t\t\t 4. Modificar"<<endl;
    cout<<"\t\t\t 5. Buscar"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        player.consultarRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        player.nuevoRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout<<"Jugador agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    player.eliminarRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    player.actualizarRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout<<"Jugador modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 5:
        player.busquedaRegistro(jugadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    jugadorEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;



}


menus::catalogoEntrenadores()
{
    entrenador player;
    fstream entrenadorEntradaSalida = player.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    ENTRENADORES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultar"<<endl;
	cout<<"\t\t\t 2. Agregar"<<endl;
	cout<<"\t\t\t 3. Eliminar"<<endl;
	cout<<"\t\t\t 4. Modificar"<<endl;
    cout<<"\t\t\t 5. Buscar"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        player.consultarRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        player.nuevoRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout<<"Entrenador agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    player.eliminarRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    player.actualizarRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout<<"Entrenador modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 5:
        player.busquedaRegistro(entrenadorEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    entrenadorEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;

}


menus::catalogoPuestos()
{
    puesto player;
    fstream puestoEntradaSalida = player.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    PUESTOS     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultar"<<endl;
	cout<<"\t\t\t 2. Agregar"<<endl;
	cout<<"\t\t\t 3. Eliminar"<<endl;
	cout<<"\t\t\t 4. Modificar"<<endl;
    cout<<"\t\t\t 5. Buscar"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        player.consultarRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        player.nuevoRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout<<"Puesto agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    player.eliminarRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    player.actualizarRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout<<"Puesto modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 5:
        player.busquedaRegistro(puestoEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    puestoEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;

}

menus::catalogoPaises()
{
    pais p1;
    fstream paisEntradaSalida = p1.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t    PAISES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultar"<<endl;
	cout<<"\t\t\t 2. Agregar"<<endl;
	cout<<"\t\t\t 3. Eliminar"<<endl;
	cout<<"\t\t\t 4. Modificar"<<endl;
    cout<<"\t\t\t 5. Buscar"<<endl;
    cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        p1.consultarRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        p1.nuevoRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout<<"Pais agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 3:
	    p1.eliminarRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    p1.actualizarRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout<<"Pais modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 5:
        p1.busquedaRegistro(paisEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
        break;
    case 6:
        cout<<"Presione Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    paisEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 6);
    return 0;

}
