/*
1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes campos:
nombre, edad, sexo, club, pedir datos al usuario para un corredor, 
y asignarle una categoría de competicion:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoria de competicion
*/

#include <iostream>
#include <string.h>
using namespace std;

struct corredor{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
	char cate[10];
}c1;

int main(){
	
	char cate[15];
	
	cout<<"Nombre: ";
	cin.getline(c1.nombre, 20,'\n'); //el c1. es para guardar el dato en c1.
	cout<<"Edad: ";
	cin>>c1.edad;
	cin.ignore();
	cout<<"Sexo: ";
	cin.getline(c1.sexo,10,'\n');
	cout<<"Club: ";
	cin.getline(c1.club,20,'\n');	
	
	if(c1.edad<=18){
		strcpy(cate,"Juvenil");
	}else if(c1.edad<=40){
		strcpy(cate,"Senior");
	}else{
		strcpy(cate,"Veterano");
	}
	
	cout<<"- - - - - - - - - - -"<<endl;
	cout<<"Nombre: "<<c1.nombre<<endl;
	cout<<"Edad: "<<c1.edad<<endl;
	cout<<"Sexo: "<<c1.sexo<<endl;
	cout<<"Club: "<<c1.club<<endl;
	cout<<"Categoria: "<<cate<<endl;
	
	system("pause");
	return 0;
}
