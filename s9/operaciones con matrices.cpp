#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	
	int f1,c1,f2,c2;
	
	srand(time(NULL));
	int opc;
	do{
		
		
				cout<<"Ingrese el numero de filas de la matriz 1 --> "; cin>>f1;
				cout<<"Ingrese el numero de columnas de la matriz 1 --> "; cin>>c1;
	
				int matriz1[f1][c1];
	
				//generar la matriz de [c1][f1]
	
				for (int i=0; i<f1; i++){
					for(int j=0; j<c1; j++){
						matriz1[i][j] = 1 + rand()%51;
					}
				}
	
				cout<<"Ingrese el numero de filas de la matriz 2 --> "; cin>>f2;
				cout<<"Ingrese el numero de columnas de la matriz 2 --> ";cin>>c2;
	
				int matriz2[f2][c2];
	
				//generar la matriz de [c2][f2]
	
				for (int i=0; i<f2; i++){
					for(int j=0; j<c2; j++){
						matriz2[i][j] = 1 + rand()%51;
					}
				}
		system("cls");
		cout<<"Operaciones con matrices"<<endl;
		cout<<"1. Suma o resta de matrices"<<endl;
		cout<<"2. Multiplicacion de matrices"<<endl;
		cout<<"3. Mostrar matrices"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"INGRESAR OPCION -->"; cin>>opc;
		
		switch(opc){
			
			case 1:{
				
				if(f1==c1 && f2==c2 && f1==f2){
					int matriz_suma[f1][c1];
					for(int i=0; i<f1;i++){
						for(int j=0;j<f1;j++){
							matriz_suma[i][j] = matriz1[i][j]+matriz2[i][j];
						}
					}
					cout<<"Matriz suma: "<<endl;
					for(int k=0; k<f1;k++){
						for(int m=0; m<f1; m++){
							cout<<"[ "<<matriz_suma[k][m]<<" ]";
							if(m==f1-1){
								cout<<endl;
							}
						}
					}	
				}else{
					if(f1!=c1){
						cout<<"La matriz 1 no es cuadradada"<<endl;
					}
					if(f2!=c2){
						cout<<"La matriz 2 no es cuadrada"<<endl;
					}
					if(f1!=f2 && c1!=c2){
						cout<<"Las matrices 1 y 2 no tienen el mismo orden"<<endl;
					}
				}
				system("pause");
				break;
				
			}
			case 2:{
				if(c1==f2){
				int matriz_multi[f1][c2];
				for(int k=0; k<f1;k++){
					for(int m=0; m<c2;m++){
						for(int n=0; m<f1;m++){
							matriz_multi[k][m] = matriz1[k][n]+matriz2[n][m];
						}
				
					}
				}
				cout<<"Matriz multiplicacion: "<<endl;
				for(int a1=0; a1<f1; a1++){
					for(int a2=0; a2<c2; a2++){
						cout<<"[ "<<matriz_multi[a1][a2]<<" ]";
						if(a2==c2-1){
						cout<<endl;
						}
					}
				}
				}else{
					cout<<"No se puede realizar la multiplicacion de matrices xd"<<endl;
				}
				system("pause");
				break;
				case 3:{
					cout<<endl;
					cout<<"-- Matriz 1: "<<endl;
					cout<<endl;
					cout<<"Numero de filas: "<<f1<<endl;
					cout<<"Numero de columnas: "<<c1<<endl;
					for (int a=0; a<f1; a++){
						for(int b=0; b<c1; b++){
							cout<<"[ "<<matriz1[a][b]<<" ] ";
							if(b==c1-1){
								cout<<endl;
							}
						}
					}
					cout<<"Matriz 2: "<<endl;
					cout<<endl;
					cout<<"Numero de filas: "<<f2<<endl;
					cout<<"Numero de columnas: "<<c2<<endl;
					for (int c=0; c<f2; c++){
						for(int d=0; d<c2; d++){
							cout<<"[ "<<matriz2[c][d]<<" ] ";
							if(d==c2-1){
								cout<<endl;
							}
						}
					}
				system("pause");
				break;
					
				}
				
			}
			
		}
		system("cls");
	}while(opc != 0);
	system("pause");
	return 0;
}
	
