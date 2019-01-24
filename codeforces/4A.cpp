#include <iostream>
using namespace std;

int main(){    
    int number;

    cin >> number;
    string par=(number%2==0&&number>3)?"YES":"NO";
    cout << par << "\n";
    return 0;
}