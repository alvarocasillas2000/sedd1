#include "Materia.h"
#include <iostream>
#include <cstdio>
#include <cstring>




void Materia::Imprime(){
	cout<<"Clave de la Clase: "<<Clave<<endl;
	cout<<"\n"<<Nombre<<endl;
	cout<<"Profesor: "<<Profesor<<endl;
	cout<<"Libro de Texto: "<<LibroTexto<<endl;	
}

void Materia::CambiaProfe(){
	string nprofe;
	
	system("cls");
	cout<<"Clave de la Clase "<<Clave<<endl;
	cout<<"Profesor actual: "<<Profesor<<endl;
	cout<<"Introduzca el nuevo profesor: ";
	cin.ignore();
	getline(cin,nprofe);
	SetProfe(nprofe);
	system("cls");
	
	cout<<"\n\n\t\t같캜AMBIO REALIZADO같�\n\n";
	cout<<"Clave de la Clase: "<<Clave<<endl;
	cout<<"\t"<<Nombre<<endl;
	cout<<"Profesor: "<<Profesor<<endl;
	cout<<"Libro de Texto: "<<LibroTexto<<endl;
}

	
void Materia::CambiaClave(){
	int nclave;
	system ("cls");
	cout<<"\t"<<Nombre<<endl;
	cout<<"Clave actual de la Clase: "<<Clave<<endl;
	cout<<"Introduzca la nueva clave: ";
	cin>>nclave;
	SetClave(nclave);
	system ("cls");
	
	cout<<"\n\n\t\t같캜AMBIO REALIZADO같�\n\n";
	cout<<"Clave de la Clase: "<<Clave<<endl;
	cout<<"\t"<<Nombre<<endl;
	cout<<"Profesor: "<<Profesor<<endl;
	cout<<"Libro de Texto: "<<LibroTexto<<endl;
	
}
