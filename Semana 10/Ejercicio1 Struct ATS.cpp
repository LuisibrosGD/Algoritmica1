#include <iostream>
#include <conio.h>
#include <string.h>

/*
1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes campos:
nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle una categoria
de competicion:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoria de competicion
*/

using namespace std;

struct corredor{
	char nombre[30];
	int edad;
	char sexo;
	char club[20];
	string categoria;
}corredores[5]; //e

int main(){
	int rpta;
	int j=0;
	for(int i=0;i<5;i++){
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(corredores[i].nombre,30,'\n');
		cout<<"Edad: ";
		cin>>corredores[i].edad;
		cout<<"Sexo M --> Masculino o F --> Femenino"<<endl;
		cout<<"Digite la opcion: ";
		cin>>corredores[i].sexo;
		fflush(stdin);
		cout<<"Club: ";
		cin.getline(corredores[i].club,20,'\n');
		//asignando categoria
		
		if(corredores[i].edad<=18){
			corredores[i].categoria = "Juvenil";
		}else if(corredores[i].edad<=40){
			corredores[i].categoria = "Senior";
		}else{
			corredores[i].categoria = "Veterano";
		}
		
		
		if (i<4){
			cout<<"Desea continuar? --> 0 : Salir, 1: Continuar"<<endl;
			cout<<"Sobran "<<4-i<<" estructuras"<<endl;
			cin>>rpta;
		}
		j++;
		cout<<"\n";
		if(rpta==0){
			break;
		}
		
		
	}
	
	//imprimiedo 
	
	for(int i=0;i<j;i++){
		cout<<"Nombre: "<<corredores[i].nombre<<endl;
		cout<<"Edad: "<<corredores[i].edad<<endl;
		cout<<"Sexo: "<<corredores[i].sexo<<endl;
		cout<<"Club: "<<corredores[i].club<<endl;
		cout<<"Categoria: "<<corredores[i].categoria<<endl;
		cout<<"\n";
	}
	
	
	getch();
	return 0;
	
}
