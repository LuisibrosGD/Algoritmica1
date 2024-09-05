#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

void registro(float cliente[]);

void descuento(float cliente[]);

void convertir(float cliente[]);

void mostrar(float cliente[]);

int main(){
	/*
	cliente[0]: tipo de cliente
	cliente[1]: importe de compras S/.
	cliente[2]: importe descuento
	cliente[3]: nuevo importe compras S/.
	cliente[4]: nuevo importe en $
	*/
	
	cout<<"Numero de clientes --> 5"<<endl;
	cout<<"Procesando . . ."<<endl;
	system("pause");
	system("cls");
	
	//creando los vectores
	float cliente_1[5],cliente_2[5],cliente_3[5], cliente_4[5],cliente_5[5];
	registro(cliente_1);
	registro(cliente_2);
	registro(cliente_3);
	registro(cliente_4);
	registro(cliente_5);

	//descuento segun el tipo
	
	descuento(cliente_1);
	descuento(cliente_2);
	descuento(cliente_3);
	descuento(cliente_4);
	descuento(cliente_5);

	//convertir a dolares
	
	convertir(cliente_1);
	convertir(cliente_2);
	convertir(cliente_3);
	convertir(cliente_4);
	convertir(cliente_5);
	
	//mostrar resultados
	
	cout<<"\n Cliente 1: "<<endl;
	mostrar(cliente_1);
	cout<<"\n Cliente 2: "<<endl;
	mostrar(cliente_2);
	cout<<"\n Cliente 3: "<<endl;
	mostrar(cliente_3);
	cout<<"\n Cliente 4: "<<endl;
	mostrar(cliente_4);
	cout<<"\n Cliente 5: "<<endl;
	mostrar(cliente_5);
	
	
	system("pause");
	return 0;
}

void registro(float cliente[]){
	float tipo;
	srand(time(NULL));
	do{
	
	cout<<"\nTipo cliente (1), (2), (3) --> ";cin>>tipo;
	
	}while(tipo!=1 && tipo!=2 && tipo!=3);
	cliente[0] = tipo;
	cliente[1] = 1+rand()%2500;
	system("pause");
	system("cls");
}

void descuento(float cliente[]){
	float dscto;
	if (cliente[0]==1){
		dscto = cliente[1]*0.1;
	}
	if(cliente[0]==2){
		dscto = cliente[1]*0.15;
	}
	if (cliente[0]==3){
		dscto = cliente[1]*0.2;
	}
	cliente[2] = cliente[1]- dscto;
}

void convertir(float cliente[]){
	cliente[3] = cliente[2] * 3.5;
}

void mostrar(float cliente[]){
	cout<<"Tipo de cliente: "<<cliente[0]<<endl;
	cout<<"Importe de descuento S/."<<cliente[1]<<endl;
	cout<<"Nuevo importe compras S/."<<cliente[2]<<endl;
	cout<<"Importe en $: $"<<cliente[3]<<endl;
}


