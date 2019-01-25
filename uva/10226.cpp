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
    int T;
    cin >> T;
    cin.ignore();// must be there when using getline(cin, s)
    string st;
    getline(cin, st);
    for (int t = 0; t < T; ++t){
     
        map<string, int> mimapa;
        int tot = 0;
        while(getline(cin, st)){
            
            //cout << st << endl;
            if (!st.size())
            {
                break;
            }
            tot +=1;
            if (mimapa.count(st)) {
                mimapa[st] += 1;
            } else {
                mimapa[st] = 1;
            }
        }
        if(t){
            cout << endl;
        }
        cout << fixed << setprecision(4);
        for (std::map<string, int>::iterator i = mimapa.begin(); i != mimapa.end(); ++i)
        {

            cout << i->f << ' ' << (i->s*100.0)/tot << endl;
        }
    }

    return 0;
}
