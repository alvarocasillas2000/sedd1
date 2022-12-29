#include "Socio.h"

int Socio::getNumero()const{
    return Numero;
}
int Socio::getAnio()const{
    return Anio;
}
string Socio::getNombre()const{
    return Nombre;
}
string Socio::getDomicilio()const{
    return Domicilio;
}
void Socio::setNumero(const int& num){
    Numero=num;
}
void Socio::setAnio(const int& anio){
    Anio=anio;
}
void Socio::setNombre(const string& nom){
    Nombre=nom;
}
void Socio::setDomicilio(const string& dom){
    Domicilio=dom;
}
string Socio::tostring()const{   ///Van guardandose los datos en un string y se retorna al final de la funcion :)
    string aux;
    char dat[20];
    aux+="\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-";
    aux+="\nNumero de socio: ";
    sprintf(dat,"%i",Numero);
    aux+=dat;
    aux+="\nNombre del socio: ";
    aux+=Nombre;
    aux+="\nDomicilio: ";
    aux+=Domicilio;
    aux+="\nAnio de ingreso: ";
    sprintf(dat,"%i",Anio);
    aux+=dat;
    return aux;
}
bool Socio::operator==(const Socio& a)const{
    return Numero==a.Numero;
}
bool Socio::operator!=(const Socio&a)const{
    return Numero!=a.Numero;
}
bool Socio::operator>(const Socio& a)const{
    return Numero>a.Numero;
}
bool Socio::operator>=(const Socio& a)const{
    return Anio>=a.Anio;
}
bool Socio::operator<(const Socio&a)const{
    return Numero<a.Numero;
}
bool Socio::operator<=(const Socio&a)const{
    return Anio<=a.Anio;
}
