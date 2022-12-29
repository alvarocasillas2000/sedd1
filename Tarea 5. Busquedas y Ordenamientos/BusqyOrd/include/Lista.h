#include <iostream>
#ifndef LISTA_H
#define LISTA_H
#include <exception>

using namespace std;
const int TAM=100;

class persona{
private:
    string nombre;
    string apellido_p, apellido_m;
    string ocupacion;
    string direccion;
    string edad;

public:
    persona(){};
    persona(const string& p):nombre(p){};
    persona(const persona& p){
        nombre=p.nombre;
        apellido_p=p.apellido_p;
        apellido_m=p.apellido_m;
        ocupacion=p.ocupacion;
        direccion=p.direccion;
        edad=p.edad;
    };

    string tostring()const{
        string resultado;
//        char cad[50];
        resultado+="\n";
        resultado+=nombre;
        resultado+=" ";
        resultado+=apellido_p;
        resultado+=" ";
        resultado+=apellido_m;
        resultado+=" | ";
        resultado+=edad;
        resultado+=" anios | Ocupacion: ";
        resultado+=ocupacion;
        resultado+=" | Direccion: ";
        resultado+=direccion;
        return resultado;
    }

    friend bool operator==(persona &p1, persona &p2){
        return p1.nombre== p2.nombre;
    }
    friend bool operator>(persona &p1, persona &p2){
        return p1.nombre> p2.nombre;
    }
    friend bool operator<(persona &p1, persona &p2){
        return p1.nombre< p2.nombre;
    }
    friend bool operator>=(persona &p1, persona &p2){
        return p1.nombre>= p2.nombre;
    }
    friend bool operator<=(persona &p1, persona &p2){
        return p1.nombre<= p2.nombre;
    }
    void setnombre(const string& p ){ nombre=p;}
    string getnombre()const { return nombre;}

    void setApellido_p(const string& p ){ apellido_p=p;}
    string getApellido_p()const { return apellido_p;}

    void setApellido_m(const string& p ){ apellido_m=p;}
    string getApellido_m()const { return apellido_m;}

    void setOcupacion(const string& p ){ ocupacion=p;}
    string getOcupacion()const { return ocupacion;}

    void setDireccion(const string& p ){ direccion=p;}
    string getDireccion()const { return direccion;}

    void setEdad(const string& p ){ edad=p;}
    string getEdad()const { return edad;}

    friend ostream& operator<<(ostream& o,persona& p2){

        o<<"Nombre Completo:"<<p2.nombre;
        o<<" "<<p2.apellido_p;
        o<<" "<<p2.apellido_m;
        o<<" | "<<p2.edad<<" anios";
        o<<"\n   Ocupacion: "<<p2.ocupacion;
        o<<" | Direccion: "<<p2.direccion;
        return o;
    }
    friend istream& operator>>(istream& o,persona& p2){
        cout<<"Ingresa nombre: ";
        o>>p2.nombre;
        cout<<"Apellido paterno: ";
        o>>p2.apellido_p;
        cout<<"Apellido materno: ";
        o>>p2.apellido_m;
        cout<<"Edad: ";
        o>>p2.edad;
        cout<<"Ocupacion: ";
        o>>p2.ocupacion;
        cout<<"Direccion: ";
        cin.ignore();
        getline(o, p2.direccion);
//        o>>p2.direccion;
        cout<<"Ingresado con exito"<<endl;


        return o;
    }
};
template<class T>
class Lista{
private:
    T datos[TAM];
    int ultimo;
public:
    Lista():ultimo(-1){};
     class Exception : public std::exception {
      private:
        std::string msg;

      public:
        explicit Exception(const char* message) : msg(message) { }

        explicit Exception(const std::string& message) : msg(message) { }

        virtual ~Exception() throw () { }

        virtual const char* what() const throw () {
            return msg.c_str();
        }
    };
    bool vacia()const;
    bool llena()const;
    bool inserta(const T&, const int& );
    bool eliminar(const int&);
    int  primero()const;
    int  Ultimo()const;
    int  anterior(const int&)const;
    int  siguiente(const int &)const;
    void recupera(const int& )const;
    void  imprime()const;
    string toString();
    int BusquedaLineal(T&);
    int BusquedaBinaria(T&);
    void BubbleSort();
    void BetterBubbleSort();
    void InsertSort();
    int QuickSort(int , int);
    void ShellSort();
};

template<class T>
void Lista<T>::ShellSort(){
    int i, j, k, intervalo=Ultimo()/2;
    T aux;
    while(intervalo>=1)
    {
        for(i=0; i+intervalo<Ultimo(); i++)
        {
            j=i;
            while(j>=0)
            {
                k=j+intervalo;
                if(datos[j]>datos[k])
                {
                    aux = datos[j];
                    datos[j] = datos [k];
                    datos[k] = datos [j];
                    j = j - intervalo;
                }
                else
                    j--;
            }
        }
        intervalo = intervalo / 2;
    }
}

template<class T>
string Lista<T>::toString(){
    string resultado;
    int i(0);
    while(i<=ultimo)
    {
        resultado+=datos[i].tostring()+"\n";
        i++;
    }
    return resultado;
}

template<class T>
int Lista<T>::QuickSort(int izq, int der){
    T aux;
    int i, j;
    if(izq>=der)
        return 0;
    aux=datos[izq];
    datos[izq]=datos[der];
    datos[der]=aux;
    i=izq;
    j=der;
    while(i<j){
        while(i<j&&datos[i]<=datos[der]){
            i++;
        }
        while(i<j&&datos[j]>=datos[der]){
            j--;
        }
        if(i!=j){
            aux = datos[i];
            datos[i]=datos[j];
            datos[der]=aux;
        }
        QuickSort(izq, i-1);
        QuickSort(i+1, der);
    }
}//A la hora de implementarlo se pone asi
//QuickSort(Milista.primero(), Milista.ultimo())

template<class T>
void Lista<T>::InsertSort(){
    int i=1, j;
    T aux;
    while(i<=ultimo){
        aux = datos[i];
        j=i;
        while(j>0&&aux<datos[j-1]){
            datos[j]=datos[j-1];
            j--;
        }
        if(i!=j)
            datos[j]=aux;
        i++;
    }

}

template<class T>
void Lista<T>::BetterBubbleSort(){
    int i=ultimo, j, bandera, cont=0;
    do{
            bandera=0;
            j=0;
        while(j<i){
            if(datos[j]>datos[j+1]){
                T aux=datos[j];
                datos[j]=datos[j+1];
                datos[j+1]=aux;
                bandera=1;
            }
            cont++;
            j++;
        }
    i--;
    }while(bandera==1);
    cout<<"\n Numero iteraciones:"<<cont;
}

template<class T>
void Lista<T>::BubbleSort(){
    int i=ultimo, j, cont=0;
    while(i>0){
            j=0;
        while(j<i){
            if(datos[j]>datos[j+1]){
                T aux=datos[j];
                datos[j]=datos[j+1];
                datos[j+1]=aux;
            }
            cont++;
            j++;
        }
    i--;
    }
    cout<<"\n Numero iteraciones:"<<cont;
}

template<class T>
int Lista<T>::BusquedaBinaria(T& elem){
    int i=0, j=ultimo, medio;
    while(i<=j){
        medio=(i+j)/2;
        if(elem==datos[medio]){
            return medio;
        }
        if(elem<datos[medio]){
            j=medio-1;
        }
        else{
            i=medio+1;
        }
    }
    return -1;
}

template<class T>
int Lista<T>::BusquedaLineal(T& elem){
    int i=0;
    while(i<=ultimo){
        if(elem==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

template<class T>
void Lista<T>::imprime()const{
    for(int i=0;i<=ultimo;i++){
        T aux=datos[i];
        cout<<"\n"<<i<<": "<<aux;
    }
}
template<class T>
void Lista<T>::recupera(const int& pos)const {
    if(vacia()||pos<0||pos>ultimo){
        cout<<"\n Error de excepcion"<<endl;
        throw Exception("Posicion invalida, recupera");    //Aqui tenemos un problema que se resolvera con exceptions
    }
    else{
        T aux = datos[pos];
        cout<< aux;
    }
}
template<class T>
int Lista<T>::siguiente(const int& pos)const{
    if(vacia()||pos<0||pos>ultimo-1)
        return -1;
    return pos+1;
}
template<class T>
int Lista<T>::anterior(const int& pos)const{
    if(vacia()||pos<0||pos>ultimo)
        return -1;
    return pos-1;
}
template<class T>
int Lista<T>::Ultimo()const{
    if(vacia())
        return -1;
    return ultimo;
}
template<class T>
int Lista<T>::primero()const{
    if(vacia())
        return -1;
    return 0;
}
template<class T>
bool Lista<T>::eliminar(const int& pos){
    if(vacia()||pos<0||pos>ultimo)
        return false;
    int i=pos;
    while(i<ultimo){
        datos[i]=datos[i+1];
        i++;
    }
    ultimo--;
    return true;
}
template<class T>
bool Lista<T>::inserta(const T &elem,const int& pos){
    if(llena()||pos<0||pos>ultimo+1)
        return false;
    int i=ultimo+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ultimo++;
    return true;
}
template<class T>
bool Lista<T>::llena()const{
    if(ultimo==TAM-1)
       return true;
    return false;
}
template<class T>
bool Lista<T>::vacia()const{
    if(ultimo==-1)
        return true;
    return false;
}

#endif // LISTA_H
