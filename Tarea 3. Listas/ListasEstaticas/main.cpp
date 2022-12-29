#include <iostream>
#include "listae.h"
#include "GatoDomestico.h"

#define T 100

using namespace std;



int main()
{
    listae milista;
    Gato migato;

    int opc;
    string nuevo;
    enum{
    OPSALIR,
    OPAGREGAR,
    OPBUSCAR,
    OPELIMINAR,
    OPINSERTAR,
    OPMOSTRAR
    };
    cout<<"Gatos del vecindario"<<endl;
    cout<<"Elija lo que desea hacer"<<endl;
    cout<<OPAGREGAR<<") Agregar"<<endl;
    cout<<OPBUSCAR<<") Buscar"<<endl;
    cout<<OPELIMINAR<<") Eliminar"<<endl;
    cout<<OPINSERTAR<<") Insertar"<<endl;
    cout<<OPMOSTRAR<<") Mostrar"<<endl;
    cout<<OPSALIR<<") Salir"<<endl;
    cin>>opc;
    switch (opc){
        case OPSALIR:
            cout<<"Gracias, hasta luego"<<endl;
        break;

        case OPAGREGAR:

            system("cls");

                        cin.ignore();
                        cout << "Propietario del Gato: ";
                        getline(cin, nuevo);
                        migato.setPropietario(nuevo);
                        cout << "Anio de nacimiento: ";
                        getline(cin, nuevo);
                        migato.setYear(nuevo);
                        cout << "Lugar de nacimiento: ";
                        getline(cin, nuevo);
                        migato.setLugar(nuevo);
                        cout << "Dieta: ";
                        getline(cin, nuevo);
                        migato.setDieta(nuevo);
                        cout << "Raza: ";
                        getline(cin, nuevo);
                        migato.setRaza(nuevo);
                        milista.add(migato);
                        //milista.imprime();

        break;

        case OPBUSCAR:

        break;
    }

//    milista.add();
    milista.imprime();
    return 0;
}
