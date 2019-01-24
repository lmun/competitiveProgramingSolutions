#include <iostream>
#include <cstring>

using namespace std;

int main(){    
    int number;

    cin >> number;
    int i;
    string palabra;
    for(i=0;i<number;i++){
    	cin >> palabra;
    	if(palabra.length()>10){
    		cout << palabra[0] << palabra.length()-2 << palabra[palabra.length()-1] << "\n";
    	}else{
    		cout << palabra << "\n";
    	}
    }
    return 0;
}