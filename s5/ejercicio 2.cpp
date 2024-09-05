#include <iostream>

using namespace std;

int main (){
	int num, *dir_num, divi=0, no_divi=0;
	
	cout<<"Ingrese un numero: "; cin>>num;
	
	dir_num=&num;
	
	for(int i=1; i<=*dir_num; i++){
		if(*dir_num%i==0){
			divi=divi+1;
		}else{
			no_divi=no_divi+1;
		}
	}
	if(divi==2){
		cout<<"El numero "<<*dir_num<<" es primo"<<endl;
		
	}else{
		cout<<"El numero "<<*dir_num<<" no es primo"<<endl;
	}
	cout<<"Direccion: "<<dir_num;
	
	return 0;
}
