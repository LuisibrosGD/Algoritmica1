/*Ejercicio 2: escriba una funcion llamada al_cuadrado() que calcule el cuadrado del valor que se le
transmite y despliegue el resultado. La funcion deberá ser capaz de elevar al cuadrado números flotantes*/

#include <iostream>

using namespace std;

//Prototipo de funcion
void pedirNum();
void al_cuadrado(int x, int y);

int n1, n2;

int main(){
	
	pedirNum();
	
	al_cuadrado(n1, n2);
	
	
	
	
	
	return 0;
}

//funciones

void pedirNum(){
	cout<<"Digite un numero: "; cin>>n1;
	cout<<endl;
	cout<<"Digite la potencia: "; cin>>n2;
}
void al_cuadrado(int x, int y){
	long resultado=1;
	for(int i=1; i<=y; i++){
		
		resultado=resultado*x;
	}
	
	cout<<"El resultado es: "<<resultado<<endl;	
}

