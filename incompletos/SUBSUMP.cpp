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
#define vpii vector<pii >
#define wgraph vector<vpii >
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
char mat[15][15];
int nums[15][15];
int cols[15];
int rows[15];
int n, v, n2;
ll res;
int actual;
int puntos;
void backtrack(int i, int j){
    if(actual>v){
        return;
    }
    if (i==n)
    {
        res += actual==v;
        return;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     printf("%s\n",mat[i] );
    // }
    int nj=j+1, ni=i;
    if (nj==n)
    {
        nj = 0;
        ni++;
    }
    if (mat[i][j] == '.')
    {
        for (int k = 1; k <= n; ++k)
        {
            bool posi = true;
            for (int a = 0;posi and a < i; ++a)
            {
                if(nums[a][j]==k){
                    posi=false;
                }
            }
            for (int a = 0; posi and a < j; ++a)
            {
                if (nums[i][a]==k)
                {
                    posi=false;
                }
            }
            // cout << posi<< endl;
            if (posi)
            {
                nums[i][j] = k;
actual+=k;
                    backtrack(ni,nj);
                
                nums[i][j] = 0;
                actual -=k;
            }
        }
    } else{
        backtrack(ni,nj);    
    }
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    // cin.ignore(); must be there when using getline(cin, s)
    for (int t = 0; t < T; t++)    {
        scanf("%d %d", &n, &v);
        res = 0;
        actual = 0;
        n2 = n*n;
        puntos = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s",mat[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                nums[i][j] = 0;
                if (mat[i][j]=='.')
                {
                    puntos+=1;
                }

            }
            rows[i] = 0;
            cols[i] = 0;
        }
        backtrack(0, 0);
        printf("Case %d: %lld\n", t+1, res);
    }
    return 0;
}
