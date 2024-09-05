#include <iostream>

using namespace std;

struct atleta{
	char nombre[20];
	char pais[20];
	int num_medallas;
	
}atletas[100];

int main(){
	
	int num_atletas, numMayor=0, j;
	
	cout<<"Digite el numero de atletas: "; cin>>num_atletas;
	
	for(int i=0;i<num_atletas;i++){
		fflush(stdin);
		cout<<"\nAtleta "<<i+1<<": "<<endl;
		cout<<"Escriba su nombre: "; cin.getline(atletas[i].nombre,20,'\n');
		cout<<"Escriba su pais: "; cin.getline(atletas[i].pais,20,'\n');
		cout<<"Ingrese el numero de medallas: "; cin>>atletas[i].num_medallas;
		if(atletas[i].num_medallas > numMayor){
			numMayor = atletas[i].num_medallas;
			j=i;
		}	
		
	}//for
	
	//Atleta con mas medallas
	cout<<"\nAtleta con mas medallas: "<<endl;
	cout<<"\nNombre: "<<atletas[j].nombre<<endl;
	cout<<"Pais: "<<atletas[j].pais<<endl;
	
	system("pause");
	return 0;
}
