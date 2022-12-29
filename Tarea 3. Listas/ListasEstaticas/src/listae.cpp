#include <iostream>
#include "listae.h"
#include "Gato.h"
#define T 50

using namespace std;

listae::listae() : ultimo(-1) {}

int listae::ultimoo()
{
    return ultimo;
}

/*int busca(Gato sear){
    for(int i=0; i <= ultimo; i++){
        if(datos[i] == sear)
            return i;
    }
    return -1;
}*/

bool listae::vacia(){
    if(ultimo == -1)
        return true;
    return false;
}

bool listae::llena(){
    if(ultimo == T - 1)
        return true;
    return false;
}


bool listae::inserta(const int& posicion, const Gato& elem){
    if (llena() || posicion < 0 || posicion > ultimo + 1){
        return false;
    }
    int i = ultimo +1;
    while (i > posicion){
        datos[i] = datos[i - 1];
		i--;
	}
	datos[posicion] = elem;
	ultimo++;
	return true;
    }

bool listae::add(const Gato& elem){
    int posicion = ultimo + 1;
    if (llena() || posicion < 0 || posicion > ultimo + 1){
        return false;
    }

    int i = ultimo +1;
    while (i > posicion){
        datos[i] = datos[i - 1];
		i--;
	}
	datos[posicion] = elem;
	ultimo++;
	return true;
}

bool listae::elimina(const int& posicion){
	if(vacia() || posicion < 0 || posicion > ultimo )
		return false;
	int i=posicion;
	while (i<ultimo){
		datos[i] = datos[i+1];
		i++;
	}
	ultimo--;
	return true;
}

string listae::imprime(){
    if(vacia() )
		cout<< "lista vacia"<<endl;
    int i;
    for(i=0; i<=ultimo; i++){
        return toString(i);
    }
}
string toString(){

string x=Gato.getPropietario()+","+gato.getDieta()+",";

return x;
}

