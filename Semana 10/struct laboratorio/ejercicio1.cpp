#include <iostream>
#include <windows.h>

using namespace std;

struct obreros{
	char nombre[30];
	float jornalsuma=0;
	float jornal_ene=0;
	float jornal_feb=0;
	float jornal_mar=0;
	float importe=0;
	float prom=0;
	float dscto=0;
	float imp_dscto=0;
	float bonif=0;
	float importeTotalNeto=0;
}obrero[15];

void condicionJornal(float jornalMes);

int main(){
	
	char opc = ' ';
	
	int numObrero=0,j;
	
	
	do{
		system("cls");
		cout<<"\n\tMenu de opciones\n"<<endl;
		cout<<"1. Registro de obreros"<<endl;
		cout<<"2. Mostrar datos"<<endl;
		cout<<"0. Salir"<<endl;
		cin>>opc;
		switch(opc){
			case '1':{
				
				system("cls");
				
				//registrar datos
				fflush(stdin);
				cout<<"Cuantos obreros desea registrar?: "<<endl;
				cin>>numObrero;
	
				cout<<"\t\nREGISTRO DE DATOS: \n"<<endl;
				
				for(int i=0;i<=numObrero-1;i++){
					
					fflush(stdin);
					
					cout<<"\nObrero "<<i+1<<": "<<endl;
		
					cout<<"Ingrese su nombre: "; cin.getline(obrero[i].nombre,30,'\n');
					cout<<endl;
		
					do{
		
						cout<<"Ingrese el jornal de enero: S/. "; cin>>obrero[i].jornal_ene;
		
						condicionJornal(obrero[i].jornal_ene);
		
					}while(obrero[i].jornal_ene<400 || obrero[i].jornal_ene>800);
		
					do{
		
						cout<<"Ingrese el jornal de febrero: S/. "; cin>>obrero[i].jornal_feb;
		
						condicionJornal(obrero[i].jornal_feb);
		
					}while(obrero[i].jornal_feb<400 || obrero[i].jornal_feb>800);
		
					do{
		
						cout<<"Ingrese el jornal de marzo: S/. "; cin>>obrero[i].jornal_mar;
		
						condicionJornal(obrero[i].jornal_mar);
		
					}while(obrero[i].jornal_mar<400 || obrero[i].jornal_mar>800);
		
					//importe
		
					obrero[i].jornalsuma = obrero[i].jornal_ene + obrero[i].jornal_feb + obrero[i].jornal_mar;
		
					//promedio
		
					obrero[i].prom = obrero[i].jornalsuma / 3;
		
					//descuento
		
					if(obrero[i].jornalsuma<1500){
						obrero[i].dscto = 0.03;
					}else{
						obrero[i].dscto = 0.05;
					}
		
					//importe descuento
		
					obrero[i].imp_dscto = obrero[i].jornalsuma * obrero[i].dscto;
		
					//bonificacion
		
					if(obrero[i].prom<500){
						obrero[i].bonif = 100;
					}else{
						obrero[i].bonif = 50;
					}
		
					//importe total neto
		
					obrero[i].importeTotalNeto = obrero[i].jornalsuma - obrero[i].imp_dscto + obrero[i].bonif;
		
				}
				j=numObrero;
				break;
			}
			case '2':{
				
				system("cls");
				cout<<endl;
				fflush(stdin);
				if(j == 0){
					cout<<"Primero ingrese datos"<<endl;
					system("pause");
					break;
				}
				
				for(int i=0; i<=j-1; i++){
					cout<<"Nombre: \t\t"<<obrero[i].nombre<<endl;
					cout<<"Enero: \t\t\tS/."<<obrero[i].jornal_ene<<endl;
					cout<<"Febrero: \t\tS/."<<obrero[i].jornal_feb<<endl;
					cout<<"Marzo: \t\t\tS/."<<obrero[i].jornal_mar<<endl;
					cout<<"Importe: \t\tS/."<<obrero[i].jornalsuma<<endl;
					cout<<"Promedio: \t\tS/."<<obrero[i].prom<<endl;
					cout<<"Porcentaje descuento: \t"<<obrero[i].dscto<<"%"<<endl;
					cout<<"Importe descuento: \tS/."<<obrero[i].imp_dscto<<endl;
					cout<<"Bonificacion: \t\tS/."<<obrero[i].bonif<<endl;	
					cout<<"Importe total neto: \tS/."<<obrero[i].importeTotalNeto<<endl;
					cout<<"-------------------------------"<<endl;
				}
				system("pause");
				break;
			}
			
		}
	}while(opc!='0');
	
	
	system("pause");
	return 0;
}


void condicionJornal(float jornalMes){
	if(jornalMes<400 || jornalMes>800){
		cout<<"El jornal debe estar entre S/.400 y S/. 800"<<endl;
	}
}


