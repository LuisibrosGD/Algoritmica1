#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <windows.h>

using namespace std;

//declaracion de variables
string xn1, xCantidad, xPrecioEtiqueta, xPoferta;
string nombre;
void menu();
void insertar();
//void mostrar();


int main(){
	char opc=' ';
	srand(time(NULL));
	do{
	
	menu();
	cin>>opc;
	
	switch(opc){
		case '1':{
			insertar();
			break;
		}
		case '2':{
			//mostrar();
			break;
		}
		case '3':{
			
			break;
		}
		case '4':{
			
			break;
		}
		case '5':{
			
			break;
		}
	}
	
	}while(opc!='0');
	system("pause");
	return 0;
}

void menu(){
	
	system("cls");
	
	cout<<"\n\tOPERACIONES CON ARCHIVOS"<<endl;
	cout<<"1.- Adicion de Registros"<<endl;
	cout<<"2.- Mostrar Registros"<<endl;
	cout<<"3.- Buscar registro"<<endl;
	cout<<"4.- Modificar Registro"<<endl;
	cout<<"5.- Eliminar Registro"<<endl;
	cout<<"0.- Salir"<<endl;
	cout<<"\n\tIngresar Opcion---> ";
	
}

void insertar(){
	
	ofstream archivo;
	
	int n1, cantidad, opc1;
	char lineaProducto;
	float precioEtiqueta, pOferta;
	
	archivo.open("articulos.txt", ios::app); //abrimos el archivo en modo añadir texto
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		
		n1 = rand()%500+1; //codigo
		
		//cout<<"Digite el codigo que quiera aniadir: "<<endl;
		cout<<"\nCodigo: "<<n1<<endl;
		archivo<<n1<<endl;
		
		fflush(stdin);

		
		cout<<"\nDigite el nombre del producto: "<<endl;
		getline(cin, nombre);
		archivo<<nombre<<endl;
		
		cout<<"\nLinea de producto: \nA: Electrodomesticos \nB: Linea blanca \nC: Audio y video"<<endl;
		cout<<"Digite la linea del producto (A), (B), (C): ";
		cin>>lineaProducto;
		archivo<<lineaProducto<<endl;
		
		cout<<"\nDigite el precio de la etiqueta (S/.): ";
		cin>>precioEtiqueta;
		archivo<<precioEtiqueta<<endl;
		
		if(lineaProducto == 'a'|| lineaProducto=='A'){
			pOferta = precioEtiqueta * 0.9; 
		}else if(lineaProducto=='b'||lineaProducto=='B'){
			pOferta = precioEtiqueta * 0.85;
		}else if(lineaProducto == 'c'||lineaProducto=='C'){
			pOferta = precioEtiqueta * 0.8;
		}
		
		//registrando el precio de oferta
		archivo<<pOferta<<endl;
		
		//cantidad 
		cantidad = 10 + rand()%20;
		cout<<"\nCantidad: "<<cantidad<<endl;
		archivo<<cantidad<<endl;
		
		cout<<"\nDesea registrar otro producto: \n(1) --> Si \n(0) --> No"<<endl;
		cin>>opc1;
		
	}while(opc1!=0);
	
	archivo.close();
}
/*
void mostrar(){
	
	ifstream lee("articulos.txt",ios::in);
	
	
	if(lee.fail()){
		cout<<"Error en el archivo..."<<endl;
		Sleep(2000);
		exit(1);
	}
	
	while(!lee.eof()){
		
		getline(lee, xn1);
		getline(lee, xprecioEtiqueta);
		getline(lee, xPoferta);
		
	
	cout<<"\nCodigo--------------------> "<<xn1<<endl;
	istringstream(xn1)>>n1;
	cout<<"\nNombre del producto-------> "<<nombre<<endl;
	cout<<"\nPrecio etiqueta-----------> "<<precioEtiqueta<<endl;
	istringstream(xprecioEtiqueta)>>precioEtiqueta;
	cout<<"\nPrecio oferta-------------> "<<xSueldo<<endl;
	istringstream(xPoferta)>>pOferta;
	
	
	cout<<"**************************************"<<endl;
	getline(lee,nom);
	}
	archivo.close();
	system("pause");
}
*/









