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
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define wgraph vector<vpii>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
char mat[12][12];
set<unsigned long long int> sese;
int n;
void backtrack(int i, int j, int cu, unsigned long long int lulu)
{
    if (i < 0 or i >= n or 0 > j or j >= n)
    {
        return;
    }
    if (mat[i + 1][j + 1] == 'X')
    {
        unsigned long long int lala = lulu | (1llu << ((8 * i) + j));
        if (cu == 7)
        {
            sese.insert(lala);
            return;
        }
        mat[i + 1][j + 1] = '.';
        backtrack(i + 1, j, cu + 1, lala);
        backtrack(i - 1, j, cu + 1, lala);
        backtrack(i, j + 1, cu + 1, lala);
        backtrack(i, j - 1, cu + 1, lala);
        mat[i + 1][j + 1] = 'X';
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    // cin.ignore(); must be there when using getline(cin, s)
    for (int t = 0; t < T; t++)
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                mat[i][j] = '.';
            }
        }
        scanf("%d", &n);
        sese.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", mat[i + 1] + 1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(i, j, 0, 0);
            }
        }
        cout << sese.size() << endl;
    }
    return 0;
}