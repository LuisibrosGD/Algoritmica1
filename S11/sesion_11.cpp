#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

string nomb, dni, dir, xSueldo;
float sueldo;

void menu(){
	system("cls");
	
	cout<<"\nOperaciones con ARCHIVOS"<<endl;
	cout<<"1. Adicion de registros"<<endl;
	cout<<"2. Lectura de registros"<<endl;
	cout<<"3. Buscar registro"<<endl;
	cout<<"4. Modificar registro"<<endl;
	cout<<"5. Eliminar registro"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"\n\tIngresar opcion --> ";
	
}

//Busqueda de registro
void Buscar( ifstream &lee){
	system("cls");
	string clave;
	bool find=false;
	fflush(stdin);
	cout<<"Ingresar DNI --> ";
	getline(cin, clave);
	
	getline(lee, nomb);
	while(!lee.eof() && !find){
		//getline(nomb)
		getline(lee,dir);
		getline(lee,dni);
		if(dni == clave){
			cout<<"\nNombres y apellidos ----> "<<nomb<<endl;
			cout<<"\nDireccion --------------> "<<dir<<endl;
			cout<<"\nDNI --------------------> "<<dni<<endl;
			cout<<"***************************************"<<endl;
			find = true;
		}
		
		getline(lee,nomb);
	}//while
	
	if(!find){
		cout<<"Registro no existe en el archivo..."<<endl;
		Sleep(2000);
	}
	system("pause");
}

//leer registro
void Lee(ifstream &lee){
	system("cls");
	getline(lee, nomb);
	while(!lee.eof()){
		//getline(lee, nomb);//1er campo
		getline(lee, dir);//2do campo
		getline(lee, dni);//3er campo
		cout<<"\nNombres y apellidos ----> "<<nomb<<endl;
		cout<<"\nDireccion --------------> "<<dir<<endl;
		cout<<"\nDNI --------------------> "<<dni<<endl;
		cout<<"***************************************"<<endl;
		getline(lee, nomb);
	}
	
	getch();
	
	
	
}


//Insertar datos
void Adicionar(ofstream &Grab){ //el &Grab es para pasarle la ruta tambien, sino lo tiene hay que colocar dentro de la funcion
	char opc=' ';
	do{
		fflush(stdin);
		cout<<"***************************"<<endl;
		cout<<"\nNombres y apellidos --> ";
		getline(cin, nomb);
		cout<<"\Direccion -------------> ";
		getline(cin, dir);
		cout<<"\nDNI ------------------> ";
		getline(cin, dni);
		
		Grab<<nomb<<endl;
		Grab<<dir<<endl;
		Grab<<dni<<endl;
		cout<<"\nDesea continuar (S)Si o (N)No --> ";cin>>opc;
		
	}while(opc=='s' || opc=='S');

}
int main(){
	
	char opcion = ' ';
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case '1':{
				
				ofstream Grabacion("D:\\Ingeniería de software\\Ciclo 3\\Algoritmica\\S11\\pruebaTexto.txt", ios::app); //si hubiese puesto ios::out en vez de app, el archivo creado se iba a borrar y no se iba a adicionar texto
				//como lo hace ios::app
				if(Grabacion.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}				
				
				Adicionar(Grabacion);
				Grabacion.close();
				
				break;
			}
			case '2':{
				ifstream Leer("D:\\Ingeniería de software\\Ciclo 3\\Algoritmica\\S11\\pruebaTexto.txt", ios::in);
				if(Leer.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				Lee(Leer);
				Leer.close();
				break;
			}
			
			case '3':{
				ifstream Busca("D:\\Ingeniería de software\\Ciclo 3\\Algoritmica\\S11\\pruebaTexto.txt", ios::in);
				if(Busca.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				Buscar(Busca);
				Busca.close();
				break;
			}
			case '4':{
				ifstream Leer
				break;
			}
			
		}//switch
	}while(opcion !='0');
	
	
	
	
	
	
	
	system("pause");
	return 0;
}
