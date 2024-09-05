#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int menu(){
	int x;
	system("cls");
	cout<<"<---- Bienvenido ---->"<<endl<<endl;
	cout<<"1. Agregar Persona"<<endl;
	cout<<"2. Ver personas"<<endl;
	cout<<"3. Salir"<<endl;
	cin>>x;
	return x;
}

bool verifica(string ced){
	ifstream leer("Persona.txt", ios::in);
	string Nom;
	string Ced;
	string Ape;
	leer>>Nom;
	while(!leer.eof()){
		leer>>Ape;
		leer>>Ced;
		
		if(Ced == ced){
			leer.close();
			return false;
		}
		leer>>Nom;
	}
	leer.close();
	return true;
}

void agregar(ofstream &es){
	system("cls");
	
	string Nom;
	string Ced;
	string Ape;
	es.open("Persona.txt", ios::app);
	cout<<"Nombre ";
	cin>>Nom;
	cout<<"Apellido ";
	cin>>Ape;
	cout<<"Cedula: ";
	cin>>Ced;
	if(verifica(Ced));
	es<<Nom<<" "<<Ape<<" "<<Ced<<"\n";
	es.close();
}

int main(){
	ofstream Esc;
	int op;
	do{
		system("cls");
		op = menu();
		switch(op){
			case 1:{
				agregar(Esc);
				break;
			}
		}//switch
	}while(op!=3);
	
	system("pause");
	return 0;
	
}





