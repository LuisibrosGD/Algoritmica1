#include <iostream>

using namespace std;

int main (){
	//orden ascendente
	int num[7] = {1,2,3,4,5,7,6};
	int aux;
	bool interr;
	
	for(int i=0; i<7; i++){
		cout<<i+1<<" pasada"<<endl;
		cout<<"- - - - - - - - - -"<<endl;
		interr = false;
		for(int j=0; j<6; j++){ 
		
			if(num[j]>num[j+1]){ // 5 > 2
				aux = num[j]; //aux = 5
				num[j] = num[j+1]; //5<-2
				num[j+1]=aux; //2 <- 5
				//2, 5
				interr = true;
			}
		}
		if(interr == false){
			break;
		}
	}
	
	for(int i=0; i<7; i++){
		cout<<num[i]<<" ";
	}
	
}
