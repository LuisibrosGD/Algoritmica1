#include <iostream>
#include <string.h>
using namespace std;

struct Persona{
	char nombre[20];
	int edad;
}persona1;

/* OTRA FORMA
struct Persona{
	char nombre[20];
	int edad;
}persona1 = {--ingresa datos en el orden del tipo de datos y separalo con comas--};
*/

int main(){
	struct Persona persona1;
	cout<<"Edad: ";
	cin>>persona1.edad;
	cin.ignore();
	cout<<"Nombre: ";
	//getline(cin, persona1.nombre) --> esto es para usar cuando es string
	cin.getline(persona1.nombre,20,'\n'); //--> esto es para usar cuando es un arreglo de char;
	/*
	OJOOOOOOO: (AQUI SI HACE LIMPIEZA DE BUFFER, SIEMPRE CUANDO SE PIDE UN NUMERO Y
	LUEGO CARACTER)
	cout<<"Edad: ";
	cin>>persona1.edad;
	cin.ignore();
	cout<<"Nombre: ";
	cin.getline(persona1.nombre,20,'\n');
	
	SIN EMBARGO AQUI NO: (EL ORDEN IMPORTA)
	cout<<"Nombre: ";
	cin.getline(persona1.nombre,20,'\n');
	cout<<"Edad: ";
	cin>>persona1.edad;
	
	*/
	
	cout<<"\nImprimiendo datos\n";
	cout<<"Nombre: "<<persona1.nombre<<endl;
	cout<<"Edad: "<<persona1.edad<<endl;
	
	
	
	
	system("pause");
	return 0;	
}
