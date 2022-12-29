#include <iostream>
#include "excepciones.hpp"
#include "Socio.h"
#ifndef LISTA_H
#define LISTA_H

using namespace std;

template <class T>
class lista{
	private:
   		class nodo{///Nodos o apuntadores
     		private:
         		T elem;		///El elemento es de tipo T, del template
         		nodo* sig;
         		nodo* ant;
     		public:
		        nodo();
		        nodo(const T&);
		        T getElem()const;
		        nodo* getSig()const;
		        nodo* getAnt()const;        ///Get anterior...
		        void setElem(const T&);
		        void setSig(nodo*);
		        void setAnt(nodo*);         ///Nueva funcion
     	};
	    nodo* ancla;
	    void copiarLista(const lista<T>& );
	    bool PosValida(nodo*)const;			///Recibe un nodo y verifica si tenemos posibilidad para usar esa direccion en memoria, de lo contrario lanza un error
 	public:
            typedef nodo* Posicion; 		///Tipo de dato para las direcciones de los nodos que se encuentran dentro de la lista
    		lista();
    		lista(const lista<T>&);
    		~lista();
    		bool Vacia()const;
    		void insertarElem(nodo* ,const T&);
    		void eliminarElem(nodo*);
    		nodo* getPrimero()const;
    		nodo* getUltimo()const;
    		nodo* getAnt(nodo *)const;
    		nodo* getSig(nodo *)const;
    		nodo* buscarElem(const T&)const;
    		nodo* verifica(const T&)const;
    		T recupera(nodo*)const;
		    string toString()const;
		    string Antiguedad(const T&)const;
		    int total()const;
		    void eliminarLista();
		    lista<T>& operator=(const lista<T>&);
} ;


template <class T>
lista<T>::~lista(){	///Destructor
    eliminarLista();
}

template <class T>
void lista<T>::copiarLista(const lista<T>& l){///Copiar elementos de la lista
    nodo* aux(l.ancla);
    nodo* ant(nullptr);
    nodo* nodo1;
    while(aux!=nullptr){
        nodo1=new nodo(aux->getElem());
        if(nodo1==nullptr){
            throw Exception("La direccion de memoria no esta disponible");
        }
        if(ant==nullptr){
            ancla=nodo1;
        }
        else{
            ant->getSig(nodo1);
        }
        ant=nodo1;
        aux=aux->getSig();
    }
}

template <class T>
bool lista<T>::PosValida(nodo* p) const{		///Funcion para saber si la posición es valida
    nodo* aux(ancla);
    while(aux!=nullptr){
        if(aux==p){
            return true;
        }
        aux=aux->getSig();
    }
    return false;
}

template <class T>                  ///constructores
lista<T>::lista(){
    nodo* ancla(nullptr);
    nodo* aux(nullptr);
    nodo* ult(nullptr);
    }						///Definimos al ancla apuntando a nullptr

template <class T>
lista<T>::lista(const lista<T>& l):ancla(nullptr){
    copiarLista(l);
}

template <class T>
bool lista<T>::Vacia()const{					///Funcion para saber si esta vacia
    return ancla==nullptr;
}

template <class T>
void lista<T>::insertarElem(nodo* p, const T& e){
    if(p!=nullptr && !PosValida(p)){
        throw Exception("Posicion invalida, insertarElem");
    }
    nodo* aux(new nodo(e));

    if(aux==nullptr){
        throw Exception("La memoria no esta disponible");
    }
    if(p==nullptr){				///Aqui se inserta al principio, si la lista esta vacia
        aux->setSig(ancla);
        ancla=aux;
    }
    else{				///Aqui se inserta en cualquier lugar
        if(getPrimero()->getElem()>e){
            aux->setSig(p);
            ancla=aux;
            return;
        }
        if(getUltimo()->getElem()<e){
            aux->setSig(getUltimo()->getSig());
            getUltimo()->setSig(aux);
            return;
        }
        while(p!=nullptr){              ///Al irlos ingresando van ordenandose
            if(p->getElem()>e){
                getAnt(p)->setSig(aux);
                aux->setSig(p);
                return;
            }
            p=p->getSig();
        }
    }
}

template <class T>
void lista<T>::eliminarElem(nodo* p){
    if(Vacia())
        throw Exception("La lista esta vacía, no se pueden eliminar elementos");
    if(!PosValida(p)){
        throw Exception("Posicion Invalida, eliminar elemento");
    }
    if(p==ancla){		///Si la posicion es igual a la de ancla, se elimina el primero
        ancla=ancla->getSig();
    }
    else{			///Si no se elimina el de la posicion indicada
        getAnt(p)->setSig(p->getSig());
    }
    delete p;
}

template <class T>
int lista<T>::total()const{				///Cuenta el numero de socios
    if(Vacia()){
        return 0;
    }
    nodo *aux (ancla);
    int cont=1;
    while(aux->getSig()!=nullptr){
        cont++;
        aux=aux->getSig();
    }
    return cont;///Retorna el contador
}

template <class T>
typename lista<T>::nodo* lista<T>::getPrimero()const{
    return ancla;			///Retorna el ancla. El primer rlemento
}

template <class T>
typename lista<T>::nodo* lista<T>::getUltimo()const{
    if(Vacia()){
        return nullptr;
    }
    nodo* aux(ancla);
    while(aux->getSig()!=nullptr){
        aux=aux->getSig();
    }
    return aux;
}

template <class T>
typename lista<T>::nodo* lista<T>::getAnt(nodo* p)const{
    if(p==ancla){           //si la posicion es la primera, regresa null
        return nullptr;
    }
    nodo* aux(ancla);
    while(aux!=nullptr && aux->getSig()!=p){
        aux=aux->getSig();
    }
    return aux;
}

template <class T>
typename lista<T>::nodo* lista<T>::getSig(nodo* p)const{
    if(Vacia())
        throw Exception("La lista esta vacía");
    if(PosValida(p)){
        return nullptr;
    }
    return p->getSig();
}

template <class T>
typename lista<T>::nodo* lista<T>::buscarElem(const T& e)const{
    nodo* aux(ancla);
    Socio aux1;
    while(aux!=nullptr){
     aux1=aux->getElem();
     if(aux1.getNombre()==e.getNombre() && aux1.getDomicilio()==e.getDomicilio()){
            return aux;
     };
     aux=aux->getSig();
    }
    return aux;
}

template <class T>
typename lista<T>::nodo* lista<T>::verifica(const T& a)const{			///Checa que no se repita el num del socio
    nodo* aux(ancla);
    while(aux!=nullptr){
        if(aux->getElem()==a){
            return aux;
        }
        aux=aux->getSig();
    }
    return aux;
}


template <class T>
T lista<T>::recupera(nodo* p)const{
	nodo *aux=new nodo();
    if(!PosValida(p)){
    	throw Exception("Posicion invalida, recupera");
    }
    return p->getElem();
}


template <class T>
string lista<T>::toString()const{					///Funcion para convertir los datos a un solo string
    nodo* aux(ancla);
    string result;
    while(aux!=nullptr){
        result+=aux->getElem().tostring()+ "\n";
        aux=aux->getSig();
    }
    return result;
}
template <class T>
string lista<T>::Antiguedad(const T& f)const{				///Funcion para mostrar la antiguedad
    nodo* aux(ancla);
    string result;
    while(aux!=nullptr){
        if(aux->getElem()<=f){
        result+=aux->getElem().tostring()+"\n";         //Muestra todos los elementos que cumplan con la condicion de la antiguedad
        }
        aux=aux->getSig();
    }
    return result;
}
template <class T>
void lista<T>::eliminarLista(){					/////Eliminar nuestra lista
    nodo* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=ancla->getSig();
        delete aux;
    }
}
template <class T>
lista<T>& lista<T>::operator=(const lista<T>& l){
    eliminarLista();
    copiarLista(l);
    return *this;
}

///La clase Nodo no cambia :)

template <class T>
lista<T>::nodo::nodo():sig(NULL){}

template <class T>
lista<T>::nodo::nodo(const T& e):elem(e), sig(NULL){}

template <class T>
T lista<T>::nodo::getElem()const{ 			//////Obtener elemento
    return elem;
}

template <class T>
typename lista<T>::nodo* lista<T>::nodo::getSig()const{			/////Obtener siguiente
    return sig;
}

template <class T>
typename lista<T>::nodo* lista<T>::nodo::getAnt()const{			/////Obtener siguiente
    return ant;
}

template <class T>
void lista<T>::nodo::setElem(const T& e){			/////Establecer elemento
    elem=e;
}

template <class T>
void lista<T>::nodo::setSig(lista<T>::nodo* p){			/////Establecer siguiente
    sig=p;
}

template <class T>
void lista<T>::nodo::setAnt(lista<T>::nodo* p){			/////Establecer siguiente
    ant=p;
}


#endif // LISTA_H
