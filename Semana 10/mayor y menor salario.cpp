#include <iostream>
#include <conio.h>

/*
3. Realizar un programa que lea un arreglo de estructuras los datos de N empleados
de la empresa y que imprima los datos del empleado con mayor y menor salario
*/

struct empleado{
	char nombre[20];
	float salario;
}empleados[50];

using namespace std;

int main(){
	int num_empleados;
	int numMayor=0, numMenor=9999999, posicionMayor, posicionMenor;
	cout<<"Digite el numero de empleados: "; cin>>num_empleados;
	
	for(int i=0; i<num_empleados;i++){
		cin.ignore();
		cout<<"Escriba su nombre: "; cin.getline(empleados[i].nombre, 20,'\n');
		cout<<"Digite su salario: "; cin>>empleados[i].salario;
		
		if(empleados[i].salario>numMayor){
			numMayor = empleados[i].salario;
			posicionMayor = i;
		}
		if(empleados[i].salario<numMenor){
			numMenor = empleados[i].salario;
			posicionMenor = i;
		}
		
		
	}
	
	//Mostrar resultados
	cout<<"\nMenor salario: "<<endl;
	cout<<"Nombre: "<<empleados[posicionMenor].nombre<<endl;
	cout<<"Salario: "<<empleados[posicionMenor].salario<<endl;
	cout<<"\nMayor salario: "<<endl;
	cout<<"Nombre: "<<empleados[posicionMayor].nombre<<endl;
	cout<<"Salario: "<<empleados[posicionMayor].salario<<endl;

	
	
	getch();
	return 0;
}
