#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y){  //ancho = 80, alto = 25
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int main(){
	
	gotoxy(80,25); cout<<"Hola";
	
	
	
	system("pause");
	return 0;
}

/*
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
		
		if(f1!=c1 && f2!=c2 && f1!=f2){
			cout<<"Las matrices no son cuadradas"<<endl;
		}else{
			if(f1==c1 && f2==c2 && f1!=f2){
				cout<<"Las matrices son cuadradas pero no del mismo orden"<<endl;
			}
		}
		
	}while(f1!=c1 || f2!=c2 || f1!=f2);
*/
