#include <iostream>

using namespace std;

/*
Ejemplos basicos de funciones

int numMax(int x, int y)  -- ojo tambien puede ser char, string en vez de int
double intercambio(double x, double y)
void desplegar(float x, float y) --> esta funcion no retorna nada

las funciones van a nivel pre procesador

*/

//ejemplo encontrar el mayor de 2 numeros

//prototipo de funcion -------- primero se coloca esto
int encontrarMax(int x, int y);


int main(){
	int n1, n2;
	int mayor;
	
	
	cout<<"Digite 2 numeros; ";
	cin>>n1>>n2;
	
	mayor = encontrarMax(n1, n2); // 3° paso llamamos a la funcion
	
	cout<<"El mayor de los 2 numeros: "<<mayor<<endl;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

//definicion de funcion ---- luego de la definiciond e funcion
int encontrarMax(int x, int y){
	int numMax;
	
	if(x>y){
		numMax = x;
	}else{
		numMax = y;
	}
	
	return numMax;
}
