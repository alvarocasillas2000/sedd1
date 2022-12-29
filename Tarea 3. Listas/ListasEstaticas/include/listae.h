#include <iostream>
#include <string>
#ifndef LISTAE_H
#define LISTAE_H
#include "Gato.h"
#define T 50

using namespace std;


class listae
{
    public:
        listae();
        bool vacia();//hecha
        bool llena();//hecha
		bool inserta(const int&, const Gato&);//cualquier posicion
		bool elimina(const int&);
		bool add(const Gato&);//al final
		std::string imprime();
		int busca(const string);
		int ultimoo();
		string toString(const int&);

    private:
        int ultimo;
        Gato datos[T];
};

#endif // LISTAE_H
