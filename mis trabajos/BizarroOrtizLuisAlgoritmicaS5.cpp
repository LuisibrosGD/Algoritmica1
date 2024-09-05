#include <iostream>

using namespace std;

void menu();

//prototipo de funcion

float costoProm(float dim, int costom2);

void imp(float precio, float porcImp);

float interesMe(float cuotaInicial, float tasaMensual);

void mostrarInt(float &capital, float &tasita, int &temp);

int main(){
	
	//para el caso 1 y 2
	
	char opc=' ', zona, tipInm;
	float dim, impuesto, precioInm, tasaAnual, cuotaInicial, monto, intMens;
	int costom2, tiempo;
	string nombreMueble;
	
	//para el caso 3
	
	float capital, tasita;
	int temp;
	
	do{
		
		menu();
		cin>>opc;
		switch(opc){
			case '1':{
				cout<<"Ingrese la zona de ubicacion: a/b/c"<<endl;
				cin>>zona;
				cout<<"Ingrese la dimension en metros cuadrados: "; cin>>dim;
				cout<<"Ingrese el tipo de inmueble: Casa(C/c), Departamento(D/d), Oficina(O/o)"<<endl; cin>>tipInm;
				
				if(zona=='a' || zona=='A'){
					costom2 = 3000;
				}else if(zona=='b' || zona == 'B'){
					costom2 = 2000;
				}else if(zona=='c' || zona == 'C'){
					costom2=1000;
				}
				
				//Porcentaje de impuesto
				
				if(tipInm=='C' || tipInm=='c' || tipInm=='d' || tipInm=='D'){
					impuesto=0.05;
				}else if(tipInm=='o' || tipInm=='O'){
					impuesto=0.1;
				}
				
				//para el tipo de inmueble
				
				if(tipInm=='c' || tipInm=='C'){
					nombreMueble = "Casa";
				}else if(tipInm=='d'||tipInm=='D'){
					nombreMueble = "Departamento";
				}else if(tipInm=='o'||tipInm=='O'){
					nombreMueble = "Oficina";
				}
				
				//llamado de funciones
				
				precioInm = costoProm(dim, costom2);
				cout<<endl;
				cout<<"Zona de ubicacion: "<<zona<<endl;
				cout<<"Dimension: "<<dim<<" m^2"<<endl;
				cout<<"Costo por m^2: "<<costom2<<endl;
				cout<<"Tipo de inmueble: "<<nombreMueble<<endl;
				cout<<"Cotizacion del inmueble: $ "<<precioInm<<endl;
				cout<<"Porcentaje de impuesto de pago al municipio: "<<impuesto*100<<"% del precio inmueble"<<endl;
				imp(precioInm, impuesto);
				
				break;
			}
			
			case '2':{
				
				cout<<"Digite el tiempo para pagar (5 anios --> 5, 10 anios --> 10): "; cin>>tiempo;
				cout<<endl;
				
				if(tiempo==5){
					tasaAnual = 25/12;
				}else if(tiempo==10){
					tasaAnual = 15/12;
				}
				
				cuotaInicial = 0.01*precioInm;
				
				cout<<"Importe de cuota inicial: S/. "<<cuotaInicial<<endl;
				
				intMens = interesMe(cuotaInicial, tasaAnual);
				cout<<"Interes al cabo de "<<tiempo<<" anios: $ "<<intMens*12*tiempo<<endl;
				cout<<"Interes mensual: $ "<<intMens<<endl;
				monto = cuotaInicial + intMens*12*tiempo;
				cout<<"Importe total: "<<monto<<" dolares o "<<monto*3.75<<" soles"<<endl;
				cout<<endl;
				break;
			}
			
			case '3':{
				do{
				cout<<"Ingrese su capital de inversion: $ "; cin>>capital;
				}while(capital<1000);
				cout<<endl;
				do{
				cout<<"Digite el tiempo en meses (max 12 meses): ", cin>>temp;
				}while(temp>12 || temp <= 0);
				
				
				if(capital <= 5000 & temp <= 6){
					tasita=1.5;
				}else if(capital > 5000 & temp > 6){
					tasita=5;
				}else{
					tasita=3;
				}
				
				mostrarInt(capital, tasita, temp);
				
				
				break;
			}
		}
		
		system("pause");
			
	}while(opc!='0');
	
	return 0;
}

void menu(){
	system("CLS");
		cout<<endl;
		cout<<" Opciones de Funciones"<<endl<<endl;
		cout<<"1.- Cotizar inmueble"<<endl;
		cout<<"2.- Opcion de financiamiento"<<endl;
		cout<<"3.- Opcion 3"<<endl;
		cout<<"Ingresar Opcion -----> ";
}

float costoProm(float dim, int costom2){
	float cProm;
	cProm=dim*costom2;
	return cProm;
}

void imp(float precio, float porcImp){
	float precioImp;
	precioImp = precio * porcImp;
	cout<<"Impuesto de pago al municipio: $ "<<precioImp<<endl;
}

float interesMe(float cuotaInicial, float tasaAnual){
	
	float interesM;
	interesM = cuotaInicial * tasaAnual / 12;
	return interesM;
	
}

void mostrarInt(float &capital, float &tasita, int &temp){
	
	float interesSimple;
	interesSimple = capital*tasita*temp;
	cout<<"Interes al cabo de "<<temp<<" meses: $ "<<interesSimple<<endl;
	cout<<"Tasa de interes mensual: "<<tasita<<"%"<<endl;
	cout<<"Interes mensual: $ "<<interesSimple/temp<<endl;
	for(int i=1; i<=temp; i++){
		cout<<"Interes acumulado hasta el mes "<<i<<" es: $ "<<interesSimple-(temp-i)*interesSimple/temp<<endl;
	}
	
}



