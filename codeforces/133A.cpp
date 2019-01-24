#include <iostream>
using namespace std;

int main(){    
    int number,i;
    string palabra;
    cin >> palabra;
    for(i=0;i<palabra.length();i++){
    	if('H'==palabra[i]||'Q'==palabra[i]||'9'==palabra[i]){
    		cout << "YES" << "\n";
    		return 0;
    	}
    }
    cout << "NO" << "\n";
    return 0;
    
}