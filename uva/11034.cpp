#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int c;
    cin >> c;
    // cin.ignore(); must be there when using getline(cin, s)
    for (int kk = 0; kk < c; ++kk) {
        int le, m;
        cin >> le >> m;
        int largo;
        string arivalbank;
        deque<pii> arleft;
        deque<pii> arright;
        
        for (int i = 0; i < m; ++i){
            cin >> largo >> arivalbank;    
            if (arivalbank == "left") {
                arleft.push_front(mp(largo, i));
            } else {
                arright.push_front(mp(largo, i));
            }
        }
        if (kk != 101) 
        {
            //continue;
        }
        int viajes = 0;
        bool left = true;
        int cap = 0;
        deque<int> ferry;
        le *= 100;
        while(m) {
            //cout << 'x' << m << endl;
            //cout << cap << ' ' << le << ' ' << endl;
            //cout << arleft.size() << ' ' << arright.size() << ' ' << endl;
            //cout << arleft.back().f << ' ' << arright.back().f << ' ' << endl;
            while(!ferry.empty()){
                ferry.pop_front();
                cap = 0;
                m--;
            }
            while(left && !arleft.empty() && arleft.back().f + cap <= le){
                ferry.push_front(arleft.back().s);
                cap += arleft.back().f;
                //cout << cap << ' ' << le << endl;
                arleft.pop_back();
            }
            while(!left && !arright.empty() && arright.back().f + cap <= le ) {
                ferry.push_front(arright.back().s);
                cap += arright.back().f;
                arright.pop_back();
            }
            if (ferry.size() > 0 || (left && !arright.empty()) || (right && !arleft.empty())) {
                left = !left;
                viajes += 1;
            }
        }
        cout << viajes << endl;
    }
    return 0;
}
