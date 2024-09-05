#include <iostream>

using namespace std;

int main(){
	double resultado;
	double n1, n2;
	int opc1, opc2;
	do{
		
		cout<<"Digite 2 numeros: "<<endl;
		cout<<"Numero 1: "; cin>>n1;
		cout<<endl;
		cout<<"Numero 2: "; cin>>n2;
		cout<<endl;
		cout<<"¿Que operacion desea realizar?"<<endl;
		cout<<"\n1. Sumar"<<endl;
		cout<<"2. Restar"<<endl;
		cout<<"3. Multiplicar"<<endl;
		cout<<"4. Dividir"<<endl;
		cout<<"Ingresar opcion --> ";
		cin>>opc1;
		
		switch(opc1){
			case 1:{
				resultado = n1+n2;
				break;
			}
			case 2:{
				resultado = n1-n2;
				break;
			}
			case 3:{
				resultado = n1*n2;
				break;
			}
			case 4:{
				if(n2==0){
					cout<<"No se puede dividir"<<endl;
					break;
				}
				resultado = n1/n2;
				
				break;
			}
			default:{
				cout<<"Opcion invalida"<<endl;
			}
		}//switch
		
		cout<<"El resultado es: "<<resultado;
		
		cout<<"\n ¿Desea continuar? Presione 0 para salir, o cualquier tecla para reiniciar"<<endl;
		cin>>opc2;
		
		system("cls");
		
	}while(opc2 != 0);
	
	
	
	
}
