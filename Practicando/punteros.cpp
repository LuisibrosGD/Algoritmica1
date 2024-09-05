#include <iostream>

using namespace std;

int main(){
	
	int *dir_n1 = NULL;
	int num1;
	
	cout<<"Ingrese un numero: "<<endl;
	cin>>num1;
	
	dir_n1 = &num1; //ahora dir_n1 apunta a la direccion de memoria de num1
	
	cout<<"Direccion de memoria: "<<dir_n1<<endl;
	cout<<"Valor que se encuentra en: "<<dir_n1<<" es "<<*dir_n1<<endl;
	
	
	
	
	system("pause");
	return 0;
}
