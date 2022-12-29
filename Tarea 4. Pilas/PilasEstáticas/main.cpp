#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "StackFloat.h"

using namespace std;

Queue post(100);


//Definir una funcion que le otorgue prioridad a las operaciones
int prioridad(char car){
    switch(car){
    case '/':
    case '*': return 2;
    break;
    case '+':
    case '-': return 1;
    break;
    default:
        return 0;

    }
}
									//Funcion para transformar de infija a postfija
void InfToPost(string inf){			//recibe la cadena a transformar
    int i=0;						//inicializar el contador
    char c;							//variable auxiliar
    Stack pila(100);
    while (i < inf.size()){			//mientras que i sea menor que el tamaño de la cadena
        switch(inf[i]){
            case '(': pila.push(inf[i]);	//Si es parentesis de apertura se añade a la pila
            break;
            case ')':						//Si es de cierre, se encuentra su pareja y se eliminan ambos
                while(pila.top() != '('){		//Mientras que el tope no sea el de apertura
                        post.push(pila.top());	//se traslada el operador que este en la pila a la variable auxiliar
                        pila.pop();				//se elimina ese operador
                }
                pila.pop();					//Por ultimo se elimina el parentesis de cierre tambien
            break;
            case '/':
            case '*':
            case '+':
            case '-':						//mientras que la prioridad del que quiere entrar es menor o igual a la prioridad
                							//del elemento en el tope de la pila, se saca el tope y se pasa a la cola
                while(prioridad(inf[i]) <= prioridad(pila.top())){
                    post.push(pila.top());
                    pila.pop();
                }
                pila.push(inf [i]);
            break;
            default:						//cualquier otro caracter
                post.push(inf [i] );		//Se añade a la cola


        }
    i++;
    }
    while(!pila.empty()){			//Mientras que la pila no este vacia
        post.push(pila.top());		//Se añaden todos los elementos faltantes
        pila.pop();
    }
    post.push(pila.top());			
}


string imprime(){					//Funcion para mostrar el resultado
    Queue caux = post;				//Se crea una cola auxiliar por si se necesita luego la original, para evaluarla, por ejemplo
    string postfija = "";			//aqui se concatena el resultado
    while(!caux.empty()){			//mientras la lista no este vacia
        if(caux.front()==32)		//si por error se insertó un espacio, se elimina.
            caux.pop();
        else{
        postfija+=caux.front();		//se concatena al resultado
        caux.pop();					//y se elimina el frente
        }
    }
    postfija+=caux.front();
    return postfija;				//al final se retorna el resultado
}

main(){					//Transformacion de infija a postfija
    string entrada;
    cout<<"Introduzca la expresion infija"<<endl;
    cin.ignore();
    getline(cin, entrada);
    InfToPost(entrada);//se hace el cambio de infija a post
    cout<<imprime()<<endl;//se imprime
}
/*
float evaluar(string post){
    StackFloat pilaf(100);
    float x, y, r;
    char ca;
    int i=0;
    while(i<post.size()){
        ca = post[i];
        switch(ca){
            case '/':
            case '*':
            case '-':
            case '+':
                y = pilaf.top(); pilaf.pop();
                x = pilaf.top(); pilaf.pop();
                switch(ca){
                    case '/':
                        r = x / y;
                    break;
                    case '*':
                        r = x * y;
                    break;
                    case '-':
                        r = x - y;
                    break;
                    case '+':
                        r = x + y;
                    break;
                }
            pilaf.push(r);
            break;
            default:
                pilaf.push(ca - '0');
            break;
        }
        i++;
    }
    return pilaf.top();
}

void ejercicio2(){
    string entrada;
    cout<<"Introduzca una expresion postfija"<<endl;
    cin.ignore();
    getline(cin, entrada);
    cout<<evaluar(entrada);
}


enum{
OPSALIR = 0,
OPEJ1,
OPEJ2,
OPEJ3,
};

void ejercicio3(){
    int n, x;
    StackFloat rep(100), Aux(100), Fin(100);
    cout<<"Eliminar repetidos en una pila"<<endl;
    cout<<"\n¿Cuantos elementos desea agregar a la pila?"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
            cout<<i+1<<". ";
            cin>>x;
            rep.push(x);
    }
    while(!rep.empty()){
        if(Aux.empty()){
            Aux.push(rep.top());
            rep.pop();
                if(Aux.top()==rep.top()){
                rep.pop();
                }
                else {
                Aux.push(rep.top());
                rep.pop();
                }
        }

        if(Aux.top()==rep.top()){
            rep.pop();
        }
        else {
            Aux.push(rep.top());
            rep.pop();
        }
    while(!Aux.empty()){
        Fin.push(Aux.top());
        Aux.pop();
    }

    //mostrar la pila
    while(!Fin.empty()){
        cout<<Fin.top()<<endl;
        Fin.pop();
    }
}
}


int main()
{
    int opc;
    cout<<"\t\t°°°°Pilas v1.0°°°°"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"Elija el programa que desea ejecutar: "<<endl;
    cout<<OPEJ1<<") De infija a postfija"<<endl;
    cout<<OPEJ2<<") Evaluar resultado de expresion postfija"<<endl;
    cout<<OPEJ3<<") Eliminar elementos repetidos consecutivos"<<endl;
    cout<<OPSALIR<<") Salir\n"<<endl;
    cin>>opc;
    switch(opc){
    case OPSALIR:
        system("cls");
        break;
    case OPEJ1:
        ejercicio1();
        break;
    case OPEJ2:
        ejercicio2();
        break;
    case OPEJ3:
        ejercicio3();
        break;
    default:
        cout<<"Opcion inválida"<<endl;

    }
    return 0;
}*/
