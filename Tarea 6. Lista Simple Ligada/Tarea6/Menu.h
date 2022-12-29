#ifndef MENU_H
#define MENU_H
#include "Socio.h"
#include "Lista.h"


class Menu
{
    public:
    Menu(lista<Socio>& listaSimple){
    Interface(listaSimple);
    }
    private:
        void Interface(lista<Socio>&);
};



#endif // MENU_H
