#include <iostream>
#include <fstream>
#include <sstream> //istringstream(xSueldo)>>sueldo;
//#include <string.h>
//#include <control.h>
#include <windows.h>

using namespace std;

string nom, dir, dni, xSueldo;
float sueldo;
//**************************************
// ELIMINACION DE REGISTRO
//**************************************
void Eliminar( ifstream &lee, ofstream &reempl ){
	system("cls");
	string clave;
	bool find=false;
	fflush(stdin);
	cout<<"Ingresar DNI--> ";
	getline(cin, clave);
	// Lectura de los registros
	getline(lee,nom);
//	while(!lee.eof() && !find ){
	while(!lee.eof() ){
	//getline(lee,nom);
		getline(lee,dir);
		getline(lee,dni);
		getline(lee, xSueldo);
		if(dni == clave){
			cout<<"\n...Se ha eliminado el registro:"<<endl; 		
			cout<<"\nNombres y Apellidos-------> "<<nom<<endl;
			cout<<"\nDireccion-----------------> "<<dir<<endl;
			cout<<"\nDNI-----------------------> "<<dni<<endl;
			cout<<"\nSueldo--------------------> "<<xSueldo<<endl;
			cout<<"**************************************"<<endl;
			find = true;
			Sleep(1000);
		}else{
			reempl<<nom<<endl;
			reempl<<dir<<endl;
			reempl<<dni<<endl;
			reempl<<xSueldo<<endl;
			
		}
		
		getline(lee,nom);
	
	}//while
		if(find ==false){
			cout<<"Registro no existe en el archivo... "<<endl;
			system("pause");
		}

}



//**************************************
// MODIFICACION DE REGISTRO
//**************************************
void Modificar( ifstream &lee, ofstream &reempl ){
	system("cls");
	string clave, newname;
	float newsueldo;
	bool find=false;
	fflush(stdin);
	cout<<"Ingresar DNI--> ";
	getline(cin, clave);
	// Lectura de los registros
	getline(lee,nom);
//	while(!lee.eof() && !find ){
	while(!lee.eof() ){
	//getline(lee,nom);
		getline(lee,dir);
		getline(lee,dni);
		getline(lee, xSueldo);
		if(dni == clave){
			cout<<"\nNombres y Apellidos-------> "<<nom<<endl;
			cout<<"\nDireccion-----------------> "<<dir<<endl;
			cout<<"\nDNI-----------------------> "<<dni<<endl;
			cout<<"\nSueldo--------------------> "<<xSueldo<<endl;
			cout<<"**************************************"<<endl;
			cout<<"\n Ingresar Nuevo Nombre---> ";
			fflush(stdin);
			getline(cin,newname);
			cout<<"\n Ingresar Nuevo Sueldo---> ";cin>>newsueldo;
			reempl<<newname<<endl;
			reempl<<dir<<endl;
			reempl<<dni<<endl;
			reempl<<newsueldo<<endl;
			
			find = true;
		}else{
			reempl<<nom<<endl;
			reempl<<dir<<endl;
			reempl<<dni<<endl;
			reempl<<xSueldo<<endl;
			
		}
		
		getline(lee,nom);
	
	}//while
	
		if(find ==false){
			cout<<"Registro no existe en el archivo... "<<endl;
			system("pause");
		}

}





//**************************************
// BUSCQUEDA de REGISTRO
//**************************************
void Buscar( ifstream &lee ){
	system("cls");
	string clave;
	bool find=false;
	fflush(stdin);
	cout<<"Ingresar DNI--> ";
	getline(cin, clave);
	
	getline(lee,nom);
	while(!lee.eof() && !find ){
	//getline(lee,nom);
		getline(lee,dir);
		getline(lee,dni);
		getline(lee, xSueldo);
		if(dni == clave){
			cout<<"\nNombres y Apellidos-------> "<<nom<<endl;
			cout<<"\nDireccion-----------------> "<<dir<<endl;
			cout<<"\nDNI-----------------------> "<<dni<<endl;
			cout<<"\nSueldo--------------------> "<<xSueldo<<endl;
			cout<<"**************************************"<<endl;
			find = true;
		}
		
		getline(lee,nom);
	
	}// while
	
	if(!find){
		cout<<"Registro no existe en el archivo...."<<endl;
		Sleep(2000);
	}
		system("pause");
	
}




//**************************************
// LECTURA DE  REGISTROS
//**************************************
void Lee( ifstream &lee ){
system("cls");
getline(lee,nom);
while(!lee.eof()){
	//getline(lee,nom);
	getline(lee,dir);
	getline(lee,dni);
	getline(lee, xSueldo);
	//getline(lee,xSueldo);
	cout<<"\nNombres y Apellidos-------> "<<nom<<endl;
	cout<<"\nDireccion-----------------> "<<dir<<endl;
	cout<<"\nDNI-----------------------> "<<dni<<endl;
	cout<<"\nSueldo--------------------> "<<xSueldo<<endl;
	istringstream(xSueldo)>>sueldo;
	cout<<"\nDescuento--------------------> "<<sueldo-(.20*sueldo)<<endl;
	
	cout<<"**************************************"<<endl;
	getline(lee,nom);
	}

system("pause");
}


//**************************************
// ADICIONAR REGISTROS
//**************************************
void Adicionar( ofstream &Grab ){
	char opc;
	do{
		fflush(stdin);
		cout<<"*******************************"<<endl;
		cout<<"\nNombres y Apellidos-------> ";
		getline(cin,nom);
		cout<<"\nDireccion-----------------> ";
		getline(cin,dir);
		cout<<"\nDNI-----------------------> ";
		getline(cin,dni);
		cout<<"\nSUELDO--------------------> ";cin>>sueldo;
		
		
		Grab<<nom<<endl;
		Grab<<dir<<endl;
		Grab<<dni<<endl;
		Grab<<sueldo<<endl;
		cout<<"\nDesea continuar (S)i o (N)o--> ";cin>>opc;
		
	}while(opc =='s'|| opc == 'S');
	
}

void menu(){
	system("cls");
	
	cout<<"\n\tOPERACIONES CON ARCHIVOS"<<endl;
	cout<<"1.- Adicion de Registros"<<endl;
	cout<<"2.- Lectura de Registros"<<endl;
	cout<<"3.- Buscar registro"<<endl;
	cout<<"4.- Modificar Registro"<<endl;
	cout<<"5.- Eliminar Registro"<<endl;
	cout<<"0.- Salir"<<endl;
	cout<<"\n\tIngresar Opcion---> ";
	
}


int main(){

	char opcion=' ';
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case '1':{
				ofstream Grabacion("D:\\Pruebas\\nuevo.txt", ios::app);
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
				ifstream Leer("D:\\Pruebas\\nuevo.txt", ios::in);
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
				ifstream Leer("D:\\Pruebas\\nuevo.txt", ios::in);
					if(Leer.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				Buscar(Leer);
				Leer.close();
				
				
				break;
			}
			
			case '4':{
				
					ifstream Leer("D:\\Pruebas\\nuevo.txt", ios::in); 
					ofstream Reempl("D:\\Pruebas\\destino.txt", ios::out);
					Modificar(Leer,Reempl);
					Leer.close();
					Reempl.close();
					//***** faltan... eliminacion de nuevo.txt y rename de destino.txt
					remove("D:\\Pruebas\\nuevo.txt");
					rename("D:\\Pruebas\\destino.txt", "D:\\Pruebas\\nuevo.txt");
					
				
				break;
			}
			case '5':{
				
					ifstream Leer("D:\\Pruebas\\nuevo.txt", ios::in); 
					ofstream Reempl("D:\\Pruebas\\destino.txt", ios::out);
					Eliminar(Leer,Reempl);
					Leer.close();
					Reempl.close();
					//***** faltan... eliminacion de nuevo.txt y rename de destino.txt
					remove("D:\\Pruebas\\nuevo.txt");
					rename("D:\\Pruebas\\destino.txt", "D:\\Pruebas\\nuevo.txt");
					
				
				break;
			}
		}	// switch
		
		
		
		
		
	}while(opcion != '0');
	
	
	
	
return 0;	
}
