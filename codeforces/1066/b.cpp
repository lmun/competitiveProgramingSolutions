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
    int n, r;
    cin >> n >> r;
    // cin.ignore(); must be there when using getline(cin, s)
    vi pos(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> pos[i];
    }
    int laston = -mod;
    int lastposi = -mod;
    int on = 0;
    for (int i = min(r-1, n-1); i >= 0; --i)
    {
        if (pos[i]==1)
        {
            laston = i;
            lastposi = i;
            on = 1;
            break;
        }
    }
    if (lastposi < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = lastposi; i < n; ++i)
    {
        if (pos[i] == 1)
        {
            if (i-r+1 > lastposi+r)
            { //me pase po
                 //printf("aa%d\t%d\n", i, lastposi);
                on = -1;
                break;
            } else {
                if (i-r+1 > laston+r) // tengo que prender otra mas antes que esta
                {
                    if (lastposi == laston)
                    {
                        on = -1;
//                        printf("bb%d\n", i);
                        break;
                    } else {
                        on += 1;
                        laston = lastposi;
                    }
                }
                lastposi = i;
            }
            //printf("xx%d\t%d\n", i, on);
        }
    }
    if (on > 0 && laston+r-1 < n-1)
    {
//        printf("la%d\t%d\t%d\n", laston, on, lastposi);
            if (lastposi+r-1 >= n-1)
            {
                on++;
            } else {
                on = -1;
            }
    }
    cout << on << endl;

    return 0;
}
