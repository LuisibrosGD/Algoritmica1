#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
/*
autor:luis junior alfredo bizarro ortiz
*/

struct obrero{
	char nombre[30];
	float jornal_en;
	float jornal_fe;
	float jornal_ma;
	float j_suma;
	float j_prom;
	float p_desc;
	float imp_desc;
	float bono;
	float imp_neto;

}ob[15];

// posicion del cursor en pantalla (col 80 y 25 filas)
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

using namespace std;  

void menu(){
	system("CLS");
	cout<<"Laboratorio 10"<<endl;
	cout<<"\n1.- Ejercicio 1";
	cout<<"\n2.- Ejercicio 2";
	cout<<"\n0.- Salir";
	cout<<"\n\nIngresar Opcion----> ";
	
}

int main(){
	
	char opc=' ';
	int n;
	float j_suma, j_prom;
	
	do{
		menu();
		cin>>opc;
		switch(opc){
			case '0':{
				break;
			}
			case '1':{
				
				do{
				
				cout<<"Digite la cantidad de obreros: "<<endl;
				cin>>n;
				
				float jornal[n];
				
				if(n<0 || n>15){
					cout<<"La cantidad de obreros debe ser menor o igual que 15"<<endl;
				}
				
				}while(n<0 || n>15);
				
				for(int i=0;i<n;i++){
					j_suma=0;
					j_prom=0;
					cout<<"\nObrero "<<i+1<<endl;
					cin.ignore();
					cout<<"\nNombre: "; cin.getline(ob[i].nombre,30,'\n');
					do{
					
						cout<<"\nIngrese jornal del mes de enero: "; cin>>ob[i].jornal_en;
					
						if(ob[i].jornal_en<400 || ob[i].jornal_en>800){
							cout<<"Jornal debe estar entre S/ 400 y S/. 800"<<endl;
						}
					
					}while(ob[i].jornal_en<400 || ob[i].jornal_en>800);
					
					do{
					
						cout<<"\nIngrese jornal del mes de febrero: "; cin>>ob[i].jornal_fe;
					
						if(ob[i].jornal_fe<400 || ob[i].jornal_fe>800){
							cout<<"Jornal debe estar entre S/ 400 y S/. 800"<<endl;
						}
					
					}while(ob[i].jornal_fe<400 || ob[i].jornal_fe>800);
					
					do{
					
						cout<<"\nIngrese jornal del mes de marzo: "; cin>>ob[i].jornal_ma;
					
						if(ob[i].jornal_ma<400 || ob[i].jornal_ma>800){
							cout<<"Jornal debe estar entre S/ 400 y S/. 800"<<endl;
						}
					
					}while(ob[i].jornal_ma<400 || ob[i].jornal_ma>800);
					
					j_suma = j_suma + ob[i].jornal_en + ob[i].jornal_fe + ob[i].jornal_ma;
					j_prom = j_suma / 3;
					ob[i].j_suma = j_suma;
					ob[i].j_prom = j_prom;
					
					//descuento
					
					if (j_suma<1500){
						ob[i].p_desc = 0.03;
					}else{
						ob[i].p_desc = 0.05;
					}
					ob[i].imp_desc = ob[i].p_desc * j_suma;
					
					//bonificacion
					
					if (j_prom<500){
						ob[i].bono = 100;
					}else{
						ob[i].bono = 50;
					}
					
					ob[i].imp_neto = j_suma - ob[i].imp_desc + ob[i].bono;
						
				}
				
				system("cls");
				cout<<"\nMostrar Datos: \n"<<endl;
				cout<<"Obrero		Enero	Febrero	Marzo		Importe		Prom	%dscto		Imp.dscto	Bonif	importe Neto"<<endl;
				cout<<"____________________________________________________________________________________________________________"<<endl;
				for(int i=0; i<n;i++){
						
					cout<<ob[i].nombre<<"		"<<ob[i].jornal_en<<"	"<<ob[i].jornal_fe<<"	"<<ob[i].jornal_ma<<"		"<<ob[i].j_suma<<"		"<<ob[i].j_prom<<"	"<<ob[i].p_desc<<"		"<<ob[i].imp_desc<<"		"<<ob[i].bono<<"	"<<ob[i].imp_neto<<endl;
				
				}//for(int i=0; i<n;i++){
				
				
				
				break;
			}
			case '2':{
				
				break;
			}
		}//cerrar switch
		getch();
	}while(opc!='0');
	
	
	getch();
	return 0;
}
