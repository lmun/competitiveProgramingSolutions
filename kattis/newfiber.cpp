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
	int n, m;
	cin >> n >> m;
	// cin.ignore(); must be there when using getline(cin, s)
	vvi mat(n, vi(0));
	vi card(n, 0);
	vi caro(n, 0);
	vi posi(n, 0);
	int codo = m;
	while (codo--) {
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
		card[a]++,card[b]++;
	}
	for (int i = 0; i < n; ++i)
	{
		caro[i] = card[i];
	}
	std::vector<pii> pari(0);
	for (int i = 0; i < n; ++i)
	{
		pari.push_back(mp(card[i]-1, i));
	}
	sort(all(pari));
	int acc = 0;
	int res = 0;
	for(pii a: pari){
		cout << a.f << ' ' << a.s << endl;
		acc += a.f;
		if(acc <= n - 2){
			res++;
			posi[a.s] = 1;
		}
	}
	for(int g: posi){
		cout << g << ' ';
	}
	cout << endl;
	cout << res << endl;
	cout << n-res << endl;
	vi inc(n,0);
	int next = 0, tot = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if(posi[i] == 0 || inc[i] == 1 || caro[i] <= 1){
			continue;
		}
		while(caro[i] > 0){
			while(next==i || inc[next]==1){
				next++;
			}
			cout << i << ' ' << next << endl;
			if(tot >= n-1){
				break;
			}
			caro[i] -= 1;
			caro[next] -= 1;
			inc[i] = 1;
			inc[next] = 1;
			tot += 1;
			next++;
		}
	}
	return 0;
}
