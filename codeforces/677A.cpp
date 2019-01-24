#include <iostream>
#include <cstring>

using namespace std;


int main(){    
    int number,i,h,act;

    cin >> number >> h;
    int total=number;
    for(i=0;i<number;i++){
    	cin >> act;
    	if(act>h){
    		total++;
    	}
    }
    cout << total << '\n';
    return 0;
}