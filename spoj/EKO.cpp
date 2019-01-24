#include <bits/stdc++.h>
using namespace std;

long long madera(long long arreglo[],long long altura, long long largo){
	long long suma=0;
	for(long long i=0;i<largo;i++){
		if(arreglo[i]-altura>0){
			suma+=arreglo[i]-altura;
		}
	}
	return suma;
}

int main(){
	long long N,M;
	cin >> N >> M;
	long long Arboles[N];
	long long maximo=0;
	for(long long i = 0; i<N ;i++){
		cin >> Arboles[i];
		maximo=max(maximo,Arboles[i]);
	}
	
	long long A=0,B=maximo;
	while(A<B){
		long long mid=A+(B-A+1)/2;
		if(madera(Arboles,mid,N)<M){
			B=mid-1;
		}else{
			A=mid;
		}
	}
	cout << B << endl;

}