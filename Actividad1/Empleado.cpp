#include "Empleado.h"
#include <iostream>
#include <cstdio>
#include <cstring>



void Empleado::Imprime(){
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Clave de empleado: "<<ClaveEmpleado<<endl;
	cout<<"Domicilio: "<<Domicilio<<endl;
	cout<<"Sueldo: $"<<Sueldo<<endl;
	cout<<"Reporta: "<<ReportaA<<endl;
	
}

void Empleado::CambiaDomic(){
	string ndom, ndom1;
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Domicilio actual: "<<Domicilio<<endl;
	cout<<"Introduzca el nuevo domicilio: ";
	cin.ignore();
	getline(cin,ndom);
	//cin>>ndom;
	//ndom=ndom1;
	SetDomicilio(ndom);
	system("cls");
	
	cout<<"\n\n\t\t°°°CAMBIO REALIZADO°°°\n\n";
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Clave de empleado: "<<ClaveEmpleado<<endl;
	cout<<"Domicilio: "<<Domicilio<<endl;
	cout<<"Sueldo: $"<<Sueldo<<endl;
	cout<<"Reporta: "<<ReportaA<<endl;
}

void Empleado::ActualSueldo(){
	float porcent, a, nsueldo;
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Sueldo actual: $"<<Sueldo<<endl;
	cout<<"Introduzca el porcentaje que desea aumentar: ";
	cin>>porcent;
	a=1+(porcent/100);
	nsueldo=Sueldo*a;
	SetSueldo(nsueldo);
	system("cls");
	cout<<"\n\n\t\t°°°CAMBIO REALIZADO°°°\n\n";
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Clave de empleado: "<<ClaveEmpleado<<endl;
	cout<<"Domicilio: "<<Domicilio<<endl;
	cout<<"Sueldo: $"<<Sueldo<<endl;
	cout<<"Reporta: "<<ReportaA<<endl;
}

void Empleado::CambiaReportaA(){
	string nreporta;
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Reporta actual: "<<ReportaA<<endl;
	cout<<"Introduzca el nuevo reporta: ";
	cin.ignore();
	getline(cin,nreporta);
	SetReportaA(nreporta);
	system("cls");
	
	cout<<"\n\n\t\t°°°CAMBIO REALIZADO°°°\n\n";
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Clave de empleado: "<<ClaveEmpleado<<endl;
	cout<<"Domicilio: "<<Domicilio<<endl;
	cout<<"Sueldo: $"<<Sueldo<<endl;
	cout<<"Reporta: "<<ReportaA<<endl;
}

