#include <iostream>

using namespace std;

/* Punteros - Declaracion de punteros

&n = la direccion de memoria de la variable n
*n = la variable cuya direccion esta almacenada en n

*/

int main(){
	
	int num, *dir_num;
	
	num = 20;
	dir_num = &num; //guardamos la posicion de memoria
	
	cout<<"Numero: "<<*dir_num<<endl;
	cout<<"Direccion de memoria: "<<dir_num<<endl;	
	
	
	
	
	
	return 0;
}
