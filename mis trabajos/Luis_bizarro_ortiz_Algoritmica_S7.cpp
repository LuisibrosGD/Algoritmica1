#include <iostream>
#include <string.h>

using namespace std;

void menu(){
	system("cls");
	cout<<"\n\tCadena de caracteres"<<endl;
	cout<<"Opcion 1: Operaciones con caracteres "<<endl;
	cout<<"Opcion 2: miniscula e inversa"<<endl;
	cout<<"Opcion 3: Efectos"<<endl;
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"Ingresar Opcion ---> ";
}



int main(){
	
	char opc;
	char x[41], texto[11];
	int cont_a=0, cont_e=0, cont_i=0, cont_o=0, cont_u=0;
	char frase[50];
	int contad=0, contad2=0;
	
	do{
		menu();
		cin>>opc;
		
		
		switch (opc){
			case '1':
				{	
					cout<<"Ingrese cadena de texto: "<<endl;
					fflush(stdin);
					cin.getline(x,41);
					
					//texto a mayusculas
					cout<<"El texto en mayusculas es ---> "<<strupr(x)<<endl;
					//Frecuencia por cada vocal
					for (int i=0; i<41; i++){
						if (x[i] == 'a' || x[i] == 'A')
							{
							cont_a = cont_a + 1;
							}
						if (x[i] == 'e' || x[i] == 'E')
							{
							cont_e = cont_e + 1;
							}
						if (x[i] == 'i' || x[i] == 'I')
							{
							cont_i = cont_i + 1;
							}		
						if (x[i] == 'o' || x[i] == 'O')
							{
							cont_o = cont_o + 1;
							}
						if (x[i] == 'u' || x[i] == 'U')
							{
							cont_u = cont_u + 1;
							}	
					}
					cout<<"Frecuencia por la vocal a: "<<cont_a<<endl;
					cout<<"Frecuencia por la vocal e: "<<cont_e<<endl;
					cout<<"Frecuencia por la vocal i: "<<cont_i<<endl;
					cout<<"Frecuencia por la vocal o: "<<cont_o<<endl;
					cout<<"Frecuencia por la vocal u: "<<cont_u<<endl;
					
					//cantidad de palabras
					
					for(int i = 0; x[i] != ' ';i++){
						contad = contad + 1;
					}
					
			
					
					cout<<"La palabra 1 tiene "<<contad<<" palabras."<<endl;

					
					//cout<<"La frase ingresada contiene "<<ContarPalabras(x)<<" palabras."<<endl;
					
					//longitud de cada palabra
					
					
					
					//longitud de toda la expresion
					
					cout<<"El texto ingresado tiene "<<strlen(x)<<" caracteres"<<endl;
					
					
					
   				
					
					
					
					
					system("pause");					
					break;
				} 
			
			
			
			case '2':
				{
					cout<<"Ingrese una frase: "<<endl;
					fflush(stdin);
					cin.getline(frase,50);
					
					if(strcmp(strlwr(frase),strrev(frase))==0){
						cout<<"Las frases ingresadas son iguales..";
					}
					
				}
			
			case '3':
				{
					
				}
			
			case '0':
				{
				return 0;
				break;	
				}
			system("pause");	
		}
		
		
		
		
		
		
		
		
		
		

	}while(opc != '0');
	
	
	
	
	system("pause");
	return 0;
}

