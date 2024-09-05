#include <iostream>
#include <conio.h>
#include <unistd.h>

using namespace std;

/*Desarrolle un programa que lea de la entrada estandar un vector de enteros y determine el mayor
elemento del vector.*/

int main(){
	int rango;
	do{
	
	cout<<"Indique la cantidad de numeros a ingresar: ";
	cin>>rango;
	if (rango <= 0){
		cout<<"Rango no admitido"<<endl;
		usleep(500000); //esta funcion es para que espere un rato pero con valores de menos de 1 segundo
		// 100 000 = 0.1 segundo
		system("cls");
	}
	
	}while(rango<=0);
	
	int num[rango];
	
	for(int i=0; i<rango; i++){
		cout<<i+1<<". Digite un numero: "; cin>>num[i];
	}
	system("cls");
	
	int num_mayor = num[0];
	
	for(int i=0; i<rango; i++){
		if (num_mayor<=num[i]){
			num_mayor = num[i];
		}
	}
	
	cout<<"El numero mayor es: "<<num_mayor<<endl;
	
	getch();
	return 0;
}
