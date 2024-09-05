#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

struct alumnos{
	short cdAlumno;
	string nombreAlumno;
}alumno;

struct notas{
	short cdAlumno;
	short cdCurso;
	float notaParcial;
	float notaFinal;
	float notaPromedio;
	char estado;
}nota;

struct cursos{
	short cdCurso;
	string nombreCurso;
	short creditos;
	short cdProfesor;
}curso;

struct profesores{
	short cdProfesor;
	string nombreProfesor;
}profesor;

//funciones

// * * * * * * menu

void menu1();
void menu2();
void menu3();
void menu4();

int main(){
	
	char opc1=' ', opc2=' ', opc3=' ', opc4=' ';
	
	do{//menu general
		menu1();
		cin>>opc1;
		switch(opc1){
			case '1':{ // MENU PROFESORES
				system("cls");
				cout<<endl;
				
				do{
					menu2();
					cin>>opc2;
					switch(opc2){
						case '1':{ //registro
							ofstream prof_registro;
							prof_registro.open("profesores.txt", ios::app);
							if(prof_registro.fail()==true){
								cout<<"Error al crear el archivo"<<endl;
								Sleep(1000);
								exit(1);
							}else{

								cout<<"Ingrese su codigo: "; cin>>profesor.cdProfesor;
								
								fflush(stdin);
								cout<<"Ingrese su nombre: "; getline(cin, profesor.nombreProfesor);
								
								prof_registro<<profesor.cdProfesor;
								prof_registro<<endl;
								prof_registro<<profesor.nombreProfesor;
								prof_registro<<endl;
								
							}
							
							prof_registro.close();
							
							cout<<"Registro exitoso"<<endl;
							Sleep(700);
							
							break;
						}//case 1
						case '2':{//Mostrar profesores
							ifstream profesores;
							profesores.open("profesores.txt",ios::in);
							if(profesores.fail()==true){
								cout<<"Error al abrir el archivo"<<endl;
								Sleep(500);
								exit(1);
							}else{
								while(!profesores.eof()){
									string xcdProfesor;
									getline(profesores, xcdProfesor);
									istringstream(xcdProfesor)>>profesor.cdProfesor;
									getline(profesores, profesor.nombreProfesor);
									cout<<profesor.cdProfesor<<"\t\t"<<profesor.nombreProfesor<<endl;
									
								}
								profesores.close();
								system("pause");
								cout<<endl<<"Volviendo al menu profesores"<<endl;
								Sleep(500);
							}
							
							break;
						}
						case '0':{
							cout<<"Volviendo al menu principal"<<endl;
							fflush(stdin);
							Sleep(500);
							break;
						}
						default:{
							cout<<"Opcion invalida"<<endl;
							fflush(stdin);
							Sleep(1000);
							break;
						}
					}//switch profesores
				}while(opc2!='0');
				break;
			}
			case '2':{ //MENU ALUMNOS
				do{
				menu3();
				cin>>opc3;
				switch(opc3){
					case '1':{ //registro alumnos
						system("cls");
						ofstream estud_registro;
						fflush(stdin);
						estud_registro.open("alumno.txt", ios::app);
						if(estud_registro.fail()==true){
							cout<<"Error al crear archivo alumno"<<endl;
							Sleep(750);
							exit(1);
						}else{
							
							cout<<"Ingrese su codigo: "; cin>>alumno.cdAlumno; //max 5 caracteres
							fflush(stdin);
							
							cout<<"Ingrese su nombre: "; getline(cin, alumno.nombreAlumno);
							
							estud_registro<<alumno.cdAlumno<<endl;
							estud_registro<<alumno.nombreAlumno<<endl;
							
							estud_registro.close();
							
							cout<<"Registro exitoso"<<endl;
							Sleep(500);
						}
						
						break;
					}
					case '2':{ //mostrar lista
					system("cls");
						ifstream estud_lista;
						estud_lista.open("alumno.txt", ios::in);
						if(estud_lista.fail()==true){
							cout<<"Error al abrir el archivo porque no hay alumnos"<<endl;
							Sleep(500);
							exit(1);
						//	remove("alumno.txt");
						}else{
							cout<<endl<<"Lista de estudiantes"<<endl;
							while(!estud_lista.eof()){
								string xcdAlumno;
								getline(estud_lista, xcdAlumno);
								getline(estud_lista, alumno.nombreAlumno);
								istringstream(xcdAlumno)>>alumno.cdAlumno;
								cout<<"Codigo: "<<alumno.cdAlumno<<endl;
								cout<<"Alumno: "<<alumno.nombreAlumno<<endl;
								cout<<"******************************"<<endl;
							}
							
						}
						estud_lista.close();
						
						system("pause");
						break;
					}
					case '3':{//registro de notas
						ofstream notas_registro;
						ofstream curso_leer;
						notas_registro.open("notas.txt", ios::app);
						curso_leer.open("curso.txt", ios::in);
						if(notas_registro.fail()==true){
							cout<<"Error al crear el archivo notas, verifique si hay curso"<<endl;
							Sleep(500);
							exit(1);
						}else{
							
						}
						
						break;
					}
				}//switch
				}while(opc3!='0');
				break;
			}
			case '3':{
				do{
					menu4();
					cin>>opc4;
					switch(opc4){
						case '1':{//registro cursos
							ofstream cursos_registro;
							cursos_registro.open("cursos.txt", ios::app);
							if(cursos_registro.fail()==true){
								cout<<"Error. No se pudo crear el archivo cursos.txt"<<endl;
								Sleep(500);
								exit(1);
							}else{
								cout<<endl;
								cout<<"Ingrese el codigo del curso: "; cin>>curso.cdCurso;
								fflush(stdin);
								cout<<"Ingrese el nombre del curso: "; getline(cin, curso.nombreCurso);
								cout<<"Numero de creditos a asignar: "; cin>>curso.creditos;
								fflush(stdin);
								
								cout<<"Codigo del profesor: "; cin>>profesor.cdProfesor;//se asume que ya te sabes el codigo del profesor
								fflush(stdin);
								cursos_registro<<curso.cdCurso<<endl;
								cursos_registro<<curso.nombreCurso<<endl;
								cursos_registro<<curso.creditos<<endl;
								cursos_registro<<profesor.cdProfesor<<endl;
								
							}
							
							cursos_registro.close();
							cout<<"Registro exitoso"<<endl;
							Sleep(500);
							break;
						}
						case '2':{//mostrar cursos
							ifstream lee_curso, lee_profesor;
							lee_curso.open("curso.txt", ios::in);
							lee_profesor.open("profesores.txt", ios::in);
							if(lee_curso.fail()==true && lee_profesor.fail()==true){
								cout<<"Error al abrir los archivos.txt"<<endl;
								Sleep(500);
								exit(1);
							}else{
								
								
								
								while(!lee_curso.eof() && !lee_profesor.eof()){
									fflush(stdin);
									string xcdProfesor, xcreditos,xcdCurso;
									
									getline(lee_curso, xcdCurso);
									getline(lee_curso, curso.nombreCurso);
									getline(lee_curso, xcreditos);
									getline(lee_curso, xcdProfesor);
									
									istringstream(xcdCurso)>>curso.cdCurso;
									istringstream(xcreditos)>>curso.creditos;
									istringstream(xcdProfesor)>>profesor.cdProfesor;
									
									string linea;
									short codBuscadorProfe;
									
									bool flag = false;
									
									while(!lee_profesor.eof() && flag == true){
										getline(lee_profesor, linea);
										istringstream(linea)>>codBuscadorProfe;
										if(codBuscadorProfe==profesor.cdProfesor){
											getline(lee_profesor, profesor.nombreProfesor);
											flag==false;
										}	
									}
									
									
									cout<<"Curso: "<<curso.nombreCurso<<endl;
									cout<<"Creditos: "<<curso.creditos<<endl;
									cout<<"Profesor: "<<profesor.nombreProfesor<<endl;
									cout<<"***************************"<<endl;
								}//while (todo)
							}
							lee_curso.close();
							lee_profesor.close();
							system("pause");
							break;
						}
						case '0':{
							cout<<"Volviendo al menu principal"<<endl;
							Sleep(500);
							break;
						}
						default:{
							
							cout<<"opcion invalida"<<endl;
							Sleep(500);
							break;
						}
					}
				}while(opc4!='0');
				break;
			}
			case '0':{
				cout<<"Saliendo del programa"<<endl;
				Sleep(500);
				break;
			}
			default:{
				cout<<"Opcion invalida"<<endl;
				break;
				Sleep(500);
			}
		}
	}while(opc1!='0');
	
	system("pause");
	return 0;
}

void menu1(){ //general
	system("cls");
	cout<<"\n\t\tSistema de matricula humilde\n"<<endl;
	cout<<"1. Profesor"<<endl;
	cout<<"2. Alumno"<<endl;
	cout<<"3. Cursos (Ingresar solo coordinadores)"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Ingresar opcion --> ";
}

void menu2(){ // profesores
	system("cls");
	cout<<"Bienvenido profesor"<<endl<<endl;
	cout<<endl;
	cout<<"1. Registrarse en un curso"<<endl;
	cout<<"2. Mostrar lista de profesores(actualizar)"<<endl;
	cout<<"0. Salir"<<endl<<endl;
	cout<<"Ingresar opcion: ";
}

void menu3(){ //alumnos
	system("cls");
	cout<<endl<<"Bienvenido Estudiante"<<endl;
	cout<<endl<<"1. Registrarse"<<endl;
	cout<<"2. Mostrar lista"<<endl;
	cout<<"3. Registrar notas por curso"<<endl;
	cout<<"4. Mostrar notas"<<endl;
	cout<<"5. Modificar notas"<<endl;
	cout<<"0. Salir del programa"<<endl;
	cout<<"Ingrese su opcion --> ";
}

void menu4(){
	system("cls");
	cout<<endl;
	cout<<"REGISTRO DE CURSOS UNIVERSITARIOS"<<endl;
	cout<<"1. Registrar curso"<<endl;
	cout<<"2. Mostrar cursos"<<endl;
	cout<<"0. Salir del programa"<<endl;
	cout<<"Ingrese su opcion --> ";
}

