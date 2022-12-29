#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
using namespace std;


class Queue
{
public:
    int tam;
    int fro;
    int ult;
    char cola[1000];

    Queue(int t){
        tam = t;
        fro = 0;
        ult = 0;
    }

    void push(char valor){   //Agregar elementos
        if(empty()){        //Si esta vacia se
            fro=1;          //settean los valores en
            ult=1;          //1,1
        }
        else                //si no esta vacia solo se
            ult++;          //incrementa el ultimo en 1
        cola[ult] = valor;  //y se añade el valor, en ambos casos
    }

    char front(){            //devuelve el primer valor de la cola
        if(empty()){        //Si esta vacía, devuelve -1
            return -1;
        }
        return cola[fro];   //Retorna el valor en front
    }

    void pop(){
        fro++;
        if(fro >= ult){ //Si ya se vacio la lista
            ult = 0;    //se resetean los valores
            fro = 0;    //del front y el ultimo
        }
    }

    bool empty(){
        return (fro==0 && ult== 0);
    }

    char last(){
        return cola[ult];
    }

};
#endif // QUEUE_H
