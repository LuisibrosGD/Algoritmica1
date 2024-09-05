//Añadir texto al final de un archivo

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

void aniadir();

int main(){
	
	aniadir();
	
	
	system("pause");
	return 0;
}

void aniadir(){
	
	ofstream archivo;
	string texto;
	
	archivo.open("programacion.txt", ios::app); //abrimos el archivo en modo añadir texto
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	cout<<"Digite el texto que quiera aniadir: "<<endl;
	getline(cin,texto);
	archivo<<texto<<endl;
	
	archivo.close();
	
	
}
