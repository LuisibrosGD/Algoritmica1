/*
Estructuras anidadas

struct info_direccion{
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};

struct empleado{ --> ESTA ES LA ESTRUCTURA PRINCIPAL
	char nombre[20];
	struct info_direccion dir_empleado;  --->dir_empleado es una variable de info_direccion
	double salario;
}

EL ORDEN SERA nombre, direccion, ciudad, provincia, salario
*/

#include <iostream>
#include <conio.h>

using namespace std;

struct info_direccion{
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};

struct empleado{
	char nombre[20];
	struct info_direccion dir_empleado; 
	double salario;
}empleados[2];//esto reemplaza a empleado1,empleado2 y lo coloca todo en un arreglo 
//a esto se le conoce como arreglo de estructuras

int main(){
	
	for(int i=0;i<2;i++){
		fflush(stdin); //vaciar el buffer y permitir digitar los valores
		cout<<"Digite su nombre: ";
		cin.getline(empleados[i].nombre,20,'\n');
		cout<<"Digite su direccion: ";
		cin.getline(empleados[i].dir_empleado.direccion,30,'\n');
		cout<<"Digite la ciudad: ";
		cin.getline(empleados[i].dir_empleado.ciudad,20,'\n');
		cout<<"Provincia: ";
		cin.getline(empleados[i].dir_empleado.provincia,20,'\n');
		cout<<"Salario: ";
		cin>>empleados[i].salario;
		cout<<"\n";
	}
	
	
	//imprimiendo los datos
	for(int i=0;i<2;i++){
		cout<<"Nombre: "<<empleados[i].nombre<<endl;
		cout<<"Direccion: "<<empleados[i].dir_empleado.ciudad<<endl;
		cout<<"Ciudad: "<<empleados[i].dir_empleado.ciudad<<endl;
		cout<<"Provincia: "<<empleados[i].dir_empleado.provincia<<endl;
		cout<<"Salario: "<<empleados[i].salario;
		cout<<"\n";
	}
	
	getch();
	return 0;
}






