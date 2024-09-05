#include <iostream>

using namespace std;

int a=10;
int *p1; //lo volvemos un almacen de direccion de memoria con el *

int main() {
	
	p1=&a; // almacena la direccion de memoria de 'a'
	
	cout<<"Valor del puntero---> "<<p1<<endl;
	
	cout<<"El valor de la direccion "<<p1<< " es---> "<<*p1<<endl;
	*p1=*p1**p1; //ahora *p1 = 100
	cout<<"El valor de la direccion "<<p1<< " es---> "<<*p1<<endl;
	cout<<"El valor de la variable a "<<a<<endl;
	system("pause");
	
	}
