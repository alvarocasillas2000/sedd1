#include <iostream>
#include <cstring>
#include <cstdio>
#include "Empleado.h"


using namespace std;


int main()
{

	Empleado JefePlanta = Empleado(1111, "Isaac Martinez", "Perro 79", 1200, "Alvaro Casillas");
	Empleado JefePersonal = Empleado(1112, "Emmanuel Magana", "Gato 215", 2522.14, "Alvaro Casillas");
	int opcion, clav, resp;
do{
	
	system("cls");
	cout<<"\n\t\t°°°CLASE EMPLEADO v1.O°°°"<<endl;
	cout<<"---------------------------------------------------------\n\n"<<endl;
	cout<<"\t\tElija la funcion que desee realizar:\n"<<endl;
	cout<<"\t1. Cambiar de Domicilio"<<endl;
	cout<<"\t2. Actualizar el Sueldo"<<endl;
	cout<<"\t3. Mostrar los datos de un empleado"<<endl;
	cout<<"\t4. Cambiar nombre de quien reporta\n"<<endl;

	cin>>opcion;
	system ("cls");
	switch(opcion){
		case 1:
			cout<<"Introduzca la Clave de Empleado: "<<endl;
			//getline(cin, variable)
			cin>>clav;
			if (clav == JefePlanta.GetClaveEmpleado())
			{
				system ("cls");
				JefePlanta.CambiaDomic();
			}
			else if (clav == JefePersonal.GetClaveEmpleado())//cin.ignore
			{
				system ("cls");
				JefePersonal.CambiaDomic();
			}
			else
				cout<<"El empleado no existe"<<endl;
		break;
		case 2:
			cout<<"Introduzca la Clave de Empleado: "<<endl;
			cin>>clav;
			if (clav == JefePlanta.GetClaveEmpleado())
			{
				system ("cls");
				JefePlanta.ActualSueldo();
			}
			else if (clav == JefePersonal.GetClaveEmpleado())//cin.ignore
			{
				system ("cls");
				JefePersonal.ActualSueldo();
			}
			else
				cout<<"El empleado no existe"<<endl;
		break;
		case 3: 
			cout<<"Introduzca la Clave de Empleado: "<<endl;
			cin>>clav;
			if (clav == JefePlanta.GetClaveEmpleado())
			{
				system ("cls");
				JefePlanta.Imprime();
			}
			else if (clav == JefePersonal.GetClaveEmpleado())//cin.ignore
			{
				system ("cls");
				JefePersonal.Imprime();
			}
			else
				cout<<"El empleado no existe"<<endl;
		break;
		case 4: 
			cout<<"Introduzca la Clave de Empleado: "<<endl;
			cin>>clav;
			if (clav == JefePlanta.GetClaveEmpleado())
			{
				system ("cls");
				JefePlanta.CambiaReportaA();
			}
			else if (clav == JefePersonal.GetClaveEmpleado())//cin.ignore
			{
				system ("cls");
				JefePersonal.CambiaReportaA();
			}
			else
				cout<<"El empleado no existe"<<endl;
		break;
		default:
			cout<<"La operación que desea realizar no existe"<<endl;
	}

	cout<<"Desea regresar al menu?\n"<<endl;
	cout<<"\t1=Si\t2=No\n\t";

	cin>>resp;
}while (resp==1);	
	return 0;
}
