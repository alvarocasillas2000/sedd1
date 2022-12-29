#include <iostream>
#include <cstring>
#include <cstdio>
#include "Mamifero.h"

using namespace std;

int main() {
	
	GatoDomestico Minino = GatoDomestico("Minino","Croquetas", 2016, "Rancho Viejo", "Siames", "Antonio Rodriguez", "");
	Felino EstrellaCirco = Felino("Estrella de Circo","Pollo crudo", 2015, "Orizaba, Veracruz", "Tigre de Bengala", "Circo Hermanos Enriquez");
	
	
	int option, ans=0, op;
	do{
		system("cls");
		cout<<"\n\t\t°°°CLASES HEREDADAS v1.O°°°"<<endl;
		cout<<"---------------------------------------------------------\n\n"<<endl;
		cout<<"\t\tElija la funcion que desee realizar:\n"<<endl;
		cout<<"\t1. Mostrar la dieta"<<endl;
		cout<<"\t2. Mostrar el anio y lugar de nacimiento"<<endl;
		cout<<"\t3. Cambiar el nombre del propietario de Minino"<<endl;
		cout<<"\t4. Mostrar la raza"<<endl;
		cout<<"\t5. Cambiar el nombre del circo de la Estrella de Circo"<<endl;
		cout<<"\t6. Salir\n\n"<<endl;
		
		cin>>option;

		switch(option)
		{
			case 1: 
				system("cls");
				cout<<"\t1. Mostrar la dieta\n\n"<<endl;
				Minino.PrintDiet();
				EstrellaCirco.PrintDiet();
			break;
			case 2:
				system("cls");
				cout<<"\t2. Mostrar el anio y lugar de nacimiento"<<endl;
				Minino.PrintYearPlace();
				EstrellaCirco.PrintYearPlace();
			break;
			case 3:
				system("cls");
				cout<<"\t3. Cambiar el nombre del dueño de Minino"<<endl;
				Minino.ChangeOwner();
			break;
			case 4:
				system("cls");
				cout<<"\t4. Mostrar la raza"<<endl;
				Minino.PrintRaza();
				EstrellaCirco.PrintRaza();
			break;
			case 5:
				system("cls");
				cout<<"\t5. Cambiar el nombre del circo de la Estrella de Circo\n\n"<<endl;
				EstrellaCirco.ChangeCircus();
			break;
			case 6:
			break;
			default:
				system("cls");
				{cout<<"-.-.-.-.-.-La funcion que selecciono no existe-.-.-.-.-.-"<<endl;
				}
			break;
		}
		if(option!=6){
		cout<<"Desea regresar al menu?\n"<<endl;
		cout<<"\t1=Si\t2=No\n\n\t";
		cin>>ans;	
		}
	}while(ans==1);
	
	return 0;
}
