#include <iostream>
#include <Lista.h>


using namespace std;
int res;

int main()
{

    Lista<persona> Milista;
    persona P;
    res=1;
    enum{
    OpSalir,
    OpInsertar,
    OpEliminar,
    OpModificar,
    OpImprimir,
    OpBuscar,
    OpOrdenar
    };
    enum{
        OpcSalir,
        OpcLineal,
        OpcBinaria
    };
    enum{
        OSalir,
        OBubble,
        OBBubble,
        OShell,
        OInsert,
        OQuick
    };
    bool ordenado = false;
    do{
        int op;
        int pos;
        int opcord;
        string buscar;

        system("cls");
        cout<<"\t\t°°°Busquedas y ordenamientos°°°\n"<<endl;
        cout<<"\t"<<OpInsertar<<") Insertar"<<endl;
        cout<<"\t"<<OpEliminar<<") Eliminar"<<endl;
        cout<<"\t"<<OpModificar<<") Modificar"<<endl;
        cout<<"\t"<<OpImprimir<<") Imprimir"<<endl;
        cout<<"\t"<<OpBuscar<<") Buscar"<<endl;
        cout<<"\t"<<OpOrdenar<<") Ordenar"<<endl;
        cout<<"\t"<<OpSalir<<") Salir"<<endl;
        cin>>op;

        switch(op){
        case OpSalir:
            res=0;
            cout<<"De nada, vuelva pronto";
        break;
        case OpInsertar:
            system("cls");
            cout<<"\t\t°°°Insertar nuevo elemento°°°\n\n";
            cin>>P;
            Milista.inserta(P, Milista.Ultimo()+1);
                ordenado = false;
        break;
        case OpEliminar:
            int vis;
            system("cls");
            cout<<"\t\t°°°Eliminar un elemento°°°\n\n";
            cout<<"Desea visualizar antes la lista?"<<endl;
            cout<<"1 = Si  2 = No"<<endl;
            cin>>vis;
            if(vis==1)
                Milista.imprime();
            cout<<"\n\nInsertar la posicion a eliminar: ";
            cin>>pos;
            Milista.eliminar(pos);
            cout<<"Eliminado con exito";
        break;
        case OpModificar:
            system("cls");
            cout<<"\t\t°°°Modificar un elemento°°°\n\n";
            cout<<"Desea visualizar antes la lista?"<<endl;
            cout<<"1 = Si  2 = No"<<endl;
            cin>>vis;
            if(vis==1)
                Milista.imprime();
            cout<<"\n\nInsertar la posicion a modificar: ";
            cin>>pos;
            Milista.eliminar(pos);
            cin>>P;
            Milista.inserta(P, pos);
            ordenado = false;
        break;
        case OpImprimir:
            system("cls");
            cout<<"\t\t°°°Imprimir la lista°°°\n\n";
            Milista.imprime();
        break;
        case OpBuscar:
            int opcbus;

            system("cls");
            cout<<"\t\t°°°Buscar un elemento°°°\n\n";
            cout<<OpcLineal<<") Busqueda Lineal"<<endl;
            cout<<OpcBinaria<<") Busqueda Binaria"<<endl;
            cout<<OpcSalir<<") Salir\n\n"<<endl;
            cin>>opcbus;
            switch(opcbus){
                case OpcSalir:
                    break;
                case OpcLineal:
                    cout<<"Nombre a buscar: ";
                    cin.ignore();
                    getline(cin, buscar);
                    P.setnombre(buscar);
                    pos = Milista.BusquedaLineal(P);
                    cout<<"Elemento encontrado en la posicion : "<<pos<<endl;
                    Milista.recupera(pos);
                break;
                case OpcBinaria:
                    if(ordenado=false)
                        cout<<"Debes ordenar primero los elementos :)"<<endl;
                    else
                    {
                        cout<<"Nombre a buscar: ";
                        cin.ignore();
                        getline(cin, buscar);
                        P.setnombre(buscar);
                        pos = Milista.BusquedaBinaria(P);
                        cout<<"Elemento encontrado en la posicion : "<<pos<<endl;
                        Milista.recupera(pos);
                    }

                break;
            }
        break;
        case OpOrdenar:

            system("cls");
            cout<<"\t\t°°°Ordenar los elementos°°°\n\n";
            cout<<OBubble<<") Bubble Sort"<<endl;
            cout<<OBBubble<<") Better Bubble Sort"<<endl;
            cout<<OShell<<") Shell Sort"<<endl;
            cout<<OInsert<<") Insert Sort"<<endl;
            cout<<OQuick<<") Quick Sort"<<endl;
            cout<<OSalir<<") Salir"<<endl;
            cin>>opcord;

            switch(opcord){
            case OSalir:
            break;
            case OBubble:
                Milista.BubbleSort();
                Milista.imprime();
                ordenado = true;
            break;
            case OBBubble:
                Milista.BetterBubbleSort();
                Milista.imprime();
                ordenado = true;
            break;
            case OShell:
                Milista.ShellSort();/**< Todavia no funciona */
                Milista.imprime();
                ordenado = true;
            break;
            case OInsert:
                Milista.InsertSort();
                Milista.imprime();
                ordenado = true;
            break;
            case OQuick:
                Milista.QuickSort(Milista.primero(), Milista.Ultimo());
                Milista.imprime();
                ordenado = true;
            break;
            }
        break;

        }
    cout<<"\n\n\n";
    system("pause");
    }while(res==1);

    return 0;
}
