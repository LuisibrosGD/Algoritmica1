#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void escribir();

int main(){
	
	escribir();
	
	
	
	system("pause");
	return 0;
}

void escribir(){
	
	ofstream archivo;
	string nombreArchivo, frase;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin, nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(), ios::out); //Abriendo el archivo
	//archivo.open("nombre//carpeta1//carpeta2//ejemplo.txt", ios::out);
	//en el primer parametro puedes colocar la ruta donde se debe guardar el archivo
	//en el primer parametro puedes colocar un "nombre" en vez de nombreArchivo.c_str()
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	cout<<"\nDigite el texto del archivo: ";
	getline(cin,frase);
	
	archivo<<frase; //guarda la frase en el archivo
	
	//archivo<<"Hola que tal mi nombre es Luis"; //esto escribira en el archivo este mensaje
	
	archivo.close(); //Cerrar el archivo
	
}







