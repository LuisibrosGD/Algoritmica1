#include <iostream>
#include <conio.h>
#include <stdlib.h>//rand
#include <time.h>//rand

using namespace std;
int x[6]={2,3,4,5,6,7};

void burbuja(int a[], int n){
	int temp=0;
	bool flag=true;
	for(int j=0; (j<n && flag ==true);j++){
		flag=false;
		for(int i=0; i<n;i++){
			if(a[i] > a[i+1]){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=true;
			}
			
		}//for(int j=0; j<n;j++)
		
		
	}//(int i=0; i<n;i++)
	
	for(int i=0; i<n;i++){
	  cout<<"Elemento "<<i+1<<" --> "<<a[i]<<endl;
	}
}

int main( ) {
int n=0;
cout<<"Ingresar cantidad de elementos --> ";cin>>n;
cout<<endl;
int arr[n];
srand(time(NULL));// inicializar valores random
for(int i=0; i<n;i++){
//	cout<<"ingresar elemento "<<i+1<<" --> ";cin>>arr[i];
    arr[i]=100+rand()%100+1;
	//cout<<endl;
}
//system("pause");
//system("CLS");
for(int i=0; i<n;i++){
	cout<<"Elemento "<<i+1<<" --> "<<arr[i]<<" por 2 es "<<arr[i]+arr[i];
	cout<<endl;
}
/*
n=6;
for(int i=0; i<n;i++){
	cout<<"Elemento "<<i+1<<" --> "<<x[i]<<" por 2 es "<<x[i]+x[i];
	cout<<endl;
}
*/
system("pause");
system("cls");

burbuja(arr, n);

}




