#include <iostream>
#include "Socio.h"
#include "excepciones.hpp"
#include "Lista.h"

using namespace std;

int main()
{
    lista<Socio> miLista;
    string datos, auxNombre, auxDom;
	int dato, anio;
	lista<Socio>::Posicion pos;
	Socio s;
	int opc=1;
	while(opc!=0){
	    system("cls");
	    cout<<"°°°LISTA DINAMICA DOBLEMENTE LIGADA CIRCULAR°°°\n\n";
	    cout<<"_____________________________________"<<endl;
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
	    system("cls");
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
	        pos=miLista.verifica(s);
	        while(pos!=nullptr){
	            cout<<"\nEl numero de socio que desea utilizar no esta disponible"<<endl;
	            cout<<"Ingrese otro numero de socio: ";
	            cin>>dato;
	            s.setNumero(dato);
	            pos=miLista.verifica(s);
	        }
	        miLista.insertarElem(miLista.getPrimero(), s);
	        cout<<"°°°Nuevo socio registrado con exito°°°"<<endl;
	        system("PAUSE");
	    break;
	    case 2:
	    system("cls");
            if(miLista.Vacia())
                cout<<"Lista sin datos, no se puede eliminar"<<endl;
            else{
	        cout<<"Introduzca el nombre del socio que desea dar de baja: \n\t";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Introduza el domicilio: \n\t";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=miLista.buscarElem(s);
	        if(pos!=nullptr){
		        cout<<"\n °°°Socio Localizado°°° "<<endl;
		        cout<<miLista.recupera(pos).tostring();
		        cout<<"\n\n\n°°°Baja de Socio exitosa°°°"<<endl;
		        miLista.eliminarElem(pos);
		        cout<<endl;
	        }
	        else{
	            cout<<"\nNo se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        cout<<endl;
            }
	        system("PAUSE");
	    break;
	    case 3:
	    system("cls");
            if(miLista.Vacia())
                cout<<"Lista sin datos, no hay usuarios registrados"<<endl;
            else{
	        cout<<endl;
	        cout<<miLista.toString()<<endl;
	        cout<<endl;
            }
	        system("PAUSE");
	    break;
	    case 4:
	    system("cls");
            if(miLista.Vacia())
                cout<<"Lista sin datos, no hay usuarios registrados"<<endl;
            else{
	        anio=2022;
	        cout<<"\nIngrese los anios de antiguedad";
	        cin>>dato;
	        anio=anio-dato;
	        s.setAnio(anio);
	        cout<<"\nSocios con antiguedad de"<<dato<<" anios"<<endl;
	        cout<<miLista.Antiguedad(s)<<endl;
            }
	        system("PAUSE");
	    break;
	    case 5:
	    system("cls");
            if(miLista.Vacia())
                cout<<"Lista sin datos, no puede realizarse el cambio"<<endl;
            else{
            cout<<"Introduzca el nombre del socio\n\t";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Escriba el domicilio del socio\n\t";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=miLista.buscarElem(s);
	        if(pos==nullptr){
	                cout<<"\nNo se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        else{
	            cout<<"\n °°°Socio Localizado°°° \n"<<endl;
	            cout<<"\nIngrese el nuevo domicilio del socio: ";
	            fflush(stdin);
	            getline(cin,auxDom);
	            s.setDomicilio(auxDom);
	            s.setNombre(miLista.recupera(pos).getNombre());
				s.setAnio(miLista.recupera(pos).getAnio());
	            s.setNumero(miLista.recupera(pos).getNumero());
	            miLista.eliminarElem(pos);
	            miLista.insertarElem(miLista.getPrimero(),s);
	            cout<<endl<<miLista.recupera(pos).tostring()<<endl;
	        }
	        cout<<"\n"<<endl;
            }
	        system("PAUSE");
	    break;
	    case 6:
	    system("cls");
            if(miLista.Vacia())
                cout<<"Lista sin datos, no se puede buscar el Socio"<<endl;
            else{
            cout<<"Escriba el nombre del socio a buscar: ";
            fflush(stdin);
	        getline(cin,auxNombre);
	        s.setNombre(auxNombre);
            cout<<"Escriba el domicilio del socio a buscar: ";
            fflush(stdin);
	        getline(cin,auxDom);
	        s.setDomicilio(auxDom);
	        pos=miLista.buscarElem(s);
	        if(pos==nullptr){
	            cout<<"No se encontraron coincidencias. Por favor intente de nuevo.";
	        }
	        else{
	            cout<<endl<<"°°°Socio Localizado°°°\n"<<endl;
	            cout<<miLista.recupera(pos).tostring();
	        }
	        cout<<endl;
            }
	        system("PAUSE");
	    break;
	    case 7:
	    system("cls");
            if(miLista.Vacia())
                cout<<"La lista no tiene socios registrados"<<endl;
            else{
	        cout<<miLista.toString()<<endl;
	        dato=miLista.total();
	        cout<<"El numero de socios registrados es de "<<dato<<" socios"<<endl;
	        cout<<endl;
	        system("PAUSE");
	    break;
	    default:
	    	cout<<"Opcion inexistente o erronea"<<endl;
            }
	    	system("PAUSE");
	    break;
	    }
    }
}
