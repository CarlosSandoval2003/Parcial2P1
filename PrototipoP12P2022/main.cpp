#include <iostream>
#include "menus.h"
#include "Usuarios.h"
using namespace std;

int main()
{
    menus menuG;
    bool accesoUsuarios;
    Usuarios usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
    if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"** REGRESE PRONTO **";
    return 0;


}

