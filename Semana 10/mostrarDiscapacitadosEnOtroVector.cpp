#include <iostream>
#include <string.h>
using namespace std;

/*
Ejercicio 8: Defina una estructura que sirva para representar a una persona. 
La estructura debe contener dos campos: el nombre de la persona y un valor de 
tipo lógico que indica si la persona tiene algún tipo de discapacidad. 
Realice un programa que dado un vector de personas rellene dos nuevos 
vectores: uno que contenga las personas que no tienen ninguna discapacidad 
y otro que contenga las personas con discapacidad.
*/

struct persona{
	char nombre[20];
	bool discap;
}personas[30],dis1[30],dis2[30];

int main(){
	int num_personas;
	int opc, j=0,k=0;
	cout<<"Ingrese el numero de personas: "; cin>>num_personas;
	
	for(int i=0; i<num_personas;i++){
		
		fflush(stdin);
		cout<<"Paciente "<<i+1<<": "<<endl;
		cout<<"Ingrese su nombre: "; cin.getline(personas[i].nombre,20,'\n');
		cout<<"Padece de alguna discapacidad?: 1 --> Si, 0 --> No"<<endl; 
		cout<<"Digite su opcion: ";cin>>opc;
		if(opc==1){
			personas[i].discap = true;
			strcpy(dis1[j].nombre,personas[i].nombre);
			j++;
			
		}else{
			personas[i].discap = false;
			strcpy(dis2[k].nombre,personas[i].nombre);
			k++;

		}
		cout<<"\n";
	}
	
	
	//mostrar resultados
	for(int i=0; i<j;i++){
		cout<<"Discapacitados: "<<endl;
		cout<<i+1<<": "<<dis1[i].nombre<<endl;
	}
	cout<<"\n- - - - - - - - - - - -\n"<<endl;
	for(int i=0;i<k;i++){
		cout<<"No discapacitados: "<<endl;
		cout<<i+1<<": "<<dis2[i].nombre<<endl;
	}
	system("pause");
	return 0;
}

