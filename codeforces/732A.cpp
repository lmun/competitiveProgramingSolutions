#include <iostream>
#include <cstring>

using namespace std;


int main(){    
    int price,coin,i;
    cin >> price >> coin;
    int act=price%10;
    for(i=1;i<10&&act!=coin&&act%10!=0;i++,(act+=price)%=10){}
    cout << i << '\n';
    return 0;
}