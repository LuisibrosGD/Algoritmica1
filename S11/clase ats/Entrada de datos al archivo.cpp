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
	ofstream archivo; //declarando: es como int n1; ofstream nombreDelArchivo
	
	string nombreArchivo,frase;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin, nombreArchivo);
	
	// archivo.open("prueba.txt", ios::out); //abriendo el archivo y creando el archivo en la misma carpeta del codigo
	archivo.open(nombreArchivo.c_str(),ios::out); //usamos .c_str para transformar la cadena a comando de C, ya que si colocas 
	//nombreArchivo te va dar error
	
	//ios::out -> modo copiar texto y empezar de nuevo cada vez que compile
	
	if(archivo.fail()){ //archivo.fail() -> envia un valor booleano
	
		cout<<"No se pudo abrir el archivo";
		exit(1);
		
	}
	
	cout<<"\nDigite el texto del archivo: ";
	getline(cin, frase); //usamos getline para guardar cadena
	
	archivo<<frase; //ahora lo que se inserte por consola va a estar en el archivo
	
	archivo<<endl; //un salto de linea 
	
	archivo<<"Hola que tal mi nombre es luisus";
	//cout<<"ingrese texto";	
	archivo.close(); //cerrar el archivo
}
