#include <iostream>
#include <conio.h>

using namespace std;

/*
Escribe un programa que defina un vector de numeros y muestre en la salida estandar el vector en 
orden inverso - del ultimo al primer elemento
*/

int main(){

	int vector[10], vector_inverso[10];
	
	for(int i=0; i<10; i++){
		cout<<"Ingrese el numero de la posicion "<<i+1<<"."<<endl;
		cin>>vector[i];
	}
	
	for(int j=0; j<10; j++){
		vector_inverso[j] = vector[9-j];
		
	}
	
	cout<<"* * * * * * * * * * * * * * * * * * *"<<endl;
	
	for(int k=0; k<10; k++){
		cout<<"Elemento de la posicion "<<k+1<<" es: "<<vector_inverso[k]<<endl;
		
	}
	
	
	getch();
	return 0;
}
