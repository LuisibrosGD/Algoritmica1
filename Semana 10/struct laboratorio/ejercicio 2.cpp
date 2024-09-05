#include <iostream>
#include <math.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct alumnos{
	char nombre[30];
	char genero;
	float notaMate;
	float notaProgra;
	float notaEstad;
	float promedio;
	
}alumno[20];

struct datos{
	float aprobadosM=0;
	float aprobadosF=0;
	float desaprobadosM=0;
	float desaprobadosF=0;
	float promPonde=0;
	float promAlto=0;
	char nombreAlto[30];
	float promBajo=0;
	char nombreBajo[30];
	float promPondeM=0;
	float promPondeF=0;
	char genAlto;
	char genBajo;
}dato;


int main(){
	
	char opc=' ';
	int numAlumno=0;
	int promNota;
	float promNotafloat;
	float maxNota =0;
	float minNota =21;

	
	do{
		system("cls");
		cout<<"Menu de opciones: "<<endl;
		cout<<endl;
		cout<<"1. Registro de notas"<<endl;
		cout<<"2. Mostrar Estados"<<endl;
		cout<<"3. Promedio ponderado del salon"<<endl;
		cout<<"4. Primer y ultimo puesto"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Digite su opcion: "<<endl; cin >> opc;
		
		switch(opc){
			
			case '1':{
			
				system("cls");
				
				
				cout<<"Ingrese el numero de alumnos: "; cin >> numAlumno;
				fflush(stdin);
				cout<<"Cargando ..."<<endl;
				
				Sleep(500);
				
				for(int i=0; i<numAlumno;i++){
					system("cls");
					cout<<"Alumno "<<i+1<<": \n"<<endl;
					
					cout<<"Ingrese su nombre: "<<endl;
					fflush(stdin);
					cin.getline(alumno[i].nombre, 30, '\n');
					do{
					
					cout<<"Elija su genero (M/F): "; cin>>alumno[i].genero;
					
					if(alumno[i].genero!='f' && alumno[i].genero!='F' && alumno[i].genero!='m' && alumno[i].genero!='M'){
						cout<<"El genero no existe xd"<<endl;
						Sleep(1000);
					}
					
					}while(alumno[i].genero!='f' && alumno[i].genero!='F' && alumno[i].genero!='m' && alumno[i].genero!='M');
					
					fflush(stdin);
					
					cout<<endl;
					cout<<"Ingreso de notas: "<<endl;
					cout<<endl;
					
					do{
						
					cout<<"Matematica: "; cin>>alumno[i].notaMate;
					cout<<"Programacion: "; cin>>alumno[i].notaProgra;
					cout<<"Estadistica: "; cin>>alumno[i].notaEstad;
					
					if((alumno[i].notaMate>20 || alumno[i].notaMate<0) || (alumno[i].notaProgra>20 || alumno[i].notaProgra<0) || (alumno[i].notaEstad>20 || alumno[i].notaEstad<0)){
						cout<<"El rango de notas debe estar entre 0 y 20"<<endl;
						Sleep(400);
					}
					
					}while((alumno[i].notaMate>20 || alumno[i].notaMate<0) || (alumno[i].notaProgra>20 || alumno[i].notaProgra<0) || (alumno[i].notaEstad>20 || alumno[i].notaEstad<0));
					
					promNota = (alumno[i].notaMate + alumno[i].notaProgra + alumno[i].notaEstad)/3;
					
					round(promNota); //redondeando promedio 
					
					alumno[i].promedio = promNota;
					
					if(alumno[i].genero=='m'||alumno[i].genero=='M'){ //masculino
						if(alumno[i].promedio>10){
							dato.aprobadosM = dato.aprobadosM + 1; //m aprobado
						}else if(alumno[i].promedio<=10){
							dato.desaprobadosM = dato.desaprobadosM + 1; //m desaprobado
						}
						dato.promPondeM = dato.promPondeM + alumno[i].promedio;
						
					}else if(alumno[i].genero=='f'||alumno[i].genero=='F'){ //femenino
						if(alumno[i].promedio>10){
							dato.aprobadosF = dato.aprobadosF + 1; //f aprobado
						}else if(alumno[i].promedio<=10){
							dato.desaprobadosF = dato.desaprobadosF + 1; //f desaprobado
						}
						dato.promPondeF = dato.promPondeF + alumno[i].promedio;
						
					}
					
					
					
					if(alumno[i].promedio > maxNota){
						dato.promAlto = alumno[i].promedio;
						maxNota = alumno[i].promedio;
						strcpy(dato.nombreAlto, alumno[i].nombre);
						dato.genAlto = alumno[i].genero;
					}
					if(alumno[i].promedio < minNota){
						dato.promBajo = alumno[i].promedio;
						minNota = alumno[i].promedio;
						strcpy(dato.nombreBajo, alumno[i].nombre);
						dato.genBajo = alumno[i].genero;
					}
					
					cout<<"Registro exitoso"<<endl;
					
				} // for
				
				dato.promPondeM = (dato.promPondeM/(dato.desaprobadosM+dato.aprobadosM));
				dato.promPondeF = (dato.promPondeF/(dato.desaprobadosF+dato.aprobadosF));
					
				dato.promPonde = (dato.promPondeF+dato.promPondeM)/numAlumno;
				
				
				
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				fflush(stdin);
				
				if(numAlumno==0){
					cout<<"\n\nNo hay datos que mostrar :(\n\n"<<endl;
					Sleep(1000);
					break;
					
				}
				
				for(int i=0; i<numAlumno;i++){
					cout<<"\nNombre: \t\t\t"<<alumno[i].nombre<<endl;
					cout<<"Genero: \t\t\t"<<alumno[i].genero<<endl;
					cout<<"Nota Matematica: \t\t"<<alumno[i].notaMate<<endl;
					cout<<"Nota Programacion: \t\t"<<alumno[i].notaProgra<<endl;
					cout<<"Nota Estadistica: \t\t"<<alumno[i].notaEstad<<endl;
					cout<<"Promedio: \t\t\t"<<alumno[i].promedio<<endl;
					cout<<endl;
					cout<<"-----------------------------"<<endl;
				}
				cout<<endl;
				cout<<"\t\tMasculino";cout<<"\t\t\tFemenino"; cout<<"\t\t\t\t Total"<<endl;
				cout<<"Aprobados"; cout<<"\t\t"<<dato.aprobadosM;cout<<"\t\t\t"<<dato.aprobadosF; cout<<"\t\t\t\t\t"<<dato.aprobadosM+dato.aprobadosF<<endl;
				cout<<"Desaprobados"; cout<<"\t\t"<<dato.desaprobadosM; cout<<"\t\t\t"<<dato.desaprobadosF<<"\t\t\t\t\t"<<dato.desaprobadosM+dato.desaprobadosF<<endl;
				cout<<"Total Alumnos"; cout<<"\t\t"<<dato.aprobadosM+dato.desaprobadosM; cout<<"\t\t\t"<<dato.desaprobadosF+dato.aprobadosF; cout<<"\t\t\t\t\t"<<dato.aprobadosM+dato.aprobadosF+dato.desaprobadosM+dato.desaprobadosF<<endl;
				system("pause");
				break;
			}//case 2
			
			case '3':{
				system("cls");
				cout<<endl;
				cout<<"Promedio Masculino: "<<dato.promPondeM<<endl;
				cout<<"Promedio Femenino: "<<dato.promPondeF<<endl;
				cout<<"Promedio ponderado: "<<dato.promPonde<<endl;
				cout<<endl;
				system("pause");
				break;
			}
			
			case '4':{
				system("cls");
				cout<<endl;
				cout<<"Primer lugar: "<<dato.nombreAlto;
				cout<<endl<<endl;
				cout<<"Genero: "<<dato.genAlto<<endl;
				cout<<"Promedio: "<<dato.promAlto<<endl;
				cout<<endl;
				cout<<"Segundo lugar: "<<dato.nombreBajo;
				cout<<endl<<endl;
				cout<<"Genero: "<<dato.genBajo<<endl;
				cout<<"Promedio: "<<dato.promBajo<<endl<<endl;
				system("pause");
				break;
			}
			
			case '0':{
				cout<<endl;
				cout<<"Saliendo del programa"<<endl;
				Sleep(500);
				break;
			}
			default:{
				cout<<"Opcion Invalida"<<endl;
				Sleep(300);
				break;
			}
			
		}
	}while(opc!='0');
	
	
	
	system("pause");
	return 0;
}
