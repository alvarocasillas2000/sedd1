#ifndef GATO_H
#define GATO_H
#include <string>
#include <iostream>

using namespace std;

class Gato
{
private:
    string Dieta;
    string Year;
    string Lugar;
    string Raza;
    string Propietario;
public:
    Gato();
    Gato(string dieta, string year, string lugar, string raza, string propietario){
    Dieta = dieta;
    Year = year;
    Lugar = lugar;
    Raza = raza;
    Propietario = propietario;
    }

    void setDieta(string dieta){
        Dieta = dieta;
    }
     void setYear(string year){
        Year = year;
    }
    void setLugar(string lugar){
        Lugar = lugar;
    }
    void setRaza(string raza){
        Raza = raza;
    }
    void setPropietario(string propietario){
        Propietario = propietario;
    }

    bool operator<<(Gato& g);
    //Gato<<g;
};

#endif // GATO_H
