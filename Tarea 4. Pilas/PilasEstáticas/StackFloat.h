#ifndef STACKFLOAT_H
#define STACKFLOAT_H


class StackFloat
{
public:

    float pila[1000];
    int tope;//posicion del elemento que esta en el tope de la fila

    int tam;


StackFloat(int t){
        tam = t;
        tope = 0;
    }

void push(float valor){
    if(tam   > tope){
        tope++;
        pila[tope] = valor;
    }
}

float top(){
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


#endif // STACKFLOAT_H
