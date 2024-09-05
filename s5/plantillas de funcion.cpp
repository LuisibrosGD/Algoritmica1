//plantillas de funcion

//ejemplo: sacar el valor absoluto de un numero

#include <iostream>

using namespace std;

//prototipo de funcion

template <class tipoD>  //esto es para hacer plantillas, lo que viene despues de class es un nombre cualquiera
void mostrarAbs(tipoD numero); //usamos template porque no sabemos que tipo de dato vamos a recibir, ya 
//que si no tendrias que hacer una funcion para cada tipo de dato

int main(){
	int num1 = 5;
	
	float num2=56.27;
	
	double num3= -123.5678;
	
	mostrarAbs(num1);
	mostrarAbs(num2);
	mostrarAbs(num3);
	
	
	
	
	return 0;
}

template <class tipoD>
void mostrarAbs(tipoD numero){
	if(numero<0){
		numero = numero * -1;
	}
	cout<<"El valor absoluto del numero es: "<<numero<<endl;
}
