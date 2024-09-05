#include <iostream>
#include <fstream>

using namespace std;

void fichero();
void frase();

int main(){
	
	fichero();
	
	
	
	system("pause");
	return 0;
}

void fichero(){
	ofstream fichero;
	string nombre,frase;
	int numf;
	
	cout<<"Ingrese el nombre del archivo: ";
	getline(cin,nombre);
	
	//abriendo el archivo
	fichero.open(nombre.c_str(), ios::out);
	
	//condicional
	if(fichero.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	cout<<"Ingrese el numero de frases que tendra el archivo: ";
	cin>>numf;
	
	for(int i=0; i<numf; i++){
		fflush(stdin);
		cout<<"Escriba la frase "<<i+1<<": "<<endl;
		getline(cin,frase);
		fichero<<i+1<<". "<<frase;
		fichero<<endl;
		
	}
	
	fichero.close();
}



