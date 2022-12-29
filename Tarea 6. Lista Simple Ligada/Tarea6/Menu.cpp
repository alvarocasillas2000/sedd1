#include <iostream>
#include "Menu.h"
#include "Socio.h"
#include "Lista.h"
#include "listexception.hpp"

using namespace std;

void Menu::Interface(lista<Socio>& listaSimple){
	string datos, auxNombre, auxDom;
	int dato, anio;
	lista<Socio>::Posicion pos;
	Socio s;
	int opc=1;
	while(opc!=0){
	    system("cls");
	    cout<<"°°°LISTA DINAMICA SIMPLEMENTE LIGADA°°°\n\n";
	    cout<<"_____________________________________";
	    cout<<"|        1.Agregar un socio          |"<<endl;
		cout<<"|        2.Eliminar un socio         |"<<endl;
		cout<<"|    3.Imprimir la lista de socios   |"<<endl;
		cout<<"|       4.Buscar por antiguedad      |"<<endl;
		cout<<"|         5.Cambiar domicilio        |"<<endl;
		cout<<"|            6.Buscar socio          |"<<endl;
		cout<<"|          7.Total de socios         |"<<endl;
		cout<<"|               0.Salir              |"<<endl;
	    cout<<"_____________________________________\n\n";
	    cout<<"Elija una opcion: ";
	    cin>>opc;
	    switch(opc){
	    case 0:
	    break;
	    case 1:
	        cout<<"Nombre del socio: ";
	        fflush(stdin);
	        getline(cin,datos);
	        s.setNombre(datos);
	        cout<<"Domicilio del socio: ";
	        fflush(stdin);
	        getline(cin,datos);
	        s.setDomicilio(datos);
	        cout<<"Numero de socio: ";
	        cin>>dato;
	        s.setNumero(dato);
	        cout<<"Anio de ingreso: ";
	        cin>>dato;
	        s.setAnio(dato);
	        pos=listaSimple.verifica(s);
	        while(pos!=nullptr){
	            cout<<"\nEl numero de socio que desea utilizar no esta disponible"<<endl;
	            cout<<"Ingrese otro numero de socio: ";
	            cin>>dato;
	            s.setNumero(dato);
	            pos=listaSimple.verifica(s);
	        }
	        listaSimple.insertarElem(listaSimple.getPrimero(), s);
	        cout<<"°°°Nuevo socio registrado con exito°°°"<<endl;
	        system("PAUSE");
	    break;
	    case 2:
	        cout<<"Introduzca el nombre del socio que desea dar de baja: \n\t";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Introduza el domicilio: \n\t";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=listaSimple.buscarElem(s);
	        if(pos!=nullptr){
		        cout<<"\n °°°Socio Localizado°°° "<<endl;
		        cout<<listaSimple.recupera(pos).tostring();
		        cout<<"\n\n\n°°°Baja de Socio exitosa°°°"<<endl;
		        listaSimple.eliminarElem(pos);
		        cout<<endl;
	        }
	        else{
	            cout<<"\nNo se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        cout<<endl;
	        system("PAUSE");
	    break;
	    case 3:
	        cout<<endl;
	        cout<<listaSimple.toString()<<endl;
	        cout<<endl;
	        system("PAUSE");
	    break;
	    case 4:
	        anio=2022;
	        cout<<"\nIngrese los anios de antiguedad";
	        cin>>dato;
	        anio=anio-dato;
	        s.setAnio(anio);
	        cout<<"\nSocios con antiguedad de"<<dato<<" anios"<<endl;
	        cout<<listaSimple.Antiguedad(s)<<endl;
	        system("PAUSE");
	    break;
	    case 5:
            cout<<"Introduzca el nombre del socio\n\t";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Escriba el domicilio del socio\n\t";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=listaSimple.buscarElem(s);
	        if(pos==nullptr){
	                cout<<"\nNo se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        else{
	            cout<<"\n °°°Socio Localizado°°° \n"<<endl;
	            cout<<"\nIngrese el nuevo domicilio del socio: ";
	            fflush(stdin);
	            getline(cin,auxDom);
	            s.setDomicilio(auxDom);
	            s.setNombre(listaSimple.recupera(pos).getNombre());
				s.setAnio(listaSimple.recupera(pos).getAnio());
	            s.setNumero(listaSimple.recupera(pos).getNumero());
	            listaSimple.eliminarElem(pos);
	            listaSimple.insertarElem(listaSimple.getPrimero(),s);
	            cout<<endl<<listaSimple.recupera(pos).tostring()<<endl;
	        }
	        cout<<"\n"<<endl;
	        system("PAUSE");
	    break;
	    case 6:
            cout<<"Escriba el nombre del socio a buscar: ";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Escriba el domicilio del socio a buscar: ";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=listaSimple.buscarElem(s);
	        if(pos==nullptr){
	            cout<<"No se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        else{
	            cout<<endl<<"°°°Socio Localizado°°°\n"<<endl;
	            cout<<listaSimple.recupera(pos).tostring();
	        }
	        cout<<endl;
	        system("PAUSE");
	    break;
	    case 7:
	        cout<<listaSimple.toString()<<endl;
	        dato=listaSimple.total();
	        cout<<"El numero de socios registrados es de "<<dato<<" socios"<<endl;
	        cout<<endl;
	        system("PAUSE");
	    break;
	    default:
	    	cout<<"Opcion inexistente o erronea"<<endl;
	    	system("PAUSE");
	    break;
	    }
    }
}
