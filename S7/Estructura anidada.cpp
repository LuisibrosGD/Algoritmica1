#include <iostream>
/*
estructura anidada: una estructura dentro de otra estructura
*/
using namespace std;

struct info_direccion{
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};
//principal
struct empleado{
	char nombre[20];
	info_direccion dir_empleado; //dir_empleado es un nombre cualquiera
	//no hace falta colocar struct
	//struct info_direccion dir_empleado;
	double salario;
}empleados[2];

int main(){
	
	for(int i=0; i<2;i++){
		
		cout<<"Digite su nombre: ";
		cin.getline(empleados[i].nombre,20,'\n');
		cout<<"Digite su direccion: ";
		cin.getline(empleados[i].dir_empleado.direccion,30,'\n');
		cout<<"Ciudad: ";
		cin.getline(empleados[i].dir_empleado.ciudad,20,'\n');
		cout<<"Provincia: ";
		cin.getline(empleados[i].dir_empleado.provincia,20,'\n');
		cout<<"Salario: ";
		cin>>empleados[i].salario;
		cout<<"\n";
		//vaciar el buffer y permitir digitar los valores
		cin.ignore();
	}
	
	
//imprimiendo datos

	for(int i=0;i<2;i++){
		cout<<"Nombre: "<<empleados[i].nombre<<endl;
		cout<<"Direccion: "<<empleados[i].dir_empleado.direccion<<endl;
		cout<<"Ciudad: "<<empleados[i].dir_empleado.ciudad<<endl;
		cout<<"Provincia: "<<empleados[i].dir_empleado.provincia<<endl;
		cout<<"Salario: "<<empleados[i].salario<<endl;
	}
	
	
	
	system("pause");
	return 0;
}
