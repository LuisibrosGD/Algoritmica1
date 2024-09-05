/*Ejercicio 3:  Escriba una funcion llamada mult() que acepte dos numeros en puntos
flotante como parametros, multiplique estos dos numeros y despliegue el resultado */

#include <iostream>

using namespace std;

//prototipo de funcion

void pedirDatos();
void mult(float x, float y);

float num1, num2;


int main(){
	
	pedirDatos();
	
	mult(num1, num2);
	
	
	
	
	
	
	return 0;
}

void pedirDatos(){
	cout<<"Digite 2 numeros: "<<endl;
	cin>>num1>>num2;
}

void mult(float x, float y){
	float multiplicacion = x * y;
	
	cout<<"La multiplicacion es: "<<multiplicacion<<endl;
}




