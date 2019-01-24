#include <iostream>

using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n],q[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>q[i];
	}

	for(int i=0;i<m;i++){
		int iz=-1,der=n-1;
		while((der-iz)>1){
			int dif=der-iz;
			if(a[iz+(dif/2)]>=q[i]){
				der=iz+(dif/2);
			}
			else if(a[iz+(dif/2)]<q[i]){
				iz=iz+(dif/2);


			}

		}
		if(a[der]==q[i]){
			cout<<der<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}