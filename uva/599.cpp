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
vi uni(30);
vi aco(30);
int getrep(int a) {
	return uni[a] = (uni[a] == a ? a : getrep(uni[a]));
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		string edge, nodes;

		for (int i = 0; i < 30; ++i)
		{
			uni[i] = i;
			aco[i] = 1;
		}
		std::vector<pii > vepi;
		while (cin >> edge) {
			if (edge[0] == '*') {
				break;
			}
			//cout << edge[1]-'A'  << ' ' << edge[3] - 'A'<< endl;
			vepi.eb(edge[1] - 'A', edge[3] - 'A');
		}
		cin >> nodes;
		int tot = nodes.size() / 2 + 1;
		int acos = tot;
		for (pii aa : vepi) {
			//cout << getrep(aa.f) << ' ' << getrep(aa.s) << ' ' << tot << endl;
			if (getrep(aa.f) != getrep(aa.s))
			{
				tot--;
				if (aco[aa.f]) {
					aco[aa.f] = 0;
					acos--;
				}
				if (aco[aa.s]) {
					aco[aa.s] = 0;
					acos--;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tot - acos, acos);
		//cout << tot-acos << ' '<< acos << endl;
	}
	return 0;
}
