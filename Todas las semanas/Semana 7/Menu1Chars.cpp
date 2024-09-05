#include <iostream>
#include <stdio.h>


using namespace std;

void menu(){
	system("cls");
	cout<<"\n\t"<<endl;
	cout<<"1.- Uso del GET y PUT "<<endl;
	cout<<"2.- Uso del Printf y Scanf"<<endl;
	cout<<"3.- Uso del cin.getline() y getline()"<<endl;
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"Ingresar Opcion ---> ";
}

int main(){
	char opc=' ';
char a[30],b[30];
	string nombre;
	do{
	
		menu();
		cin>>opc;
		fflush(stdin);
		switch(opc){
			case '0':{
				return 0;
				break;
			}
			case '1':{
				cout<<" Ingresar una cadena --> ";
				gets(b);
				cout<<endl;
				cout<<"La cadena ingresada es -->";
				puts(b);
	
				break;
			}
			case '2':{
			char valor;	
			char nombre[30];
			/*
				printf("\nInsertar un caracter--> ");
				int lee = scanf("%c",&valor);
				printf("He leido  %d posiciones.valor = %c\n",lee,valor);
			*/
			
			/*	// Manejo del Printf y Scanf
				printf("\nInsertar un nombre--> ");
				int lee = scanf("%s",nombre);
				printf("He leido  %d posiciones.valor = %s\n",lee,nombre);
			
			*/				
			
				// Manejo del Printf y Scanf
			/*
			//limitando
					char texto[10];
				printf("\nInsertar un nombre--> ");
				int lee = scanf("%9s",texto);
				printf("He leido  %d posiciones.valor = %s\n",lee,texto);
				
			// USANDO fgets()
				printf("\nInsertar un nombre--> ");
				fgets(nombre, 30, stdin);
				printf("He leido  valor = %s\n",nombre);
				cout<<"Valor es "<<nombre;
			*/	
			// Usando scanf cadena
				char texto[10];
				printf("\nInsertar un nombre--> ");
				int lee = scanf("%[^\n]",texto);//[a-zA-z]
				printf("He leido  %d posiciones.valor = %s\n",lee,texto);
				
				break;
			}
			case '3':{
						
				//Uso del  cin cout
				cout<<" Ingresar una cadena con char --> ";
				//cin>>b;
				cin.getline(b, 20); // Se usa cuando trabajamos con vector tipó char ... ejm char x[10]
				cout<<endl<<"La cadena ingresada es --> "<<b;
				cout<<endl;
				
				// Uso de String
				cout<<" Ingresar una cadena con string --> ";
				getline(cin, nombre);
				cout<<endl<<"La cadena ingresada es --> "<<nombre;
				cout<<endl;
				break;
			}
			case '4':{
				break;
			}
			
					
			default:{
				cout<<"ERROR..Seleccione uande las opciones permitidas"<<endl;
				break;
			}
		}
		
		system("pause");	
	}while(opc != '0');
	
	
	cout<<endl;

	
	
	
	
}
