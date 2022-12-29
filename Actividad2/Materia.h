#ifndef MATERIA_H
#define MATERIA_H
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Materia
{	
	private://Atributos del objeto
		int Clave;
		string Nombre;
		string Profesor;
		string LibroTexto;
		
	public:
		Materia(){//constructor por default
			Clave=0;
			Nombre = "";
			Profesor = "";
			LibroTexto = "";
		}
		Materia(int clave, string nombre, string profesor, string librotexto){//constructor con parametros
			Clave = clave;
			Nombre = nombre;
			Profesor = profesor;
			LibroTexto = librotexto;
		}
		
		void Imprime();
		void CambiaClave();
		void CambiaProfe();
		
		SetClave(int nclav){
			Clave = nclav;
		}
		
		SetProfe(string nprofe){
			Profesor = nprofe;
		}
		
		int GetClave(){
			return Clave;
		}
};

#endif
