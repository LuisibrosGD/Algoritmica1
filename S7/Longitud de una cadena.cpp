/*
Hacer un programa que pida al usuario que digite una cadena de caracteres, 
luego verificar la longitud de la cadena, y si esta supera a 10 caracteres
mostrarla en pantalla, caso contraria no mostrarla.
*/
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int opc;
	char palabra[100];
	
	do{
		
	
	int longitud=0;
	
	cout<<"Digite una frase: "; cin.ignore();cin.getline(palabra,100,'\n');
	
	
	//strlen()
	
	longitud = strlen(palabra);
	
	if(longitud > 10){
		cout<<palabra<<endl;
	}
	
	cout<<"Continuar?: Si(1), No(0)"<<endl;
	cin>>opc;
	
	
	}while(opc == 1);
	
	system("pause");
	return 0;
}





