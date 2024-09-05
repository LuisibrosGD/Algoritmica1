#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

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

}nAlumno1, nAlumno2, *p1, *p2;

struct persona{
	char nombre[20];
	int edad, dni;
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
		
 }reg;
 // reg.trabajador.nombre


//typedef(struct alumno alias);
//alumno nAlumno1, nAlumno2;

//alias p1, p2;




// posicion del cursor en pantalla (col 80 y 25 filas)
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

void menu(){
	system("CLS");
	cout<<"Menu Opciones Struct"<<endl;
	cout<<"\n1.- Ingreso de un registro de alumno";
	cout<<"\n2.- Ingreso del Arreglos mostrar vertical";
	cout<<"\n3.- Ingreso del Arreglos mostrar Tabla";
	cout<<"\n4.- Estructura Anidada";
	cout<<"\n0.- Salir";
	cout<<"\n\nIngresar Opcion----> ";
	
}

int main(){
	char opcion = ' ';
	float porcAfp=0.20;
	int n=0;
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case '0':{
				break;
			}
			case '1':{
				system("cls");
				cout<<"\nCodigo-------> ";cin>>nAlumno1.codigo;	
				fflush(stdin);
				cout<<"\nApellidos----> ";
				getline(cin,nAlumno1.apellidos);	
				cout<<"\nNombres------> ";
				getline(cin,nAlumno1.nombres);	
			
				cout<<"\nEdad---------> ";cin>>nAlumno1.edad;	
				cout<<"\nTrabaja------> ";cin>>nAlumno1.trabaja;		
				cout<<"\nGenero-------> ";cin>>nAlumno1.genero;
				cout<<"\nSueldo Neto--> ";cin>>nAlumno1.sueldoBase;
				
				// Mostra valores ingresados
				cout<<endl<<endl;
				cout<<"\nCodigo-------> "<<nAlumno1.codigo;	
				cout<<"\nApellidos-------> "<<nAlumno1.apellidos;
				cout<<"\nNombres------> "<<nAlumno1.nombres;	
				cout<<"\nEdad---------> "<<nAlumno1.edad;	
				cout<<"\nTrabaja------> "<<nAlumno1.trabaja;		
				cout<<"\nGenero-------> "<<nAlumno1.genero;
				cout<<"\nSueldo Base--> "<<nAlumno1.sueldoBase;
				cout<<endl<<endl;
				nAlumno1.afp = nAlumno1.sueldoBase * porcAfp;
				cout<<"\nAporte AFP---> "<<nAlumno1.afp;
				nAlumno1.sueldoNeto = nAlumno1.sueldoBase - nAlumno1.afp;
				cout<<"\nSueldo Neto--> "<<nAlumno1.sueldoNeto;
			
				break;
			}
			
			case '2':{
				 system("cls");
				cout<<"\nIngresar cantidad de alumnos ---> ";cin>>n;
				alumno  arrayAlumno[n];
				for(int i=0; i<n;i++){
					
					system("cls");
					cout<<"\nCodigo-------> ";cin>>arrayAlumno[i].codigo;	
					fflush(stdin);
					cout<<"\nApellidos----> ";
					getline(cin,arrayAlumno[i].apellidos);	
					cout<<"\nNombres------> ";
					getline(cin,arrayAlumno[i].nombres);	
				
					cout<<"\nEdad---------> ";cin>>arrayAlumno[i].edad;	
					cout<<"\nTrabaja------> ";cin>>arrayAlumno[i].trabaja;		
					cout<<"\nGenero-------> ";cin>>arrayAlumno[i].genero;
					cout<<"\nSueldo Base--> ";cin>>arrayAlumno[i].sueldoBase;
					
					arrayAlumno[i].afp = arrayAlumno[i].sueldoBase * porcAfp;
					arrayAlumno[i].sueldoNeto = arrayAlumno[i].sueldoBase - arrayAlumno[i].afp;
				}//for(int i=0; i<n;i++){
				
				// Mostrar Datos ingresados
				
					system("cls");
				for(int i=0; i<n;i++){
					
				
					cout<<"\nCodigo-------> "<<arrayAlumno[i].codigo;	
					cout<<"\nApellidos----> "<<arrayAlumno[i].apellidos;	
					cout<<"\nNombres------> "<<arrayAlumno[i].nombres;	
					cout<<"\nEdad---------> "<<arrayAlumno[i].edad;	
					cout<<"\nTrabaja------> "<<arrayAlumno[i].trabaja;		
					cout<<"\nGenero-------> "<<arrayAlumno[i].genero;
					cout<<"\nSueldo Base--> "<<arrayAlumno[i].sueldoBase;
					cout<<"\nDesc AFP-----> "<<arrayAlumno[i].afp;
					cout<<"\nSueldo Neto--> "<<arrayAlumno[i].sueldoNeto;
					cout<<"\n***********************************************";
				
				}//for(int i=0; i<n;i++){				
				
				cout<<endl;
			
			
				
				
				break;
			}
						case '3':{
				 system("cls");
				cout<<"\nIngresar cantidad de alumnos ---> ";cin>>n;
				alumno  arrayAlumno[n];
				for(int i=0; i<n;i++){
					
					system("cls");
					cout<<"\nCodigo-------> ";cin>>arrayAlumno[i].codigo;	
					fflush(stdin);
					cout<<"\nApellidos----> ";
					getline(cin,arrayAlumno[i].apellidos);	
					cout<<"\nNombres------> ";
					getline(cin,arrayAlumno[i].nombres);	
				
					cout<<"\nEdad---------> ";cin>>arrayAlumno[i].edad;	
					cout<<"\nTrabaja------> ";cin>>arrayAlumno[i].trabaja;		
					cout<<"\nGenero-------> ";cin>>arrayAlumno[i].genero;
					cout<<"\nSueldo Base--> ";cin>>arrayAlumno[i].sueldoBase;
					
					arrayAlumno[i].afp = arrayAlumno[i].sueldoBase * porcAfp;
					arrayAlumno[i].sueldoNeto = arrayAlumno[i].sueldoBase - arrayAlumno[i].afp;
				}//for(int i=0; i<n;i++){
				
				// Mostrar Datos ingresados
				
					system("cls");
				for(int i=0; i<n;i++){
					
				
					gotoxy(2, i+2);cout<<arrayAlumno[i].codigo;	
					gotoxy(8, i+2);	cout<<arrayAlumno[i].apellidos;	
					gotoxy(25, i+2);cout<<arrayAlumno[i].nombres;	
					gotoxy(40, i+2);cout<<arrayAlumno[i].edad;	
					gotoxy(44, i+2);cout<<arrayAlumno[i].trabaja;		
					gotoxy(47, i+2);cout<<arrayAlumno[i].genero;
					gotoxy(50, i+2);cout<<arrayAlumno[i].sueldoBase;
					gotoxy(60, i+2);cout<<arrayAlumno[i].afp;
					gotoxy(65, i+2);cout<<arrayAlumno[i].sueldoNeto;
				
				
				}//for(int i=0; i<n;i++){				
				
				cout<<endl;
			
			
				
				
				break;
			}
			
			case '4':{
				cout<<"Nombre del trabajador---> ";
				cin.getline(reg.trabajador.nombre,15);
				
				
				break;
			}
			
		}//switch
		
		getch();//system("pause") usar #include <conio.h>;	
	}while(opcion != '0');
	
	
	
	
	  
	return 0;
}