#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void escribir();

int main(){
	
	escribir();
	
	system("pause");
	return 0;
}

void escribir(){
	int opc, i=1;
	ofstream fichero1;
	string texto, nombreArchivo;
	
	cout<<"Digite el nombre del archivo: "<<endl;
	getline(cin, nombreArchivo);
	fichero1.open(nombreArchivo.c_str(), ios::out);//abriendo archivo
		
	if(fichero1.fail()){ //archivo.fail() -> envia un valor booleano
	cout<<"No se pudo abrir el archivo";
	exit(1);
	}
	do{
		fflush(stdin);
		cout<<i<<". Ingrese la frase: "<<endl;
		getline(cin, texto);
		
		fichero1<<texto;
		i++;
		cout<<"Desea añadir mas frases? 1 -> Si, 0 -> No"<<endl;
		cin>>opc;	
	}while(opc!=0);
	
	fichero1.close();
}
