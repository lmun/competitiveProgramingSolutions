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
int x = 0;
int cod[30];
int woke[30];

int getcode(char a) {
	a -= 'A';
	//cout << (int)a << endl;

	if (cod[a] == -1) {
		cod[a] = x++;
		woke[cod[a]] = 0;
	}
	return cod[a];
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		// vi cod(30, -1);
		// vi woke(30, -1);
		for (int i = 0; i < 30; ++i)
		{
			cod[i] = -1;
			woke[i] = -1;
		}
		vi inci(30, 0);
		// std::vector<pii > pai;
		vvi pai(30, vi(0));
		int m;
		cin >> m;
		string st;
		cin >> st;
		x = 0;
		string ari;
		while (m--) {
			cin >> ari;
			pai[getcode(ari[0])].push_back(getcode(ari[1]));
			pai[getcode(ari[1])].push_back(getcode(ari[0]));
			//	cout << ari[0] << getcode(ari[0]) << endl;
		}
		for (char a : st) {
			woke[getcode(a)] = 1;
			for (int aaa : pai[getcode(a)]) {
				inci[aaa]++;
			}
		}
		bool fin = false;
		int woken = 0;
		int res = 0;
		while (!fin) {
			fin = true;
			vi vinci(30,0);
			for (int i = 0; i < 30; ++i)
			{
				vinci[i] = inci[i];
			}
			for (int i = 0; i < 30; ++i)
			{
				if (woke[i] == 0 && inci[i] > 2) {
					fin = false;
					woke[i] = 1;
					woken++;
					for (int aaa : pai[i]) {
						vinci[aaa]++;
					}
				}
			}
			inci = vinci;
			if (!fin) {
				res += 1;
			}
		}
		if (woken + 3 < n) {
			cout << "THIS BRAIN NEVER WAKES UP\n";
		} else {
			cout << "WAKE UP IN, " << res << ", YEARS\n";
		}
		//cout << woken << res << endl;
	}
	return 0;
}
