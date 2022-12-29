#include <iostream>
#include <cstring>
#include <cstdio>
#include "Materia.h"
using namespace std;

int main() {
	
	Materia Programacion = Materia(4455, "Programacion", "Yezael Gomez", "Programacion en C");
	Materia BasesDatos = Materia(5566, "Bases de Datos", "Yair Ochoa", "Bases de Datos para Computacion");
	int opcion, clav, resp;
	
	do{
		system("cls");
		cout<<"\n\t\t°°°CLASE MATERIA v1.O°°°"<<endl;
		cout<<"---------------------------------------------------------\n\n"<<endl;
		cout<<"\t\tElija la funcion que desee realizar:\n"<<endl;
		cout<<"\t1. Cambiar la clave de la materia de Programacion"<<endl;
		cout<<"\t2. Actualizar el profesor de Bases de Datos"<<endl;
		cout<<"\t3. Mostrar los datos de la materia Bases de Datos"<<endl;
	
		cin>>opcion;
		system ("cls");
		switch(opcion){
			case 1: 
				system ("cls");
				Programacion.CambiaClave();
			break;
			case 2:
				system ("cls");
				BasesDatos.CambiaProfe();
			break;
			case 3: 
				system ("cls");
				BasesDatos.Imprime();
			break;
			default:
				system ("cls");
				cout<<"La operación que desea realizar no existe"<<endl;
			break;
		}
		cout<<"Desea regresar al menu?\n"<<endl;
		cout<<"\t1=Si\t2=No\n\t";
		cin>>resp;
		
	}while (resp==1);
	
return 0;
}
