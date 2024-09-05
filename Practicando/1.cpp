/*
1. Generar un vector de numeros aleatorios 1 al 200 y luego ordenarlos en orden descendente utilizando el algoritmo
de ordenamiento burbuja.
Luego calcular el promedio del vector y mostrarlo
*/


#include <iostream>
#include <time.h>
#include <stdlib.h> // para rand()

using namespace std;

void promedio(int vec[], int);

int main(){
	int n;
	
	cout<<"Ingresar cantidad de elementos: "; cin>>n;
	int num[n];
	
	srand(time(NULL));
	
	//creando el vector de numeros aleatorios
	for(int i=0; i<n;i++){
		num[i] = 1+rand()%200;
		cout<<i+1<<"--> "<<num[i]<<endl;
	}
	
	//ordenamiento burbuja mejorado
	
	bool boton;
	int aux;
	
	for(int i=0; i<n;i++){
		
		boton = false;
		for(int j=1; j<n-1 ;j++){
			if (num[j+1]>num[j]){
				aux = num[j+1];
				num[j+1] =  num[j];
				num[j] = aux;
				boton = true;
			}
		
		
		}
		if (boton == false){
			break;
		}	
		cout<<"pasada --> "<<i+1<<endl;
		
	
	}
	
	//mostrar en ascendente
	
	for(int m=n-1; m>=0; m--){
		cout<<"N_"<<m+1<<" --> "<<num[m]<<endl;
	}
	
	//mostrar en descendente
	
	/*
	for(int k=0; k<n; k++){
		cout<<"N_"<<k+1<<" --> "<<num[k]<<endl;
	}
	*/
	
	//promedio del vector
	
	promedio(num, n);
	
	
	
	system("pause");
	return 0;
}

void promedio(int vec[], int tam){
	float suma=0;
	float prom;
	for(int i=0; i<tam; i++){
		suma = suma + vec[i];
	}
	prom = suma/tam;
	cout<<"La suma de todos los elementos es: "<<suma<<endl;
	cout<<"El promedio es: "<<prom<<endl;
}

