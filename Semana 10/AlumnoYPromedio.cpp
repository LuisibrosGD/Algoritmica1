#include <iostream>

using namespace std;

/*
Ejercicio 5: Hacer 2 estructuras una llamada promedio que tendrá 
los siguientes campos: nota1, nota2, nota3; y otro llamada alumno 
que tendrá los siguientes miembros: nombre, sexo, edad; hacer que 
la estructura promedio este anidada en la estructura alumno, 
luego pedir todos los datos para un alumno, luego calcular su 
promedio, y por ultimo imprimir todos sus datos incluidos el promedio.
*/

struct promedio{
	float nota1;
	float nota2;
	float nota3;
	float promedio;
};

struct alumno{
	char nombre[20];
	char sexo;
	int edad;
	struct promedio dir_promedio;
}alumnos[25];

int main(){
	int nAlumnos;
	cout<<"Digite la cantidad de alumnos: "; cin>>nAlumnos;
	cout<<endl;
	
	for(int i=0;i<nAlumnos;i++){
		fflush(stdin);
		cout<<"Alumno "<<i+1<<endl;
		cout<<"\nIngrese el nombre: "; cin.getline(alumnos[i].nombre,20,'\n'); //Recuerda que se esta trabajando con alumnos y no alumno
		cout<<"\nSexo (M) o (F): "; cin>>alumnos[i].sexo;
		cout<<"\nDigite su edad: "; cin>>alumnos[i].edad;
		cout<<"\nIngrese Nota 1: "; cin>>alumnos[i].dir_promedio.nota1;
		cout<<"\nIngrese Nota 2: "; cin>>alumnos[i].dir_promedio.nota2;
		cout<<"\nIngrese Nota 3: "; cin>>alumnos[i].dir_promedio.nota3;
		
		alumnos[i].dir_promedio.promedio = (alumnos[i].dir_promedio.nota1 + alumnos[i].dir_promedio.nota2 + alumnos[i].dir_promedio.nota3)/3;
		system("cls");
	}
	
	//Mostrar resultados
	
	for(int i=0; i<nAlumnos;i++){
		
		cout<<"Alumno "<<i+1<<endl;
		cout<<"\nNombre: "<<alumnos[i].nombre<<endl;
		cout<<"Sexo: "<<alumnos[i].sexo<<endl;
		cout<<"Nota 1: "<<alumnos[i].dir_promedio.nota1<<endl;
		cout<<"Nota 2: "<<alumnos[i].dir_promedio.nota2<<endl;
		cout<<"Nota 3: "<<alumnos[i].dir_promedio.nota3<<endl;
		cout<<"Promedio: "<<alumnos[i].dir_promedio.promedio<<endl;
		cout<<"\n";
		
	}
	
	system("pause");
	return 0;
}
