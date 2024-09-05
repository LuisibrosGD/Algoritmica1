#include <iostream>

using namespace std;
int i=0, j=0;
void menu();
void funcion1();
int funcion2();
float funcion3(float, float);
void funcion4(int, int, int );
int funcion5(int &r1, int &r2);


int main() {
	
	char opcion=' ';
	int x, min, max, n;
	float tasa, imp;
	do{
		menu();
		cin>>opcion;
		
		switch(opcion){
			case '1':{
				funcion1();
				break;
			}
			case '2':{
				x= funcion2();
				cout<<" Valor registrado es  ---> "<<x<<endl;
				cout<<" Valor al cuadrado es ---> "<<x*x<<endl;
				break;
			}
			case '3':{
				cout<<"\nIngresar Importe  ---------> "; cin>>imp;
				cout<<"\nIngresar Tasa de Interes --> "; cin>>tasa;
				tasa = tasa/100;
				cout<<endl;
				cout<<" El interes generado es --->"<<funcion3(imp, tasa)<<endl;
				break;
			}
			case '4':{
				
				
				cout<<"\nIngresar rango menor --> "; cin>>min;
				cout<<"\nIngresar rango mayor --> "; cin>>max;
				cout<<"\nCantidad de numeros por tabla--->";cin>>n;
				cout<<endl;
				funcion4( min, max,n);
				system("pause");
				break;
			}
			case '5':{
				min= 20;
				max= 50;
				x= funcion5(min, max);
				cout<<"\nel valor de min es -->"<<min;
				cout<<"\nel valor de max es -->"<<max;
				cout<<"\nLa suma de los valores es --> "<<x;
				cout<<endl;
				break;		
			}
		};//switch
		system("pause");	
	}while(opcion != '0');
	
	
	}//end main
	
// FUNCIONES


void funcion1(){
	system("CLS");
	cout<<endl;
	cout<<" Proceso de Funciones Algoritmicas"<<endl;
	cout<<"**********************************"<<endl;
		
}
int funcion2(){
	int n;
	system("cls");
	cout<<"\nIngrese cantidad de datos---> ";
	cin>>n;
		return n;
}
float funcion3(float importe, float tasa){
	return importe * tasa;
}

 void funcion4(int r1, int r2, int x){
 	for(j=r1; j<= r2; j++){
 		cout<<" Tabla del "<<j<<endl;
 		for(i=1;i<=x;i++){
 			cout<<endl;
			cout<<i<<" X " <<r1 <<" = "<<i*r1;
 		 }
 		r1++;
	 }
 	
 }
 
 int funcion5(int &r1, int &r2){
	r1= r1+r2;
	r2= r1*r2;
	return r1+r2;

 } 
void menu(){
	system("CLS");
		cout<<endl;
		cout<<" Opciones de Funciones"<<endl<<endl;
		cout<<"1.- No envia arguumentos, No retorna valores"<<endl;
		cout<<"2.- No envia arguumentos, Retorna un valor"<<endl;
		cout<<"3.- Envia arguumentos, retorna un Valor"<<endl;
		cout<<"4.- Envia argumentos, No retorna valor"<<endl;
		cout<<"5.- Envia argumentos, retorna varios valores (Referencia)"<<endl;
		cout<<endl<<"0.- Salir"<<endl<<endl;
		cout<<"Ingresara Opcion -----> ";
}		
	
	
	
	
