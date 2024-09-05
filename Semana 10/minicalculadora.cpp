#include <iostream>


using namespace std;

int main(){
	
	double resultado;
	double n1,n2;
	int opc1,opc2;
	
	do{
		fflush(stdin);
		cout<<"Ingrese 2 numeros: "<<endl;
		cout<<"Numero 1: "; cin>>n1;
		cout<<endl;
		cout<<"Numero 2: "; cin>>n2;
	
		cout<<"\nElija la opcion a realizar"<<endl;
		cout<<"1. Sumar"<<endl;
		cout<<"2. Restar"<<endl;
		cout<<"3. Multiplicar"<<endl;
		cout<<"4. Dividir"<<endl;
		cin>>opc1;
		switch(opc1){
			case 1:{
				resultado = n1 + n2;
				break;
			}
			case 2:{
				resultado = n1 - n2;
				break;
			}
			case 3:{
				resultado = n1 * n2;
				break;
			}
			case 4:{
				if(n2==0){
					cout<<"ERROR"<<endl;
					system("pause");
					break;
				}
				resultado = n1/n2;
				break;
			}
		}
		cout<<"El resultado es: "<<resultado<<endl;
		cout<<"\n Desea continuar? 1 -> Si / 0 -> No"<<endl;
		cin>>opc2;
		system("cls");
	}while(opc2!=0);
	
	system("pause");
	return 0;
}
