#include <iostream>
#include <conio.h>
using namespace std;


int main(){
	/*Se registran y mostrar N notas para el alumno 1, N notas
	para el alumno 2 y N notas para el alumno 3 (pueden ser
	generados aleatoriamente en el rango de 0 y 20) */
	
	int notas, k;
	
	do{
	
	cout<<"Ingrese la cantidad de notas por alumno: "; cin>>notas;
	
	if(notas < 0){
		system("cls");
	}
	
	}while(notas < 0);
	
	float alumno_1[notas], alumno_2[notas], alumno_3[notas];
	
	for(int i=0; i<notas; i++){
		do{
		cout<<"Ingrese la nota "<<i+1<<" del alumno 1: "; cin>>alumno_1[i];
		}while(alumno_1[i]<0 || alumno_1[i]>20);
	}
	cout<<" - - - - - - - -"<<endl;
	for(int i=0; i<notas; i++){
		do{
		cout<<"Ingrese la nota "<<i+1<<" del alumno 2: "; cin>>alumno_2[i];
		}while(alumno_2[i]<0 || alumno_2[i]>20);
	}
		cout<<" - - - - - - - -"<<endl;

	for(int i=0; i<notas; i++){
		do{
		cout<<"Ingrese la nota "<<i+1<<" del alumno 3: "; cin>>alumno_3[i];
		}while(alumno_3[i]<0 || alumno_3[i]>20);
	}
	cout<<" - - - - - - - -"<<endl;

	//nota minima
	
	float nota_min1 = alumno_1[0], nota_min2 = alumno_2[0], nota_min3 = alumno_3[0];
	
	for(int i=0; i<notas; i++){
		if (alumno_1[i]<nota_min1){
			nota_min1 = alumno_1[i];
		}
	}
	
	for(int j=0; j<notas; j++){
		if (alumno_2[j] < nota_min2){
			nota_min2 = alumno_2[j];
		}
	}
	
	for(int k=0; k<notas; k++){
		if (alumno_3[k] < nota_min3){
			nota_min3 = alumno_3[k];
		}
	}
	
	
	
	//nota maxima
	
	float nota_max1 = alumno_1[0], nota_max2 = alumno_2[0], nota_max3 = alumno_3[0];
	
	for(int l=0; l<notas; l++){
		
		if (alumno_1[l] > nota_max1){
			nota_max1 = alumno_1[l];
		}
	}
	
	for(int m=0; m<notas; m++){
	
		if (alumno_2[m] > nota_max2){
			nota_max2 = alumno_2[m];
		}
	}
	
	for(int n=0; n<notas; n++){
		
		if (alumno_3[n] > nota_max3){
			nota_max3 = alumno_3[n];
		}
	}
	
	cout<<"Nota minima del alumno 1: "<<nota_min1<<endl;
	cout<<"Nota maxima del alumno 1: "<<nota_max1<<endl;
	cout<<"- - - - - - -"<<endl;
	
	cout<<"Nota minima del alumno 2: "<<nota_min2<<endl;
	cout<<"Nota maxima del alumno 2: "<<nota_max2<<endl;
	cout<<"- - - - - - -"<<endl;

	cout<<"Nota minima del alumno 3: "<<nota_min3<<endl;
	cout<<"Nota maxima del alumno 3: "<<nota_max3<<endl;
	cout<<"- - - - - - -"<<endl;

	
	//Vector promedio
	
	float suma1=0, suma2=0, suma3=0, promedio[3], prom1, prom2, prom3;
	
	for (int i=0; i<notas; i++){
		suma1 = suma1 + alumno_1[i]; 
	}
	prom1 = suma1 / notas;
	promedio[0] = prom1;
	
	for (int i=0; i<notas; i++){
		suma2 = suma2 + alumno_2[i]; 
	}
	prom2 = suma2 / notas;
	promedio[1] = prom2;
	
	for (int i=0; i<notas; i++){
		suma3 = suma3 + alumno_3[i]; 
	}
	prom3 = suma3 / notas;
	promedio[2] = prom3;
	
	//Mostrar vector promedio
	
	for (int i=0; i<3; i++){
		cout<<"Promedio del alumno "<<i+1<<" es: "<<promedio[i]<<endl;
	}
	
	
	//ordenamiuento
	
	float temp;
	for(int j=0; j<2;j++){
		for(int i=0; i<2; i++){
			if(promedio[i] > promedio [i+1]){
				temp = promedio[i];
				promedio[i] = promedio[i+1];
				promedio[i+1] = temp;
			}
		}	
	}
	
	cout<<"Orden descendente: "<<endl;
	for(int i=2; i>=0; i--){
		cout<<i+1<<". "<<promedio[i]<<endl;
	}

	//aprobados y desaprobados
	//aprobado > 11 y desaprobado <= 11
	
	for (int i=0; i<3; i++){
		if(promedio[i]>11){
			cout<<"El alumno "<<i+1<<" esta APROBADO."<<endl;
		}else{
			cout<<"El alumno "<<i+1<<" esta DESAPROBADO."<<endl;
		}
	}
	
	//promedio del vector promedio
	
	float prom_general, suma_prom=0;
	
	for (int i=0; i<3; i++){
		suma_prom = suma_prom + promedio[i];
	}
	prom_general = suma_prom / 3;
	
	cout<<"El promedio general es: "<<prom_general;
	
	getch();
	return 0;

}




