#include <iostream>
#include <conio.h>

using namespace std;

/*Escribe un programa que lea de la entrada estandar un vector de numeros y muestre en
la salida estandar los numeros del vector con sus indices asociados.*/

int main(){
	
	int rango;
	
	cout<<"Indique la cantidad de numeros a ingresar: "<<endl;
	cin>>rango;
	
	int numero[rango];
	
	for(int i=0; i<rango; i++){
		cout<<"Escriba el numero de la posicion "<<i+1<<endl;
		cin>>numero[i]; //guardando el numero del vector
	}
	
	cout<<"- - - - - - - - - - - - - - - - - - -"<<endl;
	
	for(int j=0; j<rango; j++){
		cout<<"Numero "<<j+1<<": "<<numero[j]<<endl;
	}
	
	
	
	
	
	
	getch();
	return 0;
}
