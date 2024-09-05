/*

*/
#include <iostream>

using namespace std;

int main(){
	
	int tam;
	double suma=0, prom=0;
	char opc;
	
	do{

	cout<<"Digite el tamanio del vector: "; cin>>tam;
	double num[tam];
	
	for(int i=0; i<tam;i++){
		do{
		
		cout<<"Escribir el dato de la posicion: "<<i+1<<"--> "; cin>>num[i];
		
		if(num[i]>20||num[i]<0){
			system("cls");
		}
		
		}while(num[i]>20||num[i]<0);
	
	}
	system("cls");
	//sumar los elementos del vector
		
	for(int i=0;i<tam;i++){
		suma = suma + num[i];	
	}
	
	prom = suma / tam;
	
	cout<<"Vector: ";
	for(int i=0; i<tam;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	cout<<"El tamanio del vector es: "<<tam<<endl;
	cout<<"La suma de los elementos del vector es: "<<suma<<endl;
	cout<<"El promedio es: "<<prom<<endl;
	
	
	cout<<"Quiere seguir continuando? 0 = salir, 1 = repetir "<<endl;
	cin>>opc;
	system("cls");
	}while(opc!='0');
	system("pause");
	return 0;
}
