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
	int t;
	cin >> t;
	// cin.ignore(); must be there when using getline(cin, s)
	while (t--)
	{
		int n, s, q,aente;
		cin >> n >> s >> q;
		aente = 0;
		std::vector<deque<int> > vesta(n, deque<int> ());
		for (int i = 0; i < n; ++i)
		{
			int tot, num;
			cin >> tot;
			aente += tot;
			while(tot--) {
				cin >> num;
				vesta[i].push_back(num);
			}
		}
		deque<int> mique;
		int res = 0;
		bool listoko = false;
		for (int i = 0;!listoko; ++i) {
			int in = i%n;
			while(!mique.empty() && (mique.front() == in+1 || vesta[in].size() < q)) {
				int aux = mique.front();
				mique.pop_front();
				res += 1;
				if (aux != in +1) {
					vesta[in].push_back(aux);
				} else {
					aente--;
					//cout << aente << endl;
					if (aente == 0)
					{
						listoko = true;
						break;
					}
				}
			}
			if (listoko)
			{
				break;
			}
			while(mique.size() < s && !vesta[in].empty()) {
				int aux = vesta[in].front();
				vesta[in].pop_front();
				mique.push_front(aux);
				res += 1;
			}
			res += 2;
		}
		cout << res << endl;
	}
	return 0;
}
