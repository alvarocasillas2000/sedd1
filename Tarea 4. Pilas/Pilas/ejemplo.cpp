#include <iostream>


using namespace std;

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
 	if (tope==0);
    return true;
 }

};


//Definir una funcion que le otorgue prioridad a las operaciones
int prioridad1(char car){
    switch(car){
    case '/':
    case '*': return 2;
    break;
    case '+':
    case '-': return 1;
    break;
    default: return 0;
    break;
    }
}

string InfToPost1(string inf){//recibe la cadena a transformar
    int i=0;//inicializar el contador
    char c;//variable auxiliar
    string resultado = "";
    Stack pila(100);
    while (i < inf.size()){//mientras que i sea menor que el tamaño de la cadena
        switch(inf[i]){//
            case '(': pila.push(inf[i]);//Si es parentesis de apertura se añade a la pila
            break;
            case ')'://Si es de cierre, se encuentra su pareja y se eliminan ambos
                while(pila.top() != '('){//Mientras que el tope no sea el de apertura
                        resultado+=pila.top();
                        ///c = pila.top();//se traslada el operador que este en la pila a la variable auxiliar
                        pila.pop();//se elimina ese operador
                        ///post.push(c);//y se inserta a la cola
                }
                pila.pop();//Por ultimo se elimina el parentesis de cierre tambien
            break;
            case '/':
            case '*':
            case '+':
            case '-'://mientras que la prioridad del que quiere entrar es menor o igual a la prioridad
                //del elemento en el tope de la pila, se saca el tope y se pasa a la cola
                while(prioridad1(inf[i]) <= prioridad1(pila.top())){
                    resultado+=pila.top();
                    ///c = pila.top();
                    ///pila.pop();
                    ///post.push(c);
                }
                //pila.push(inf [i]);
            break;
            default://cualquier numero
                resultado+=inf[i];
                ///post.push(inf [i] );//Se alade a la cola


        }
    i++;
    }
    while(!pila.empty()){
            resultado+=pila.top();
      ///  c = pila.top();
        pila.pop();
        ///post.push(c);
    }
    resultado+=pila.top();
    return resultado;
}

/*string imprime(){//Funcion para mostrar el resultado
    Queue caux = post;//Se crea una cola auxiliar pos si se necesita luego la original
    string postfija = "";//aqui se concatena el resultado
    while(!caux.empty()){//mientras la lista no este vacia
        postfija+=caux.front();//se concatena al resultado
        caux.pop();//y se elimina el frente
    }
    postfija+=caux.front();
    return postfija;//al final se retorna el resultado
}
string imprime(){//Funcion para mostrar el resultado
    //Queue caux = post;//Se crea una cola auxiliar pos si se necesita luego la original
    string postfija = "";//aqui se concatena el resultado
    while(!post.empty()){//mientras la lista no este vacia
        postfija+=post.front();//se concatena al resultado
        post.pop();//y se elimina el frente
    }
    postfija+=post.front();
    return postfija;//al final se retorna el resultado
}
*/

int main(){
string entrada;
    cout<<"Introduzca la expresion infija"<<endl;
    //cin.ignore();
    //getline(cin, entrada);//Se lee el valor inicial
    cin>>entrada;
    cout<<InfToPost1(entrada);//se hace el cambio de infija a post
    //cout<<imprime()<<endl;//se imprime
   // cout<<"asdaf";
    return 0;
}

