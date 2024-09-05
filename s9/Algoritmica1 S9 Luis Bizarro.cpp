#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*
autor: luis junior alfredo bizarro ortiz
*/

int main(){
	int opc, opc1;
	int f1,e1,e2;
	srand(time(NULL));
	
	cout<<"\nIngrese el orden de las 2 matrices --> "; cin>>f1;
	
		//generar la matriz de [c1][f1]
		
		int matriz1[f1][f1];
	
		for (int i=0; i<f1; i++){
			for(int j=0; j<f1; j++){
				matriz1[i][j] = 1 + rand()%51;
			}
		}
	
		//generar la matriz de [c2][f2]
		
		int matriz2[f1][f1];
	
		for (int i=0; i<f1; i++){
			for(int j=0; j<f1; j++){
				matriz2[i][j] = 1 + rand()%51;
			}	
		}
	
	
	do{
		cout<<"\nLas matrices son: "<<endl;
		cout<<"\nMatriz 1: \n"<<endl;
		for(int a1=0; a1<f1;a1++){
			for(int a2=0; a2<f1;a2++){
				cout<<"["<<matriz1[a1][a2]<<"]";
					if(a2==f1-1){
						cout<<endl;
					}	
			}
		}
		cout<<"\nMatriz 2: \n"<<endl;
		for(int a3=0; a3<f1;a3++){
			for(int a4=0; a4<f1;a4++){
				cout<<"["<<matriz2[a3][a4]<<"]";
					if(a4==f1-1){
						cout<<endl;
					}
			}
		}
		cout<<"- - - - - - - - - - - - - - - - - - - "<<endl;
	
	cout<<"\nOperaciones con matrices"<<endl;
	cout<<"1. Multiplicacion de matrices"<<endl;
	cout<<"2. Suma de matrices multiplicadas por un escalar"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"INGRESAR OPCION --> ";
	cin>>opc;
	
	switch(opc){
		case 1:{
			
			int matriz_multi[f1][f1];
			
			//calculo de la matriz m1 x m2
			
			for(int k=0; k<f1;k++){
				for(int m=0; m<f1;m++){
					for(int n=0; n<f1;n++){
						if(n==0){
							matriz_multi[k][m]=0;
						}
						matriz_multi[k][m] = matriz_multi[k][m] + (matriz1[k][n] * matriz2[n][m]);
					}
					
				}
			}
			
			cout<<"\nMatriz multiplicacion: \n"<<endl;
			for(int a1=0; a1<f1; a1++){
				for(int a2=0; a2<f1; a2++){
					cout<<"[ "<<matriz_multi[a1][a2]<<" ]";
					if(a2==f1-1){
						cout<<endl;
					}
				}
			}
			
			cout<<"\nDiagonal: \n"<<endl;
			int diag[f1];
			for(int h=0; h<f1;h++){
				diag[h] = matriz_multi[h][h];
			}
			for(int l=0; l<f1;l++){
				cout<<"[ "<<diag[l]<<" ]";
			}
			cout<<endl;
			int suma_d=0;
			for(int z=0;z<f1;z++){
				suma_d=suma_d+diag[z];
			}
			cout<<"\nLa traza de la matriz multiplicacion es: "<<suma_d<<endl;
			cout<<endl;
			
			system("pause");
			break;
		}
		case 2:{
			
			cout<<"Digite el escalar para la matriz 1: "; cin>>e1;
			cout<<endl;
			cout<<"Digite el escalar para la matriz 2: "; cin>>e2;
			cout<<endl;
			int matriz3[f1][f1];
			int matriz4[f1][f1];
			cout<<"(Matriz 1) X "<<e1<<": \n"<<endl;
			for(int b1=0;b1<f1;b1++){
				for(int b2=0;b2<f1;b2++){
					matriz3[b1][b2] = e1 * matriz1[b1][b2];
				}
			}
			//mostrar resultado
			for(int c1=0;c1<f1;c1++){
				for(int c2=0;c2<f1;c2++){
					cout<<"["<<matriz3[c1][c2]<<"]";
					if(c2==f1-1){
						cout<<endl;
					}
				}
			}
			cout<<"\n(Matriz 2) X "<<e2<<": \n"<<endl;
			for(int d1=0;d1<f1;d1++){
				for(int d2=0;d2<f1;d2++){
					matriz4[d1][d2] = e2 * matriz2[d1][d2];
				}
			}
			//mostrar resultado
			for(int g1=0;g1<f1;g1++){
				for(int g2=0;g2<f1;g2++){
					cout<<"["<<matriz4[g1][g2]<<"]";
					if(g2==f1-1){
						cout<<endl;
					}
				}
			}
			cout<<"\nElija la Operacion a realizar:"<<endl;
			cout<<"1. Suma --> M1 + M2"<<endl;
			cout<<"2. Resta --> M1 - M2"<<endl;
			cin>>opc1;
			
			switch(opc1){
				case 1:{
					int matriz_suma[f1][f1];
					for(int q1=0;q1<f1;q1++){
						for(int q2=0;q2<f1;q2++){
							matriz_suma[q1][q2]=matriz3[q1][q2] + matriz4[q1][q2];
						}
					}
					cout<<"\nMatriz suma = Matriz 1 + Matriz 2\n"<<endl;
					for(int s1=0;s1<f1;s1++){
						for(int s2=0; s2<f1;s2++){
							cout<<"["<<matriz_suma[s1][s2]<<"]";
							if(s2==f1-1){
								cout<<endl;
							}
						}
					}
					system("pause");
					break;
				}
				case 2:{
					int matriz_resta[f1][f1];
					for(int q1=0;q1<f1;q1++){
						for(int q2=0;q2<f1;q2++){
							matriz_resta[q1][q2]=matriz3[q1][q2] - matriz4[q1][q2];
						}
					}
					cout<<"\nMatriz resta = Matriz 1 - Matriz 2\n"<<endl;
					for(int s1=0;s1<f1;s1++){
						for(int s2=0; s2<f1;s2++){
							cout<<"["<<matriz_resta[s1][s2]<<"]";
							if(s2==f1-1){
								cout<<endl;
							}
						}
					}
					system("pause");
					break;
				}
			}
			break;
		}	
	}
	system("cls");
	}while(opc!=0);
	
	
	system("pause");
	return 0;
}
