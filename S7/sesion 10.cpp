#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct alumno{
	int codigo;
	string apellidos;
	string nombres;
	int edad;
	bool trabaja;
	char genero;
	float sueldoBase;
	float sueldoNeto;
	float afp;
}nAlumno1, nAlumno2, arrayAlumno[2];

//NOTA MENTAL: datos numericos que no se usan para calculos, mejor se usa como caracter

struct persona{
	char nombre[20];
	int edad, dni;
	long telefono;
	 
};

struct telefono{
	int celular1;
	int celular2;
	int fijo;
	
};

struct registro{
	persona trabajador;
	persona empleador;
	telefono tel_trab;
	telefono tel_empl;
};

//esto es una forma de registrar alumnos 1,2,3,...
//alumno nAlumno1, nAlumno2;

void menu(){
	system("cls");
	cout<<"Menu Opciones Struct"<<endl;
	cout<<"\n1.- Ingreso de dos registros de alumnos";
	cout<<"\n2.- Ingreso del arreglo";
	cout<<"\n3.- Estructura anidada";
	cout<<"\n0.- Salir";
	cout<<"\n\nIngresar Opcion ---> ";
}

int main(){
	char opcion = ' ';
	float porc_afp = 0.2;
	int n;
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case '0':{
				
				break;
			}
			case '1':{
				system("cls");
				cout<<"\nCodigo --> ";cin>>nAlumno1.codigo;
				cin.ignore();
				cout<<"\nApellidos ----> ";
				getline(cin, nAlumno1.apellidos);
				cout<<"\nNombres ------> ";
				getline(cin, nAlumno1.nombres);
				cout<<"\nEdad ---------> ";cin>>nAlumno1.edad;
				cout<<"\nTrabaja Si(1) No(0) ------> "; cin>>nAlumno1.trabaja;
				cout<<"\nGenero -------> "; cin>>nAlumno1.genero;
				cout<<"\nSueldo Base ---> "; cin>>nAlumno1.sueldoBase;
				
				
				//mostrar valores ingresados
				cout<<endl<<endl;
				cout<<"\nCodigo --------> "<<nAlumno1.codigo;
				cout<<"\nApellidos --------> "<<nAlumno1.apellidos;
				cout<<"\nNombres --------> "<<nAlumno1.nombres;
				cout<<"\nEdad --------> "<<nAlumno1.edad;
				cout<<"\nTrabaja --------> "<<nAlumno1.trabaja;
				cout<<"\nGenero --------> "<<nAlumno1.genero;
				cout<<"\nSueldo Base --------> "<<nAlumno1.sueldoBase;
				nAlumno1.afp = nAlumno1.sueldoBase * porc_afp;
				cout<<"\nAporte AFP ----> "<<nAlumno1.afp;
				nAlumno1.sueldoNeto = nAlumno1.sueldoBase - nAlumno1.afp;
				cout<<"\nSueldo Neto --------> "<<nAlumno1.sueldoNeto;
				
				break;
			}
			case '2':{
				system("cls");
				cout<<"\nIngresar cantidad de alumnos ---> "; cin>>n;
				alumno arrayAlumno[n];
				for(int i=0; i<n;i++){
					system("cls");
					cout<<"Registro "<<i+1<<endl;
					cout<<"\nCodigo --> ";cin>>arrayAlumno[i].codigo;
					cin.ignore();
					cout<<"\nApellidos ----> ";
					getline(cin, arrayAlumno[i].apellidos);
					cout<<"\nNombres ------> ";
					getline(cin, arrayAlumno[i].nombres);
					cout<<"\nEdad ---------> ";cin>>arrayAlumno[i].edad;
					cout<<"\nTrabaja Si(1) No(0) ------> "; cin>>arrayAlumno[i].trabaja;
					cout<<"\nGenero -------> "; cin>>arrayAlumno[i].genero;
					cout<<"\nSueldo Base ---> "; cin>>arrayAlumno[i].sueldoBase;
					arrayAlumno[i].afp = arrayAlumno[i].sueldoBase * porc_afp;
					arrayAlumno[i].sueldoNeto = arrayAlumno[i].sueldoBase - arrayAlumno[i].afp;
					
				}
				
				//mostrar datos ingresados
				
				for(int i=0; i<n;i++){
					cout<<endl<<endl;
				cout<<"\nCodigo --------> "<<arrayAlumno[i].codigo;
				cout<<"\nApellidos --------> "<<arrayAlumno[i].apellidos;
				cout<<"\nNombres --------> "<<arrayAlumno[i].nombres;
				cout<<"\nEdad --------> "<<arrayAlumno[i].edad;
				cout<<"\nTrabaja --------> "<<arrayAlumno[i].trabaja;
				cout<<"\nGenero --------> "<<arrayAlumno[i].genero;
				cout<<"\nSueldo Base --------> "<<arrayAlumno[i].sueldoBase;
		
				cout<<"\nDescuento AFP ----> "<<arrayAlumno[i].afp;
			
				cout<<"\nSueldo Neto --------> "<<arrayAlumno[i].sueldoNeto;
				
				cout<<"- - - - - - - - - - - - - - - - - - "<<endl;
				
				}
				break;
			}
		}
			getch();
	}while(opcion!='0');
		

	return 0;
}
