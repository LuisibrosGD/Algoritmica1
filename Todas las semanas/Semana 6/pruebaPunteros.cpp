#include <iostream>

using namespace std;

int a=10;
int *p1;

int main() {
	
	p1=&a;
	cout<<"Valor del puntero---> "<<p1<<endl;
	cout<<"El valor de la direccion "<<p1<< "es---> "<<*p1<<endl;
	*p1=*p1**p1;
	cout<<"El valor de la direccion "<<p1<< "es---> "<<*p1<<endl;
	cout<<"El valor de la varianble a "<<a<<endl;
	system("pause");
	
	}
