#include <iostream>
#include <conio.h>

using namespace std;

int main (){
	/*
	Escriba un programa que defina un vector de numeros y calcule la suma de sus elementos
	*/
	
	//ojo pide definir el vector
	
	int numeros[] = {1,2,3,4,5};
	int suma = 0;
	
	for (int i=0; i<5; i++){
		
		suma = suma + numeros[i];
		
	}
	
	cout<<"La suma de todos los elementos del vector es: "<<suma;
	
	getch();
	return 0;
}










