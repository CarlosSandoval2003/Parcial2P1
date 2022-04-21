#include <iostream>
using namespace std;

int main()
{
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
	cout<<"\t\t\t 3. Informes"<<endl;
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
        cout<<"Menu Catalogos"<<endl;
		break;
	case 2:
        cout<<"Menu Procesos"<<endl;
		break;
	case 3:
	    cout<<"Menu Informes"<<endl;
		break;
	case 4:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 4);
    return 0;
}

