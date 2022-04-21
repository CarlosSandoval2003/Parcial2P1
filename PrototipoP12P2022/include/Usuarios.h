#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
using namespace std;

class Usuarios
{
    public:
        Usuarios();
        virtual ~Usuarios();
        bool loginUsuarios();
        void menuUsuarios();
        string USER = "csandovalc1";
        string PASS = "25072003";
    protected:

    private:

};

#endif // USUARIOS_H
