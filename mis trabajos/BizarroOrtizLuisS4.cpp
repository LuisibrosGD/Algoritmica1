#include <iostream>

using namespace std;

void menu(){
system("CLS");

cout<<"\tMENU DE OPCIONES"<<endl<<endl;
cout<<"1.- Opcion 1  "<<endl;
cout<<"2.- Opcion 2  "<<endl;
cout<<"3.- Opcion 3  "<<endl;

cout<<"0.- SALIR PROGRAMA"<<endl<<endl;

cout<<"Ingrese Opcion ---> ";

} 

int main (){
	char opcion;
	float ingresos, prestamo, interes, tas, tasaPlus, tasaAsig, prestAcum, falta;
	int pmin=0, pmax=0, tiempo, j;
	
	do{
		
		menu();
		fflush(stdin);//limpia buffer
		cin>>opcion;
		switch(opcion){
			case '1':{
				
				do{
					cout<<"Ingrese su cantidad de ingreso mensual: S/. ";
					cin>>ingresos;
					if(ingresos < 1500){
						cout<<"Rango de ingresos no admitido"<<endl;
					}
					
				}while(ingresos<1500);
				
				pmin = 1000;
				
				if(ingresos >= 1500 && ingresos <=3000){
					pmax=5000;
					cout<<"Puedes solicitar un prestamo de S/. "<<pmin<<" hasta S/. "<<pmax<<endl;
				}else if(ingresos <= 5000){
					pmax=10000;
					cout<<"Puedes solicitar un prestamo de S/. "<<pmin<<" hasta S/. "<<pmax<<endl;
				}else{
					pmax=40000;
					cout<<"Puedes solicitar un prestamo de S/. "<<pmin<<" hasta S/. "<<pmax<<endl;
				}
				
				do{
					cout<<"Digite el prestamo: S/. "; cin>>prestamo;
					
					if(prestamo < pmin || prestamo > pmax){
						cout<<"El prestamo no se encuentra en el rango"<<endl;
					}
					
				}while(prestamo < pmin || prestamo > pmax);
				
				cout<<"Digite el tiempo para pagarlo: 12, 24 o 36 meses "<<endl;
				cin>>tiempo;
					
				if(tiempo==12){
					tasaAsig=20;
				}else if(tiempo==24){
					tasaAsig=15;
				}else if(tiempo==36){
					tasaAsig=10;
				}
				
				interes=prestamo*tasaAsig*0.01*tiempo;
				tasaPlus=0.015*interes;
				tas=interes+tasaPlus;
				
				cout<<"Ingreso del solicitante: S/. "<<ingresos<<endl;
				cout<<"Importe del prestamo: S/. "<<prestamo<<endl;
				cout<<"Tiempo seleccionado: "<<tiempo<<endl;
				cout<<"Tasa asignada: "<<tasaAsig<<"%"<<endl;
				cout<<"Importe de la cuota mensual asignada: S/. "<<prestamo*tasaAsig/100<<endl;
				cout<<"Importe correspondiente al seguro de degravamen: S/. "<<0.015*prestamo*tasaAsig<<endl;
				cout<<"Importe de la cuota mensual acumulada: S/. "<<tas<<endl;
				cout<<"Importe adicional que se pagara a la cancelacion del prestamo: S/. "<<tasaPlus<<endl;
				
				break;
			}
			
			prestAcum=0;
			
			case '2':{
				for(j=1;j<=12;j++){
					prestAcum=prestamo*tasaAsig*0.01*j;
					cout<<j<<" mes: S/. "<<prestAcum<<endl;
					prestAcum=prestAcum;
					cout<<"Acumulado hasta el "<<j<<"° mes: S/. "<<prestAcum<<endl;
					falta=interes-(tiempo-j)*prestAcum;
					cout<<"Le falta pagar: S/. "<<falta<<endl;
				}
				break;
			}
			
			case '3':{
				break;
			}
			
			case '0':{
				cout<<"Fin del programa"<<endl;
				break;
			}
			
			default:{
				cout<<"Error"<<endl;
				
			}
		}
		
		system("pause");
	
	}while(opcion != 0);
	
	return 0;
}





