#include <iostream>
using namespace std;
int main(){
	
	//usaremos una bandera o un interruptor para romper un ciclo
	
	int vector[] = {1,99,100,-4,-78};
	int n = 5;
	int i,j, aux;
	bool bandera;
	
	
	
	/*
	
			Primera iteraccion i=1 -> bandera=false j=4
			45  > 0
			{1,99,100,-78,-4}
			bandera=true
			
			segunda iteraccion i=2 -> bandera = false j=3
	
	
	
	
	*/
	
	for(i=1; i<n; i++){
		bandera = false;
		for(j=n-1;j>=i;j--){
			if(vector[j-1] > vector [j]){
				aux = vector[j-1];
				vector[j-1]=vector[j];
				vector[j]=aux;
				bandera=true;
			}
		}
		if (bandera == false){
			break;
		}
	}
	
	for(i=0; i<n; i++){
		cout<<vector[i]<<" ";
	}
	
	
	system("pause");
	return 0;
}
