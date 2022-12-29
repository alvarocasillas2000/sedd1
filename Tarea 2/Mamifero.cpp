#include <iostream>
#include <cstring>
#include <cstdio>
#include "Mamifero.h"

using namespace std;

void Mamifero::PrintDiet(){
	cout<<Name<<endl;
	cout<<"Dieta: "<<Diet<<"\n"<<endl;
};

void Mamifero::PrintYearPlace(){
	cout<<Name<<endl;
	cout<<"Anio de nacimiento: "<<Year<<endl;
	cout<<"Lugar de nacimiento: "<<Place<<"\n"<<endl;
}

void GatoDomestico::ChangeOwner(){
	string newowner;
	cout<<Name<<endl;
	cout<<"Propietario actual: "<<Owner<<endl;
	cout<<"Introduzca el nuevo propietario:\n\n\t"<<endl;
	cin.ignore();
	getline(cin,newowner);
	SetOwner(newowner);
	system("cls");
	
	cout<<"\n\n\t\t같캜AMBIO REALIZADO같�\n\n";
	cout<<Name<<endl;
	cout<<"Propietario: "<<Owner<<endl;
	cout<<"Anio de nacimiento: "<<Year<<endl;
	cout<<"Lugar de nacimiento: "<<Place<<endl;
	cout<<"Dieta: "<<Diet<<"\n"<<endl;
}

void Mamifero::PrintRaza(){
	cout<<Name<<endl;
	cout<<"Raza: "<<Raza<<"\n"<<endl;
}

void Felino::ChangeCircus(){
	string newcircus;
	cout<<Name<<endl;
	cout<<"Circo actual: "<<Circus<<endl;
	cout<<"Introduzca el nuevo circo:\n\n\t"<<endl;
	cin.ignore();
	getline(cin,newcircus);
	SetCircus(newcircus);
	system("cls");
	
	cout<<"\n\n\t\t같캜AMBIO REALIZADO같�\n\n";
	cout<<Name<<endl;
	cout<<"Circo: "<<Circus<<endl;
	cout<<"Anio de nacimiento: "<<Year<<endl;
	cout<<"Lugar de nacimiento: "<<Place<<endl;
	cout<<"Dieta: "<<Diet<<"\n"<<endl;
	
}


