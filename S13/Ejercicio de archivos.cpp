#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Alumno{
	short cdAlumno;
	string nombreAlumno;
}TpAlumno;

struct Curso{
	short cdCurso;
	string nombreCurso;
}TpCurso;

struct Nota{
	short cdAlumno;
	short cdCurso;
	float notaParcial;
	float notaFinal;
	float notaPromedio;
	char estado;
}TpNota;


// ZONA DE FUNCIONES

void f_AdicionaAlumno(ofstream &GrabAlum){
	
	cout<<"\nRegistro de Alumnos"<<endl;
	cout<<"**********************"<<endl;
	cout<<"\nCodigo de Alumno ---> ";
	cin>>TpAlumno.cdAlumno;
	fflush(stdin);
	cout<<"\nNombre de Alumno ---> ";
	getline(cin, TpAlumno.nombreAlumno); 
	GrabAlum<<TpAlumno.cdAlumno<<endl;
	GrabAlum<<TpAlumno.nombreAlumno<<endl;
}

void f_LeeAlumno(ifstream &leeAlum){
	
	//cin>>TpAlumno.cdAlumno ESTA MAL PORQUE ESO AL PRINCIPIO ERA UN SHORT
	//HAY QUE PASARLO PRIMERO A NUMERO
	
	string xCdAlumno;
	
	//lee el primer campo del archivo
	getline(leeAlum,xCdAlumno);
	istringstream(xCdAlumno)>>TpAlumno.cdAlumno; //convirtiendo a numero
	//lee los demas campos
		
	while(!leeAlum.eof()){
		
		getline(leeAlum, TpAlumno.nombreAlumno);
		cout<<"\nCodigo Alumno ---> "<<TpAlumno.cdAlumno;
		cout<<"\nNombre Alumno ---> "<<TpAlumno.nombreAlumno;
		cout<<"\n**************************"<<endl;
		getline(leeAlum,xCdAlumno);
		istringstream(xCdAlumno)>>TpAlumno.cdAlumno;
	}

}

void f_AdicionaCurso(ofstream &GrabCurso){
	
	cout<<"\nRegistro de Cursos"<<endl;
	cout<<"**********************"<<endl;
	cout<<"\nCodigo del curso ---> ";
	cin>>TpCurso.cdCurso;
	fflush(stdin);
	cout<<"\nNombre de Curso ---> ";
	getline(cin, TpCurso.nombreCurso); 
	GrabCurso<<TpCurso.cdCurso<<endl;
	GrabCurso<<TpCurso.nombreCurso<<endl;
}

//Opcion 4: registro curso

void f_LeeCurso(ifstream &leeCurso){
	
	string xCdCurso;
	
	//lee el primer campo del archivo
	getline(leeCurso,xCdCurso);
	istringstream(xCdCurso)>>TpCurso.cdCurso; //convirtiendo a numero
	//lee los demas campos
		
	while(!leeCurso.eof()){
		
		getline(leeCurso, TpCurso.nombreCurso);
		cout<<"\nCodigo del curso ---> "<<TpCurso.cdCurso;
		cout<<"\nNombre del curso ---> "<<TpCurso.nombreCurso;
		cout<<"\n**************************"<<endl;
		getline(leeCurso,xCdCurso);
		istringstream(xCdCurso)>>TpCurso.cdCurso;
	}

}

//Opcion 5

void f_GrabaNota(ifstream &leeAlumno, ifstream &leeCurso, ofstream &grabaNota){
	
	short claveAlum, claveCurso;
	string xCdAlumno, xCdCurso;
	bool find=false;
	
	do{
		fflush(stdin);
		cout<<"Ingresar Codigo de Alumno---> ";cin>>claveAlum;
		getline(leeAlumno,xCdAlumno);
		istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
		
		while(!leeAlumno.eof() && !find ){
		//getline(lee,nom);
			getline(leeAlumno,TpAlumno.nombreAlumno);
			if(TpAlumno.cdAlumno == claveAlum){
				cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno <<endl;
				cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno<<endl;
				cout<<"**************************************"<<endl;
				find = true;
			}
			
			getline(leeAlumno,xCdAlumno);
			istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
		
		}// while
		
		if(find==false){
			cout<<"Codigo de alumno no existe, Ingrese un codigo valido...."<<endl;
			Sleep(2000);
			//rewind( leeAlumno);
			//fseek(leeAlumno,0L,SEEK_SET);
		}
		
	}while(find ==false);
	
	find=false;// reinicializa el flag
	//**********************************
	// Busqueda del Datos del Curso   **
	//**********************************
	//Cosistencia que exista ccodigo del Curso 
	
	do{
		fflush(stdin);
		cout<<"Ingresar Codigo del Curso---> ";cin>>claveCurso;
		getline(leeCurso,xCdCurso);
		istringstream(xCdCurso)>>TpCurso.cdCurso; 
		
		while(!leeCurso.eof()  && !find ){
		//getline(lee,nom);
			getline(leeCurso,TpCurso.nombreCurso);
			if(TpCurso.cdCurso == claveCurso){
				cout<<"\nCodigo Curso-------> "<<TpCurso.cdCurso<<endl;
				cout<<"\nNombre Curso-------> "<<TpCurso.nombreCurso<<endl;
				cout<<"**************************************"<<endl;
				find = true;
			}
			
			getline(leeCurso,xCdCurso);
			istringstream(xCdCurso)>>TpCurso.cdCurso; 
		
		}// while
		
		if(!find){
			cout<<"Codigo de Curso no existe, vuelva a ingresar...."<<endl;
			Sleep(1000);
		}
			
	}while(find == false);
	
	//Grabar registro en tabla nota.txt *****
	
	cout<<"\nNota parcial ---> "; cin>>TpNota.notaParcial;
	cout<<"\nNota final ---> "; cin>>TpNota.notaFinal;
	TpNota.notaPromedio = (TpNota.notaParcial + TpNota.notaFinal)/2;
	if(TpNota.notaPromedio <= 10.5){
		TpNota.estado = 'D';
	}else{
		TpNota.estado = 'A';
	}
	
	//Grabacion en nota.txt
	
	grabaNota<<claveAlum<<endl;
	grabaNota<<claveCurso<<endl;
	grabaNota<<TpNota.notaParcial<<endl;
	grabaNota<<TpNota.notaFinal<<endl;
	grabaNota<<TpNota.notaPromedio<<endl;
	grabaNota<<TpNota.estado<<endl;
}

//void f_Notas(){
void f_Notas(ifstream &leeAlumno,ifstream &leeNota,ifstream &leeCurso){
		
		string  xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio;
		short claveAlum, claveCurso;
		bool find=false;
	
	//*********** Buscar Alumno por Codigo
		fflush(stdin);
		cout<<"Ingresar Codigo de Alumno---> ";cin>>claveAlum;
		getline(leeAlumno,xCdAlumno);
		istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
		
		while(!leeAlumno.eof() && !find ){
		//getline(lee,nom);
			getline(leeAlumno,TpAlumno.nombreAlumno);
			if(TpAlumno.cdAlumno == claveAlum){
				cout<<"\n**************************************";
				cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno;
				cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno;
				cout<<"\n**************************************"<<endl;
				find = true;
			}
			
			getline(leeAlumno,xCdAlumno);
			istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
		
		}// while
		
		if(find==false){
			cout<<"Codigo de alumno no existe, Ingrese un codigo valido...."<<endl;
			Sleep(2000);
			exit;
			}
		// claveAlum tiene el codigo de alumno buscado
		cout<<"Alumno buscado es "<<claveAlum;
	//********************************
	// Busqueda de Notas del Alumno
	//********************************
	//	Recorrido del archivo NOTAS
		getline(leeNota,xCdAlumno);
		istringstream(xCdAlumno)>>TpNota.cdAlumno; 
		//cout<<"alumno "<<TpNota.cdAlumno<<endl;
		while(!leeNota.eof() ){
		//getline(lee,nom);
			getline(leeNota,xCdCurso);
			istringstream(xCdCurso)>>TpNota.cdCurso; 
			//cout<<"curso "<<TpNota.cdCurso<<endl;
			getline(leeNota,xnotaParcial);
				istringstream(xnotaParcial)>>TpNota.notaParcial; 
			getline(leeNota,xnotaFinal);
				istringstream(xnotaFinal)>>TpNota.notaFinal; 
			getline(leeNota,xnotaPromedio);
				istringstream(xnotaPromedio)>>TpNota.notaPromedio; 
			leeNota>>TpNota.estado;
				cout<<endl<<TpNota.cdAlumno;
				cout<<endl<<claveAlum<<endl;
				getch();
			if(TpNota.cdAlumno == claveAlum){
				cout<<"\ndentro del if"<<endl;
				cout<<endl<<TpNota.cdAlumno;
				cout<<endl<<claveAlum<<endl;
				// Buscar nombre del curso
				find=false;
				getline(leeCurso,xCdCurso);
				istringstream(xCdCurso)>>TpCurso.cdCurso; 
				cout<<"\n curso-->"<<TpCurso.cdCurso<<endl;
				
				while(!leeCurso.eof()  && find == false ){
					cout<<"\nLee cursos"<<endl;
				//getline(lee,nom);
					getline(leeCurso,TpCurso.nombreCurso);
						cout<<"\ncompara cursos"<<endl;
						cout<<endl<<TpNota.cdCurso;
						cout<<endl<<TpCurso.cdCurso<<endl;
						cout<<endl<<TpCurso.nombreCurso<<endl;
						getch();
					if(TpNota.cdCurso == TpCurso.cdCurso){
						find=true;
						cout<<"**************************************";
						cout<<"\nNombre Curso-------> "<<TpCurso.nombreCurso<<endl;
						cout<<"**************************************"<<endl;
					
						// Imprime detalle de Notas de cada asignatura 
						cout<<"\nAsignatura-----> "<<TpCurso.nombreCurso;
						cout<<"\nNota Parcial---> "<<TpNota.notaParcial;
						cout<<"\nNota Final-----> "<<TpNota.notaFinal;
						cout<<"\nNota Promedio--> "<<TpNota.notaPromedio;
						cout<<"\nEstado---------> "<<TpNota.estado;
					}//if(TpNota.cdCurso == TpCurso.cdCurso)	
					getline(leeCurso,xCdCurso);
					istringstream(xCdCurso)>>TpCurso.cdCurso;
				}//while(!leeCurso.eof() 
				find = true;
			}//if(xCdAlumno == claveAlumno)
			
			getline(leeNota,xCdAlumno);
			istringstream(xCdAlumno)>>TpNota.cdAlumno; 
			cout<<"alumno "<<TpNota.cdAlumno<<endl;
		
		}// while
		
		
	
}	
//}



void menu(){
	system("cls");
	cout<<"<-- Menu de opciones -->"<<endl;
	cout<<"1. Registro de alumnos"<<endl;
	cout<<"2. Mostrar lista de alumnos"<<endl;
	cout<<"3. Registro de cursos"<<endl;
	cout<<"4. Mostrar lista"<<endl;
	cout<<"5. Registro de notas por alumno"<<endl;
	cout<<"6. Mostrar notas de curso por alumno"<<endl;
	
	cout<<"0. Salir programa"<<endl<<endl;
	
	cout<<"Ingrese opcion ---> ";
	
	
	
}

int main(){
	
	char opc=' ';
	do{
		menu();
		cin>>opc;
		
		switch(opc){
			case '1':{
				//Grabar registros en archivo Alumno.txt
				ofstream GrabaAlumno;
				GrabaAlumno.open("alumno.txt", ios::app);//tambien se puede hace en una sola linea , en el ofstream
				
				f_AdicionaAlumno(GrabaAlumno);//f de funcion
				
				GrabaAlumno.close();
				
				break;
			}
			case '2':{
				//Leer registros en archivo alumno.txt
				ifstream LeeAlumno("alumno.txt", ios::in);
				if(LeeAlumno.fail()){
					cout<<"Error de acceso al archivo alumno.txt..."<<endl;
					//exit(1) te bota del switch
				}
				f_LeeAlumno(LeeAlumno);
				LeeAlumno.close();
				
				
				break;
			}
			case '3':{
				//Grabar registros en archivo Alumno.txt
				ofstream GrabaCurso;
				GrabaCurso.open("cursoo.txt", ios::app);//tambien se puede hace en una sola linea , en el ofstream
				
				f_AdicionaCurso(GrabaCurso);//f de funcion
				
				GrabaCurso.close();
				break;
			}
			case '4':{
				//Leer registros en archivo alumno.txt
				ifstream LeeCurso("cursoo.txt", ios::in);
				if(LeeCurso.fail()){
					cout<<"Error de acceso al archivo alumno.txt..."<<endl;
					//exit(1) te bota del switch
				}
				f_LeeCurso(LeeCurso);
				LeeCurso.close();
				
				break;
			}
			case '5':{
				//manejador INPUT para buscar un alumno
				ifstream LeeAlumno("alumno.txt", ios::in);
				//manejador INPUT para buscar curso
				ifstream LeeCurso("cursoo.txt", ios::in);
				//manejador OUTPUT para grabar las notas
				ofstream GrabaNota("nota.txt", ios::app);
				
				f_GrabaNota(LeeAlumno, LeeCurso, GrabaNota);
				
				LeeAlumno.close();
				LeeCurso.close();
				GrabaNota.close();
				
				break;
			}
			case '6':{
				
				// Buscar un alumno por codigo (INPUT sobre Alumnos.txt)
					ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
				
				// Buscar todas sus notas y mostrar sus asignaturas (INPUT sobre Notas.txt)
					ifstream LeerNota("D:\\Pruebas\\nota.txt", ios::in);
				// Extraer nombre del curso
					ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
					
					//f_Notas(LeerAlumno,LeerNota,LeerCurso);
					
					LeerAlumno.close();
					LeerNota.close();
					LeerCurso.close();
				
				
				
				
				break;
			}
			default:{
				
				cout<<"Opcion invalida"<<endl;
				getch();
			}
		}//switch
		
		system("pause");
	}while(opc!='0');
	
	
	
	system("pause");
	return 0;
}









