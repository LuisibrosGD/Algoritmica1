#include <iostream>

using namespace std;

void menu(){
	system("cls");
	cout<<"\n\tFUNCIONES CON CADENA DE CARACTERES"<<endl;
	cout<<"1.- Longitud de una cadena"<<endl;
	cout<<"2.- Invertir una Cadena"<<endl;
	cout<<"3.- Concatenar Cadenas"<<endl;
	cout<<"4.- Comparacion de Cadenas"<<endl;
	cout<<"5.- Copiar una Cadena"<<endl;
	cout<<"6.- Converir a Mayusculas/Minusculas"<<endl;
	cout<<"7.- Anadir una cadena de n caraceters a otra"<<endl;
	cout<<"8.- Extraer uan subcadena"<<endl;
	cout<<"9.- Buscar una posicion de un caracter en una cadena"<<endl;
	cout<<"a.- Extrae subcaden desde otra cadena"<<endl;
	
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"Ingresar Opcion ---> ";
}

int main(){
	char opc=' ', w[1], z;
	char x[30], y[30];
	int cant, pos;
	//string x;
	do{
		menu();
		cin>>opc;
		switch(opc){
			case '0':{
				return 0;
				break;
			}
			case '1':{
				cout<<"Ingresar un Texto";
				fflush(stdin);
				cin.getline(x,30); // char
				//getline(cin, x); // string
				cout<<"El texto ingresado tiene ---> "<<strlen(x)<< "caracteres";
				cout<<endl<<endl;
				break;
			}
			case '2':{
				char rev[30];
				cout<<"Ingresar un Texto";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				getline(cin, x); // string
				cout<<"El texto en reversa es ---> "<<strrev(x);
				cout<<endl<<endl;
				/*strcpy(rev, strrev(x));
				cout<<x<<endl;
				cout<<rev<<endl;
				if(strcmp(x, rev) == 0 )
					cout<<"Palindroma "<<x<<" reverso es--> "<<rev<<endl;
				else					
					cout<<"NO es palindroma--> "<<x<< " reverso es--> "<<rev<<endl;
				*/
				break;
			}
			case '3':{
				cout<<"Ingresar un Texto 1 --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				cout<<"Ingresar un Texto 2 --> ";
				//fflush(stdin);
				cin.getline(y,30); // char
				strcat(x, " ");
				cout<<"Union del texto1 y texto 2 es ---> "<<strcat(x, y);
				cout<<endl;
				break;
			}
			case '4':{
				cout<<"Ingresar un Texto 1 --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				cout<<"Ingresar un Texto 2 --> ";
				cin.getline(y,30); // char
				if(strcmp(x, y) == 0 )
					cout<<"Los textos son iguales"<<endl;
				else					
					cout<<"Los textos son Diferentes"<<endl;
				break;
			}
			case '5':{
				cout<<"Ingresar un Texto 1 --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				strcpy(y, x);
				cout<<"EL texto de y es "<<y<<endl;
				break;
			}
			case '6':{
				cout<<"Ingresar un Texto --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				cout<<"EL texto en MAYUSCULAS es "<<strupr(x)<<endl;
				cout<<"EL texto en minusculas es "<<strlwr(x)<<endl;
				break;
			}
			case '7':{
				cout<<"Ingresar un Texto 1 --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				cout<<"Ingresar un Texto 2 --> ";
				cin.getline(y,30); // char
				cout<<"\nResultado---> "<<strncat(x, y, strlen(y))<<endl;
				
				break;
			}
			case '8':{
				cout<<"Ingresar un Texto --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				cout<<"Buscar caracter--> ";cin>>z;
				cout<<endl;
				cout<<"Busqueda del caracter "<<z<<" desde el inicio--> "<<strchr(x, z)<<endl;
				cout<<"Busqueda del caracter "<<z<<" desde el final--> "<<strrchr(x, z)<<endl;
				
				break;
			}			

			case 'a':{
				cout<<"Ingresar un Texto --> ";
				fflush(stdin);
				cin.getline(x,30); // char
				cout<<endl;
				
				cout<<"Buscar posicion--> ";cin>>pos;
				cout<<endl;
				cout<<"Buscar cantidad--> ";cin>>cant;
				cout<<endl;
				
				strncpy(y, x+pos, cant);
				cout<<"LA subcadena extraida es ---> "<<y<<endl;
				
				
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
