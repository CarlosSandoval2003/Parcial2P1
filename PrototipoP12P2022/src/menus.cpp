#include <iostream>
#include "menus.h"
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
    cout<<"\t\t\t 5. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        cout<<"Catalogo Paises"<<endl;
		break;
	case 2:
        cout<<"Catalogo Puestos"<<endl;
		break;
	case 3:
	    cout<<"Catalogo Equipos"<<endl;
		break;
	case 4:
	    cout<<"Catalogo Jugadores"<<endl;
        break;
    case 5:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 5);
    return 0;

}

menus::menuProcesos()
    {
	system("cls");
	cout<<"\t\t\t    PROCESOS     "<<endl;
	cout<<"\t\t\t"<<endl;

}

menus::menuReportes(){

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
    cout<<"\t\t\t 5. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        cout<<"Reporte Paises"<<endl;
		break;
	case 2:
        cout<<"Reporte Puestos"<<endl;
		break;
	case 3:
	    cout<<"Reporte Equipos"<<endl;
		break;
	case 4:
	    cout<<"Reporte Jugadores"<<endl;
        break;
    case 5:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 5);
    return 0;

}




