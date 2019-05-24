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
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int bugs, inter;
		cin >> bugs >> inter;
		vvi mat(bugs, vi());
		int a, b;
		int c = inter;
		while (c--) {
			cin >> a >> b;
			a--, b--;
			mat[a].push_back(b);
			mat[b].push_back(a);
		}
		vi se(bugs, 0);
		bool susp = false;
		for (int i = 0; i < bugs; ++i)
		{
			if (se[i] != 0) {
				continue;
			}
			queue<int> que;
			que.push(i);
			se[i] = 1;
			while (!que.empty()) {
				int num = que.front();
				que.pop();
				int nenum = (se[num] % 2) + 1;
				for (int aa : mat[num]) {
					if (se[aa] > 0) {
						if ( se[aa] != nenum){
							susp = true;
						}
					} else {
						se[aa] = nenum;
						que.push(aa);
					}
				}
			}
		}
		cout << "Scenario #" << t + 1 << ":\n";
		if (!susp) {
			cout << "No s";
		}else{
			cout << "S";
		}
		cout << "uspicious bugs found!\n";
		// for (int i = 0; i < bugs; ++i)
		// {
		// 	cout << i << " .. " << se[i] << endl;
		// }

	}
	return 0;
}
