#include <iostream>
#include <string>

#ifndef MAMIFERO_H
#define MAMIFERO_H

using namespace std;



class Mamifero
{
    protected://Atributos que pueden heredarse
		string Name;
		string Diet;
		int Year;
		string Place;
		string Raza;
	public://Metodos
		Mamifero(string _name, string _diet, int _year, string _place, string _raza){//Constructor con parametros
			Name = _name;
			Diet = _diet;
			Year = _year;
			Place = _place;
			Raza = _raza;
		}

		void PrintDiet();
		void PrintYearPlace();
		void PrintRaza();

    private:
};

class Felino: public Mamifero //Clase hija de mamifero
{
	private:
		string Circus;
	public:
		Felino(string _name, string _diet, int _year, string _place, string _raza, string _circus): Mamifero(_name, _diet, _year, _place, _raza){//Constructor con parametros
			Circus = _circus;
		}
		void ChangeCircus();

	SetCircus(string newcircus){
			Circus=newcircus;
	}
};


class GatoDomestico: public Felino //Clase hija de felino
{
	private:
		string Owner;
	public:
		GatoDomestico(string _name, string _diet, int _year, string _place, string _raza, string _circus, string _owner): Felino(_name, _diet, _year, _place, _raza, _circus){
			Owner = _owner;
		}
		void ChangeOwner();

	SetOwner(string newowner){
			Owner=newowner;
		}

};

#endif // MAMIFERO_H
