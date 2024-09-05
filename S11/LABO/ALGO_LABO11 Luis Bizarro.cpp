#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

//declarando variables
int codigo;
char desc[31], marca[31];
int stockAct, stockMin;
float precioUnit;
char categ;
float dscto, valorTotal, valorFinal, igv, maxDscto;

//menu
void menu();
//ingreso datos
void Adicionar(ofstream &registro);
//ver Lista de productos
void verProd(ifstream &lista);

int main(){
		
	char opcion = ' ';
	do{
		menu();
		cin>>opcion;
		switch (opcion){
			case '1':{
				ofstream rDatos("D:\\Ingeniería de software\\Ciclo 3\\Algoritmica\\S11\\LABO\\registroDatos.txt", ios::app); 
				if(rDatos.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}				
				
				Adicionar(rDatos);
				rDatos.close();
				break;
			}
			case '2':{
				ifstream vista("D:\\Ingeniería de software\\Ciclo 3\\Algoritmica\\S11\\LABO\\registroDatos.txt", ios::in);
				if(vista.fail()){
					cout<<"Error en el archivo..."<<endl;
					Sleep(2000);
					exit(1);
				}
				verProd(vista);
				vista.close();
				break;
			}
		}//switch
	}while(opcion!='0');
	
	
	system("pause");
	return 0;
}
//menu
void menu(){
	system("cls");
	
	cout<<"\nOperaciones con ARCHIVOS"<<endl;
	cout<<"1. Registro de datos"<<endl;
	cout<<"2. Ver lista de productos"<<endl;
	cout<<"3. Obtener los resultados"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"\n\tIngresar opcion --> ";
}
//registro de datos, opcion 1
void Adicionar(ofstream &registro){
	float dscto = 0, valorTotal = 0, valorFinal = 0, igv = 0, maxDscto = 0;
	char opc=' ';
	//int i=1;
	do{
		fflush(stdin);
		
		cout<<"- - - - - - - - - - - - - -"<<endl;
		//registro<<"Producto "<<i<<": "<<endl;
		cout<<"\nCodigo del producto ---------> ";
		cin>>codigo;
		fflush(stdin);
		cout<<"\nDescripcion ------------------> ";
		cin.getline(desc, 31,'\n');
		fflush(stdin);
		cout<<"\nMarca -----------------------> ";
		cin.getline(marca, 31,'\n');
		fflush(stdin);
		cout<<"\nStock Actual ----------------> ";
		cin>>stockAct;
		fflush(stdin);
		cout<<"\nStock Minimo ----------------> ";
		cin>>stockMin;
		fflush(stdin);
		cout<<"\nPrecio unitario ------------> ";
		cin>>precioUnit;
		fflush(stdin);
		cout<<"\nCategoria producto (1,2,3) --> ";
		cin>>categ;
		fflush(stdin);
		cout<<endl;
		
		registro<<codigo<<endl;
		registro<<desc<<endl;
		registro<<marca<<endl;
		registro<<stockAct<<endl;
		registro<<stockMin<<endl;
		registro<<precioUnit<<endl;
		registro<<categ<<endl;
		
		//calculando campos
		
		valorTotal = stockAct * precioUnit;
		igv = 0.18 * valorTotal;
		valorFinal = valorTotal - igv;
		
		if(categ=='1'){
			dscto = 0.1;
		}else if(categ=='2'){
			dscto = 0.2;
		}else if(categ=='3'){
			dscto = 0.3;
		}
		
		maxDscto = valorTotal * dscto;
		//registro<<"campos: "<<endl;
		registro<<valorTotal<<endl;
		registro<<igv<<endl;
		registro<<valorFinal<<endl;
		registro<<maxDscto<<endl;
		//registro<<"- - - - - - - -"<<endl;
		//i = i + 1; 
		cout<<"\nDesea continuar (S)Si o (N)No --> ";cin>>opc;
		
	}while(opc=='s' || opc=='S');
}

void verProd(ifstream &lista) {
}


