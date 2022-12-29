#include <iostream>

#ifndef SOCIO_H
#define SOCIO_H


using namespace std;


class Socio
{
    private:

	    int Numero;
	    int Anio;
	    string Nombre;
	    string Domicilio;

	public:

	    int getNumero()const;           ///Setters y Getters
	    int getAnio()const;
	    string getNombre()const;
	    string getDomicilio()const;

	    void setNumero(const int&);
	    void setAnio(const int&);
	    void setNombre(const string&);
	    void setDomicilio(const string&);

	    string tostring()const;  ///Para imprimir

	    bool operator==(const Socio&)const;
	    bool operator!=(const Socio&)const;
	    bool operator>(const Socio&)const;
	    bool operator>=(const Socio&)const;
	    bool operator<(const Socio&)const;
	    bool operator<=(const Socio&)const;
	    friend ostream& operator<<(ostream&, Socio&);
	    friend istream& operator>>(istream&, Socio&);///Sobrecarga de operadores
};

#endif // SOCIO_H
