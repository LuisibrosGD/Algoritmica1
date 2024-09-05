#include <iostream>
#include <string.h>
using namespace std;

void menu(){
	system("cls");
	cout<<"\n\tFUNCIONES CON CADENA DE CARACTERES"<<endl;
	cout<<"1.- Longitud de una cadena 					"<<endl;
	cout<<"2.- Invertir una cadena    					"<<endl;
	cout<<"3.- Concatenar cadenas    				    "<<endl;
	cout<<"4.- COmparacion de cadenas 					"<<endl;
	cout<<"5.- Copiar una cadena      					"<<endl;
	cout<<"6.- Convertir Mayusculas/Minusculas           "<<endl;
	cout<<"7.- Añadir una cadena de n caracteres a otra "<<endl;
	cout<<"8.- Buscar una posicion desde otra cadena"<<endl;
	cout<<"9.- Extrae subcadena desde otra cadena"<<endl;
	
	
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"Ingresar Opcion ---> ";
}

int main(){
	char opc=' ', x[30], y[30], tc[1],z;
	int n, cant, pos;
	string texto;
	do{
		system("CLS");
		menu();
		cin>>opc;
		fflush(stdin);
		switch(opc){
			case '0':{
				return 0;
				break;
			}
			case '1':{
			
				cout<<"Ingrese primer texto en char ---> ";
				cin.getline(x,20);
				cout<<"El primer texto ingresado es (char) ---> "<<x<<" y tiene "<<strlen(x)<<" caracteres"<<endl;
				cout<<"Ingrese segundo texto en string ---> ";
				fflush(stdin);
				getline(cin,texto);
				cout<<"El segundo texto ingresado es (string)---> "<<texto<<" y tiene "<<texto.size()<<" caracteres"<<endl;
				
				break;
			}
			case '2':{
				cout<<"Ingrese texto ---> ";
				cin.getline(x,20);
				cout<<"El texto ingresado es ---> "<<x<<endl;
				cout<<"El texto inverso es   ---> "<<strrev(x)<<endl;
					
				break;
			}
			case '3':{
				cout<<"Ingrese primer texto ---> ";
				cin.getline(x,20);
				cout<<"Ingrese segundo texto ---> ";
				cin.getline(y,20);
				strcat(x," ");
				strcat(x,y);
				cout<<"El texto concatenado es ---> "<<x<<endl;;
				
				break;
			}
			case '4':{
				cout<<"Ingrese contrasenia     ---> ";
				cin.getline(x,20);
				cout<<"Reingrese su contrasenia ---> ";
				cin.getline(y,20);
				//n=strcmp(x,y);
				//if(x==y)..error
								
				if(strcmp(x,y)==0){
					cout<<" Las claves ingresadas son iguales..";
				}
				else{
					cout<<" Las claves son diferentes....";
				}
				cout<<endl;
				break;
			}
			case '5':{
				cout<<"Ingrese dia de hoy  ---> ";
				cin.getline(x,20);
				strcpy(y, x);
				//y=x;... error
				cout<<" El dia de hoy es --> "<<y<<endl;
				
				break;
			}
				case '6':{
					cout<<"Ingrese un texto  ---> ";
					cin.getline(x,20);
					cout<<"El texto en mayusculas es ---> "<<strupr(x)<<endl;
					cout<<"El texto en minusculas es ---> "<<strlwr(x)<<endl;
					
					cout<<"Ingrese Tipo de Cliente (a, b)  ---> ";
					
					cin>>tc;
					strcpy(tc, strlwr(tc));
					//cout<<"el dato ingresado es "<<tc;
					if(strcmp(tc,"a") ==0)
						cout<<"tipo de cliente es a"<<endl;
					else
						cout<<"tipo de cliente es b"<<endl;	
					
					break;
				}
				case '7':{
					cout<<"Ingrese primer texto ---> ";
					cin.getline(x,20);
					cout<<"Ingrese segundo texto ---> ";
					fflush(stdin);
					cin.getline(y,20);
					cout<<endl;
					cout<<"\nResultado---> "<<strncat(x, y, 2)<<endl;
						//cout<<"\nResultado---> "<<strncat(x, y, strlen(y))<<endl;
					
					
					break;
				}
				case '8':{
					cout<<"Ingrese texto ---> ";
					cin.getline(x,20);
					fflush(stdin);
					cout<<"Buscar caracter---> ";
					cin>>z;
					cout<<endl;
					cout<<"Busqueda del caracter--> "<<z<<" desde la izquierda--> "<<strchr(x,z)<<endl;
					cout<<"Busqueda del caracter--> "<<z<<" desde la derecha--> "<<strrchr(x,z)<<endl;
					cout<<endl;
										
					break;
				}	
				
				case '9':{
					fflush(stdin);
					cout<<"Ingrese texto ---> ";
					cin.getline(x,20);
					cout<<endl;
					fflush(stdin);
					cout<<"Buscar posicion---> ";cin>>pos;
					cout<<"Extraer cantidad--> ";cin>>cant;
					cout<<endl;
					strncpy(y,x+pos,cant);
					cout<<"LA subcadena extraida es "<<y<<endl;
					
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
