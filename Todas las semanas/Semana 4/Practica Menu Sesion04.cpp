#include <iostream>

using namespace std;

short i=0, j=0;

void menu(){
system("CLS");

cout<<"\tMENU DE OPCIONES"<<endl<<endl;
cout<<"1.- Muestra valores impares en un rango de 1 a 20 "<<endl;
//cout<<"2.- Consistencia valores tipo CHAR "<<endl;
cout<<"2.- Acumula valores enteros"<<endl;
cout<<"3.- Mostrar valores impares y sus acumulados"<<endl;
cout<<"4.- Visualizar Tablas de multiplicar entre dos numeros"<<endl;
cout<<"5.- Factorial de un numero"<<endl;

cout<<"0.- SALIR PROGRAMA"<<endl<<endl;

cout<<"Ingrese Opcion ---> ";


} 


int main()
{
		char opcion;
		short n,m,suma=0;
		short r1, r2,max;
	do{
		
		menu();
		fflush(stdin);//limpia buffer
		cin>>opcion;
		
		switch(opcion){
			case '1':{
				//1.- Muestra valores impares en un rango de n a m (n<=m)
				
				do{
					system("cls");
					cout<<"\nIngresar rango inferior---> ";cin>>n;
					cout<<"\nIngresar rango superior---> ";cin>>m;
					if(n>m){
						cout<<" \nRango de valores no valido..."<<endl;
						system("pause");
					}
				}while(n>m);
				
				
				
				if(n%2 ==0){
					n++;
				}
				while(n<=m){
					i++;
					cout<<"\nimpar nr-> "<<i<<"es--> "<<n;
					suma=suma+n;
					n=n+2;
				}
				
				cout<<"\nLa suma acumulada es--> "<<suma<<endl;
				cout<<"\nLa cantidad de impares es--> "<<i<<endl;
				
				break;
			}
			case '4':{
					system("cls");
					cout<<"\nIngresar Tabla de multiplicar desde---> ";cin>>r1;
					cout<<"\nIngresar Tabla de multiplicar hasta---> ";cin>>r2;
					
					cout<<"\nIngresar cantidad de mult por tabla---> ";cin>>max;
					for(j=r1;j<=r2;j++ ){
						cout<<endl<<"Tabla del "<<j<<endl;
						cout<<"************************** "<<endl<<endl;
						for(i=1;i<=max;i++){
						cout<<endl;
						cout<<i<<" X "<<j<<" = "<<j*i<<endl;
						}
					cout<<endl;	
											
					}
					
					
					
					
				break;
			}
			case '3':{
				cout<<"Opcion 3 elegida"<<endl;
				break;
			}
			case '0':{
				break;
			}
			default:{
				cout<<"Error.. Opcion no valida"<<endl;
				//break;
			}
			
		}
		
		system("pause");	
		
	}while( opcion!= '0');	
}

