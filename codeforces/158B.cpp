#include <iostream>
using namespace std;

int main(){    
    int number,i,pasajeros;
    string palabra;
    cin >> number;
    int taxis=0;
    int total[]={0,0,0,0};
    for(i=0;i<number;i++){
    	cin >> pasajeros;
    	total[pasajeros-1]++;
    }
    taxis=0;
    //junto los grupos de 2
    taxis+=(total[1]/2);
    total[1]=total[1]%2;
    //meto los que estan solos a grupos de 3
    if(total[2]>=total[0]){
    	taxis+=total[0];
    	total[2]-=total[0];
    	total[0]=0;
    }else{
    	taxis+=total[2];
    	total[0]-=total[2];
    	total[2]=0;
    }
    //
    if(total[1]==1){
    	if(total[0]==1){
    		taxis++;
    		total[1]=0;
    		total[0]=0;
    	}else if(total[0]>1){
    		taxis++;
    		total[1]=0;
    		total[0]-=2;
    	}else{
    		taxis++;
    		total[1]=0;
    	}

    }
    taxis+=(total[0]/4);
    if(total[0]%4!=0){
    	taxis++;
    }
    taxis+=total[3];
    taxis+=total[2];
    cout << taxis << "\n";
    return 0;
    
}