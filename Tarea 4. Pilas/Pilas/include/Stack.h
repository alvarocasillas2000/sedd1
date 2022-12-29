#ifndef STACK_H
#define STACK_H


class Stack
{
public:

    char pila[1000];
    int tope;//posicion del elemento que esta en el tope de la fila

    int tam;


Stack(int t){
        tam = t;
        tope = 0;
    }

void push(char valor){
    if(tam   > tope){
        tope++;
        pila[tope] = valor;
    }
}

char top(){
    if (tope != 0)
        return pila[tope];
    else
        return -1;
}

 void pop(){
    if (tope > 0)
        tope--;
 }

 bool empty(){
    return tope==0;
 }

};

#endif // STACK_H
