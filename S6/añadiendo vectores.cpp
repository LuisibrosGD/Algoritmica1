#include <iostream>
#include <conio.h>
using namespace std;
/*
Realiza un programa que defina dos vectores de caracteres y después almacene el 
contenido de ambos vectores en un nuevo vector, situando en primer lugar los elementos del primer vector 
seguido por los elementos del segundo vector. Muestre el contenido del nuevo vector en la salida estándar.
*/
int main(){
	
	int rango1, rango2, rango_total;
	
	cout<<"Digite el rango de caracteres para la primera operacion: "; cin>>rango1;
	cout<<"Digite el rango de caracteres para la segunda operacion: "; cin>>rango2;

	char vector_1[rango1], vector_2[rango2];
	
	cout<<"Primera operacion"<<endl;
	
	for(int i=0; i<rango1; i++){
		cout<<i+1<<". Escriba el caracter: "; cin>>vector_1[i];
	}
	
	system("cls");
	
	cout<<"Segunda operacion"<<endl;
	for(int j=0; j<rango2; j++){
		cout<<j+1<<". Escriba el caracter: "; cin>>vector_2[j];
	}
	
	system("cls");
	
	//definiendo el vector que une los anteriores
	rango_total = rango1 + rango2;
	char vector_total[rango_total];
	
	for(int k=0; k<rango1; k++){
		vector_total[k] = vector_1[k];
	}
	
	for(int m=rango1; m<rango_total; m++){
		vector_total[m] = vector_2[m-rango1];
	}
	
	//mostrar el vector
	
	for(int n=0; n<rango_total; n++){
		cout<<n+1<<". Letra: "<<vector_total[n]<<endl;
	}
	
	getch();
	return 0;
}
