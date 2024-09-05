#include <iostream> // definir las libraries

using namespace std;


int main() {
	int n, n2;
	char c;
	system("CLS"); // limpia pantalla
	//
	do{
	cout<<"\n\tIngresar un valor entero positivo---> ";
	cin>>n;
		if(n<=0){
			cout<<"Burro..lee bien"<<endl;
		}
	}while(n<=0);
	
	
	
	
	
	
	fflush(stdin);
	cout<<endl;
	do{
		cout<<"\n\tIngresar Tipo de Documento (d: documento/ p: paquete)---> ";cin>>c;
		cout<<endl;
		cout<<"valor de c --> "<<c;
	}while( c != 'd' && c !='p'&& c != 'D' && c !='P' );
	
	cout<<"\n\tIngresar otro valor entero positivo---> ";
	cin>>n2;
	cout<<endl;
	
	
	do{
		cout<<"\n\tIngresar un valor entre 20 y 30 positivo---> ";
		cin>>n;
		if(n<20 || n>30)
			cout<<"error"<<endl;		
	}while(n<20 || n>30);
	
	}
