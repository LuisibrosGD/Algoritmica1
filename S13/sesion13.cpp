#include <iostream>
#include <conio.h>//getch()
#include <fstream>
#include <sstream>
#include <windows.h>
//#include <stdio.h>

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
	char  estado;
}TpNota;

//******** zona de funciones *********

//**************************************
// ADICIONAR REGISTROS ALUMNOS
//**************************************
void f_AdicionaAlumno( ofstream &GrabAlum ){
		cout<<"\nRegistro de Alumnos"<<endl;
		cout<<"\n********************"<<endl;
	
		cout<<"\nCodigo Alumno----> ";
				cin>>TpAlumno.cdAlumno;
		fflush(stdin);
		cout<<"\nNombre Alumno----> ";
		getline(cin,TpAlumno.nombreAlumno);
		
		GrabAlum<<TpAlumno.cdAlumno<<endl;
		GrabAlum<<TpAlumno.nombreAlumno<<endl;
}
//**************************************
// LEE REGISTROS ALUMNOS
//**************************************
void f_LeeAlumno( ifstream &leeAlum ){
	string xCdAlumno;
	system("cls");
	getline(leeAlum,xCdAlumno);
	istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
	while(!leeAlum.eof()){
		//getline(lee,nom);
		getline(leeAlum,TpAlumno.nombreAlumno);
	
		cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno<<endl;
		cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno<<endl;
	
		cout<<"**************************************"<<endl;
		getline(leeAlum,xCdAlumno);
		istringstream(xCdAlumno)>>TpAlumno.cdAlumno; 
		}

system("pause");
}

//**************************************
// ADICIONAR REGISTROS CURSOS
//**************************************
void f_AdicionaCurso( ofstream &GrabaCurso ){
		cout<<"\nCodigo Curso----> ";
				cin>>TpCurso.cdCurso;
		fflush(stdin);
		cout<<"\nNombre Curso----> ";
		getline(cin,TpCurso.nombreCurso);
		
		GrabaCurso<<TpCurso.cdCurso<<endl;
		GrabaCurso<<TpCurso.nombreCurso<<endl;
}
//**************************************
// LEE REGISTROS CURSOS
//**************************************
void f_LeeCurso( ifstream &leeCurso ){
	string xCdCurso;
	cout<<"\nRegistro de Cursos"<<endl;
	cout<<"\n********************"<<endl;
	getline(leeCurso,xCdCurso);
	istringstream(xCdCurso)>>TpCurso.cdCurso; 
	while(!leeCurso.eof()){
		//getline(lee,nom);
		getline(leeCurso,TpCurso.nombreCurso);
	
		cout<<"\nCodigo Curso-------> "<<TpCurso.cdCurso<<endl;
		cout<<"\nNombre Curso-------> "<<TpCurso.nombreCurso<<endl;
	
		cout<<"**************************************"<<endl;
		getline(leeCurso,xCdCurso);
		istringstream(xCdCurso)>>TpCurso.cdCurso; 
	}

system("pause");
}
//*********************************************************************
//***Opcion 5:  GRABACION DE NOTAS ************************************
//*********************************************************************
void f_GrabaNota(ifstream &leeAlumno, ifstream &leeCurso, ofstream &grabaNota ){
	
	string  xCdAlumno, xCdCurso;
	short claveAlum, claveCurso;
	bool find=false;
	//FILE *leeAlumno;
	//**********************************
	// Busqueda del Datos del Alumno****
	//**********************************
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
	

	//**********************************
	// Ingreso de Notas del Alumno    **
	//**********************************

	cout<<"\nIngresar Nota Parcial ---> ";cin>>TpNota.notaParcial;
	cout<<"\nIngresar Nota Final ---> ";cin>>TpNota.notaFinal;
	TpNota.notaPromedio =(TpNota.notaParcial + TpNota.notaFinal )/2;

	if(	TpNota.notaPromedio <= 10.5)
			TpNota.estado = 'D';
	else
			 TpNota.estado = 'A';

	//*********************************
	// Grabacion en archivo NOTAS.txt
	//*********************************
	grabaNota<<claveAlum<<endl;
	grabaNota<<claveCurso<<endl;
	grabaNota<<TpNota.notaParcial<<endl;
	grabaNota<<TpNota.notaFinal<<endl;
	grabaNota<<TpNota.notaPromedio<<endl;
	grabaNota<<TpNota.estado<<endl;

}
//******************************************************
// opc6.  LISTA DE NOTAS DE ASIGNATURAS POR ALUMNO
//******************************************************
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

//******************************************
// OPCION 7: MODIFICAR NOTAS DEL ALUMNO
//******************************************
void f_modificar(ifstream &leeAlumno, ifstream &leeNota, ifstream &leeCurso, ofstream &reempl) {
    if (!leeAlumno.is_open() || !leeNota.is_open() || !leeCurso.is_open() || !reempl.is_open()) {
        cout << "Error al abrir uno de los archivos." << endl;
        return;
    }

    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio, xestado;
    short claveAlum;
    bool find = false;

    // Buscar Alumno por Codigo
    fflush(stdin);
    cout << "Ingresar Codigo de Alumno---> ";
    cin >> claveAlum;

    leeAlumno.clear();  // Clear any error flags
    leeAlumno.seekg(0); // Go to the beginning of the file

    while (getline(leeAlumno, xCdAlumno)) {
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
        if (TpAlumno.cdAlumno == claveAlum) {
            getline(leeAlumno, TpAlumno.nombreAlumno);
            cout << "\n**************************************";
            cout << "\nCodigo Alumno-------> " << TpAlumno.cdAlumno;
            cout << "\nNombre Alumno-------> " << TpAlumno.nombreAlumno;
            cout << "\n**************************************" << endl;
            find = true;
            break;
        } else {
            // Skip the name line if the code does not match
            getline(leeAlumno, TpAlumno.nombreAlumno);
        }
    }

    if (!find) {
        cout << "Codigo de alumno no existe, Ingrese un codigo valido...." << endl;
        Sleep(2000);
        return;
    }

    leeNota.clear();  // Clear any error flags
    leeNota.seekg(0); // Go to the beginning of the file

    leeCurso.clear();  // Clear any error flags
    leeCurso.seekg(0); // Go to the beginning of the file

    // Busqueda y modificación de Notas del Alumno
    while (getline(leeNota, xCdAlumno)) {
        istringstream(xCdAlumno) >> TpNota.cdAlumno;

        if (TpNota.cdAlumno == claveAlum) {
            getline(leeNota, xCdCurso);
            istringstream(xCdCurso) >> TpNota.cdCurso;
            getline(leeNota, xnotaParcial);
            istringstream(xnotaParcial) >> TpNota.notaParcial;
            getline(leeNota, xnotaFinal);
            istringstream(xnotaFinal) >> TpNota.notaFinal;
            getline(leeNota, xnotaPromedio);
            istringstream(xnotaPromedio) >> TpNota.notaPromedio;
            getline(leeNota, xestado);
            TpNota.estado = xestado[0];

            bool cursoEncontrado = false;
            leeCurso.clear();  // Clear any error flags
            leeCurso.seekg(0); // Go to the beginning of the file

            while (getline(leeCurso, xCdCurso)) {
                istringstream(xCdCurso) >> TpCurso.cdCurso;
                if (TpCurso.cdCurso == TpNota.cdCurso) {
                    getline(leeCurso, TpCurso.nombreCurso);
                    cursoEncontrado = true;
                    break;
                } else {
                    // Skip the course name line if the code does not match
                    getline(leeCurso, TpCurso.nombreCurso);
                }
            }

            if (cursoEncontrado) {
                cout << "Curso: " << TpCurso.nombreCurso << endl;
                cout << "Nota Parcial Actual: " << TpNota.notaParcial << endl;
                cout << "Nota Final Actual: " << TpNota.notaFinal << endl;
                cout << "Nota Promedio Actual: " << TpNota.notaPromedio << endl;
                cout << "Estado Actual: " << TpNota.estado << endl;
                cout << "**************************************" << endl;

                // Modificación de las notas
                cout << "Ingresar Nueva Nota Parcial ---> ";
                cin >> TpNota.notaParcial;
                cout << "Ingresar Nueva Nota Final ---> ";
                cin >> TpNota.notaFinal;
                TpNota.notaPromedio = (TpNota.notaParcial + TpNota.notaFinal) / 2;
			}
		}
	}
}



void menu(){
system("CLS");

cout<<"\tMENU DE OPCIONES"<<endl<<endl;
cout<<"1.- Registro de Alumnos "<<endl;
cout<<"2.- Lista de Alumnos "<<endl;
cout<<"3.- Registro de Cursos "<<endl;
cout<<"4.- Lista de Cursos "<<endl;
cout<<"5.- Registro de Notas por alumno"<<endl;
cout<<"6.- Mostrar Notas de Alumno"<<endl;
cout<<"7.- Modificar Notas por Alumno "<<endl;
cout<<"8.- Registrar profesores"<<endl;
cout<<"9.- Lista de profesores"<<endl;

cout<<"0.- SALIR PROGRAMA"<<endl<<endl;

cout<<"Ingrese Opcion ---> ";


} 

//****** MAIN ******************
int main() {
	
	 char genero, opc=' ';
    do{
		menu();
    	cin>>opc;
    	system("CLS");
    	switch(opc){
    		// Registro de Alumnos
    		case '1':{
    			
			
				//Grabacion en archivo Alumno.txt
			    			
    			ofstream GrabaAlumno;
				GrabaAlumno.open("D:\\Pruebas\\alumno.txt", ios::app);
				f_AdicionaAlumno(GrabaAlumno);
				GrabaAlumno.close();
				break;
			}
			case '2':{
				ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
				if(LeerAlumno.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				f_LeeAlumno(LeerAlumno);
				LeerAlumno.close();
				
				break;
			}
			
			case '3':{
				
				//Grabacion en archivo Curso.txt	    			
    			ofstream GrabaCurso("D:\\Pruebas\\curso.txt", ios::app);
				f_AdicionaCurso(GrabaCurso);
				GrabaCurso.close();
				break;
			}
			
			case '4':{
				ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
				if(LeerCurso.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				f_LeeCurso(LeerCurso);
				LeerCurso.close();

				
				break;
			}
			case '5':{
				// Manejador INPUT para Busqueda de un alumno
				ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
				// Manejador INPUT para Busqueda de  un curso
				ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
				// Manejador OUPUT para grabar notas
				ofstream GrabaNota("D:\\Pruebas\\nota.txt", ios::app);
				f_GrabaNota(LeerAlumno,LeerCurso, GrabaNota );
				//CIerre de archivos
				LeerAlumno.close();
				LeerCurso.close();
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
					
					f_Notas(LeerAlumno,LeerNota,LeerCurso);
					
					LeerAlumno.close();
					LeerNota.close();
					LeerCurso.close();
					
				break;
			}
			case '7':{
				ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
				ifstream LeerNota("D:\\Pruebas\\nota.txt", ios::in);
				ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
				
					ofstream ReemplNota("D:\\Pruebas\\destino.txt", ios::out);
					
					f_modificar(LeerAlumno,LeerNota,LeerCurso,ReemplNota);
					LeerAlumno.close();
					LeerNota.close();
					LeerCurso.close();
					ReemplNota.close();
					//***** faltan... eliminacion de nuevo.txt y rename de destino.txt
					remove("D:\\Pruebas\\nota.txt");
					rename("D:\\Pruebas\\destino.txt", "D:\\Pruebas\\nota.txt");
					
				break;
			}
			case '8':{
				
				break;
			}
			case '9':{
				
				break;
			}
		}//switch
    cout<<"\n\nPresione una tecla para continuar....";		
	getch();

		}while(opc != '0');
	
    	
	
	return 0;
}
