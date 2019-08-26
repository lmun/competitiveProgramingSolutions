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
int n;
vi cri;
void aux(vi &resp, vi &usado, int nu){
    if(nu+1==n and cri[resp[nu]+1]==0){
        cout << 1;
        for (int i = 1; i < n; ++i)
        {
            cout <<' '<< resp[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!usado[i] and cri[resp[nu]+i]==0)
        {
            resp[nu+1] = i;
            usado[i] = 1;
            aux(resp, usado, nu+1);
            usado[i] = 0;
            resp[nu+1] = 0;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int m=100;
    cri.assign(m,0);
    for (int i = 2; i < m; ++i)
    {
        if (cri[i]==0)
        {
            for (int j = i*i; j < m; j+=i)
            {
                cri[j] = i;
            }
        }
    }
    int t = 0;
    while(cin >> n) {
        if(t){
            cout << endl;
        }
        cout << "Case " << ++t << ':' << endl;
        vi resp(n,1);
        vi usado(n+1, 0);
        usado[1] = 1;
        aux(resp, usado, 0);
    }
    return 0;
}
