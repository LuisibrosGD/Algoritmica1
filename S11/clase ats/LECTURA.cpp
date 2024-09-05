#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void lectura();

int main(){
	
	lectura();	
	
	
	
	
	system("pause");
	return 0;
}

void lectura(){
	
	//OJO: se trabaja con un archivo de texto ya creado
	
	ifstream archivo2; //ahora se usa ifstream, en la entrada se usaba ofstream para declarar el archivo
	string texto;
	archivo2.open("programacion.txt", ios::in); //abrimos el archivo en modo lectura
	
	if(archivo2.fail()){ //esto funciona si es que el archivo no ha sido creado previamente
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	
	while(!archivo2.eof()){ //mientras no sea el final del archivo
		getline(archivo2,texto);
		cout<<texto<<endl; //imprime todo el texto del archivo2 que ya ha sido creado
		
		
	}
	
	
	archivo2.close();
	
	
	
	
}
