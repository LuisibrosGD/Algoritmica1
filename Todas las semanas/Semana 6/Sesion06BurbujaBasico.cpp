#include <iostream>
#include <stdlib.h>     
#include <time.h>  

using namespace std;
// Global

void menu(){
   system("CLS");
   cout<<"\n\tMENU"<<endl;
   cout<<"1.- Burbuja		"<<endl;
   cout<<"2.- Seleccion"<<endl;
   cout<<"\n0.- Salir   	"<<endl;		
   cout<<"\n\nIngresar Opcion ---> ";
}


int main() {
	char opc=' ';
	int i=0, j=0, n=0, t=0;
	bool flag=true;
	srand(time(NULL));
	
	do{
		menu();
		cin>>opc;
		system("CLS");
		switch(opc){
			
			case '0':
				break;
			case '1':{
			 	cout<<"Ingresar cantidad de elementos ---> ";cin>>n;
				int r[n];
				for(i=0; i<n;i++){
				 	r[i]=1+rand()%200;
				 	cout<<i+1<<"--> "<<r[i]<<endl;
				}
				system("pause");
				
				
				cout<<"Ordeando por Burbuja"<<endl;
				for(j=0;(j<n-1 && flag==true );j++){
					flag=false;
					for(i=0; i<n-1;i++){
				 		if(r[i] > r[i+1]){
						   t=r[i];
						   r[i]=r[i+1];
						   r[i+1] = t;
						   flag=true;
					
						}//if
				 	}// for i
					cout<<"Pasada--> " <<j<<endl;
					for(i=0; i<n;i++){
						cout<<i+1<<"--> "<<r[i]<<endl;
					}
					
				}//for j
				

				// Mostra lista Ordenada
				cout<<endl;
				for(i=0; i<n;i++){
					cout<<i+1<<"--> "<<r[i]<<endl;
				}
				//rbuja();
				break;
				}
			case '2':{
				//impares();
				break;
			}
			default:
				cout<<"ERROR: Opcion invalida";
				
				
		} //switch
		cout<<endl<<endl;
		system("PAUSE");
		
	}while(opc != '0');
	
	
	return 0;
}
