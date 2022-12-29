#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Empleado
{
	

private://atributos del objeto
	int ClaveEmpleado;
	string Nombre;
	string Domicilio;
	float Sueldo;
	string ReportaA;
public: //metodos, acciones del objeto
//	Empleado(int, string, string, float, string);
	void Imprime();
	void CambiaDomic();
	void CambiaReportaA();
	void ActualSueldo();
	
	SetClaveEmpleado(int clav){
		ClaveEmpleado=clav;	
	}
	string SetNombre;
	SetDomicilio(string ndom){
		Domicilio=ndom;
	}
	float SetSueldo(float nsueldo){
		Sueldo=nsueldo;
	}
	string SetReportaA(string nreporta){
		ReportaA=nreporta;
	}
	
	int GetClaveEmpleado(){
		return ClaveEmpleado;
	}
	

	Empleado(){//constructor por default se llama cuando no le pones parametros
		ClaveEmpleado = 0;
		Nombre = "";
		Domicilio = "";
		Sueldo = 0;
		ReportaA = "";	
	}
	
	//constructor con parámetros. al declarar el objeto 
	//pueden tenerse varios pero deben tener diferente firma, osea parametros entre parentesis
	Empleado(int _ClaveEmpleado, string _Nombre, string _Domicilio, float _Sueldo, string _ReportaA){
		ClaveEmpleado = _ClaveEmpleado;
		Nombre = _Nombre;
		Domicilio = _Domicilio;
		Sueldo = _Sueldo;
		ReportaA = _ReportaA;
	}

	

};




#endif
