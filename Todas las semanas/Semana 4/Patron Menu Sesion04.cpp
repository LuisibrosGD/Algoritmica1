#include <iostream>

using namespace std;

void menu(){
system("CLS");

cout<<"\tMENU DE OPCIONES"<<endl<<endl;
cout<<"1.- Opcion 1  "<<endl;
cout<<"2.- Opcion 2  "<<endl;
cout<<"3.- Opcion 3  "<<endl;

cout<<"0.- SALIR PROGRAMA"<<endl<<endl;

cout<<"Ingrese Opcion ---> ";


} 


int main(){
	char opcion;
	do{
		
		menu();
		cin>>opcion;
		
		switch(opcion){
			case '1':{
				cout<<"Opcion 1 elegida"<<endl;
				
				break;
			}
			case '2':{
				cout<<"Opcion 2 elegida"<<endl;
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
