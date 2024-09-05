#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	float ingr, prest, p_deg, cto, int_men, int_fin, int_acum, mensualidad, monto, paga;
	char opc;
	int vmin, vmax, tiempo, tasa, i;
	
do{
	
	cout<<"Menu de opciones: "<<endl;
	cout<<"1: Opcion 1"<<endl;
	cout<<"2: Opcion 2"<<endl;
	cout<<"3: Opcion 3"<<endl;
	cout<<"0: Cerrar programa"<<endl;
	cout<<"Ingrese su opcion: "; cin>>opc;
	switch(opc){
		case '1':
			do{
			
			cout<<"Digite sus ingresos mensuales: S/. "; cin>>ingr;
			vmin=1000;
			if(ingr>1500 && ingr<3000){
				vmax=5000;
			}else if(ingr<5000){
				vmax=10000;
			}else{
				vmax=40000;
			}
			
			if(ingr<1500){
				cout<<"Se necesita tener ingresos mayores a S/. 1500"<<endl;
			}
			
			}while(ingr<1500);
			
			do{
			
			cout<<"Prestamo que puede solicitar es de S/. "<<vmin<<" hasta S/. "<<vmax<<endl;
			cout<<"Digite el prestamo: S/. "; cin>>prest;
			
			if(prest < vmin || prest > vmax){
				cout<<"Error. No puede solicitar un prestamo fuera del rango. Vuelva a intentarlo"<<endl;
			}
			
			}while(prest < vmin || prest > vmax);
			
			do{
			
			cout<<"Digite el tiempo para pagar el prestamo: "<<endl;
			cout<<"12 meses --> 12"<<endl;
			cout<<"24 meses --> 24"<<endl;
			cout<<"36 meses --> 36"<<endl;
			cin>>tiempo;
			
			if(tiempo==12){
				tasa=20;
			}
			if(tiempo==24){
				tasa=20;
			}
			if(tiempo==36){
				tasa=20;
			}
			
			if(tiempo!=12 && tiempo!=24 && tiempo!=36){
			
			cout<<"Digite el tiempo que se muestra en pantalla"<<endl;
			
			}
			
			}while(tiempo!=12 && tiempo!=24 && tiempo!=36);
			
			//costo por seguro de degravamen 1.5% mensual
			
			p_deg = 1.5;
			cto = prest*tasa*0.01*p_deg*0.01;
			int_men = prest*tasa*0.01;
			int_fin = int_men*tiempo;
			cout<<"Ingreso: S/. "<<ingr<<endl;
			cout<<"Importe del prestamo solicitado: S/. "<<prest<<endl;
			cout<<"Tiempo seleccionado: "<<tiempo<<" meses"<<endl;
			cout<<"Tasa seleccionada: "<<tasa<<"% mensual"<<endl;
			cout<<"Importe de la cuota mensual: S/. "<<int_men<<endl;
			cout<<"Importe correspondiente al seguro de degravamen: S/. "<<cto*tiempo<<endl;
			cout<<"Importe de la cuota mensual acumulada: S/. "<<int_fin<<endl;
			cout<<"Importe adicional que se pagara a la cancelacion del prestamo: S/. "<<int_fin+cto*tiempo<<endl;
			monto=int_fin+prest+cto*tiempo;
			cout<<"Monto: S/. "<<monto<<endl;
			break;
			
		case '2':
			int_acum=0;
			mensualidad=monto/tiempo;
			cout<<"Mensualidad a pagar: S/. "<<mensualidad<<endl;
			cout<<"Mes:"<<"		Falta cancelar:"<<"		Usted pago:"<<endl;
			for(i=1; i<=tiempo; i++){

				cout<<i<<"		"<<"S/. "<<monto-(mensualidad)*i<<"		S/. "<<int_acum<<endl;
				
				int_acum=int_acum+mensualidad;
				
			}
			break;
		
		case '3':
			do{

			cout<<"Digite el monto a pagar en el 1er mes (mayor a 500): S/. "; cin>>paga;
			if(paga < 500){
				cout<<"Usted puede adelantar como minimo S/. 500"<<endl;
			}
			
			}while(paga < 500);
			
			cto = (prest - paga)*tasa*0.01*p_deg*0.01;

			int_men = (prest-paga)*tasa*0.01;
			int_fin = int_men*tiempo;
			cout<<"Ingreso: S/. "<<ingr<<endl;
			cout<<"Importe del prestamo solicitado: S/. "<<prest<<endl;
			cout<<"Pago adelantado: S/. "<<paga<<endl;
			cout<<"Tiempo seleccionado: "<<tiempo<<" meses"<<endl;
			cout<<"Tasa seleccionada: "<<tasa<<"% mensual"<<endl;
			cout<<"Importe de la cuota mensual: S/. "<<int_men<<endl;
			cout<<"Importe correspondiente al seguro de degravamen: S/. "<<cto*tiempo<<endl;
			cout<<"Importe de la cuota mensual acumulada: S/. "<<int_fin<<endl;
			cout<<"Importe adicional que se pagara a la cancelacion del prestamo: S/. "<<int_fin+cto*tiempo<<endl;
			monto=int_fin+prest+cto*tiempo;
			break;
		case '0':
			break;
		
		default:
			cout<<"Opcion incorrecta, intentelo otra vez"<<endl;
			
	
	}
	system("pause");
	system("cls");
}while(opc != '0');
	return 0;
}
