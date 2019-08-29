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
int cuenta;
char resp[200];
vector<string> numeros;
int total;
void aux(string &pala, int nextresp, int nextchar)
{
    if (total >= 100)
    {
        return;
    }

    if (nextchar == pala.size())
    {
        cout << resp << endl;
        total++;
        return;
    }
    // cout << resp << ' ' << nextresp << '.' << nextchar << endl;
    for (int i = 0; i < 26; i++)
    {
        // cout << resp << i << endl;
        if (numeros[i].size() > 0)
        {
            int ncopy = nextchar;
            while (ncopy < pala.size() and pala[ncopy] == '0' and pala[ncopy] != numeros[i][0])
            {
                ncopy++;
            }
            if (ncopy + numeros[i].size() > pala.size())
            {
                continue;
            }
            bool posible = true;
            for (int j = 0; j < numeros[i].size(); j++)
            {
                if (pala[ncopy++] != numeros[i][j])
                {
                    posible = false;
                }
            }
            // cout << resp << ' ' << ((char)(i+'a')) <<posible << endl;
            if (posible)
            {
                resp[nextresp] = i + 'a';
                aux(pala, nextresp + 1, ncopy);
                resp[nextresp] = 0;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int t = 0;
    while (cin >> n)
    {
        t++;
        numeros.assign(30, "");
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            char a;
            string b;
            cin >> a >> b;
            numeros[a - 'a'] = b;
        }
        total = 0;
        string pala;
        cin >> pala;
        cuenta = 0;
        cout << "Case #" << t << endl;
        aux(pala, 0, 0);
        cout << endl;
    }
    return 0;
}
