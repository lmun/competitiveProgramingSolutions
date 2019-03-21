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
ll modpow(ll base, ll exp, ll m) {

   ll result = 1;

   while (exp > 0) {
      if ((exp & 1) > 0) result = (result * base) % m;
      exp >>= 1;
      base = (base * base) % m;
   }

   return result;

 }
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	// cin.ignore(); must be there when using getline(cin, s)
	vvi mat(n, vi(0));
	for (int t = 0; t < n-1; t++)	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c == 1){
			continue;
		}
		a--, b--;
		mat[a].push_back(b);
		mat[b].push_back(a);

	}
	vi visi(n, 0);
	queue<int> que;
	vi tam;
	for (int i = 0; i < n; ++i)
	{
		if(visi[i]){
			continue;
		}
		visi[i] = 1;
		int k = i;
		int si = 0;
		que.push(i);
		while(!que.empty()){
			int q = que.front();
			si++;
			que.pop();
			for(int aa:mat[q]){
				if(!visi[aa]){
					visi[aa] = 1;
					que.push(aa);
				}
			}
		}
		tam.push_back(si);
	}
	ll tot = 0;
	for(int tt:tam){
		// cout << tt << endl;
		tot += modpow(tt, k, mod);
		tot %= mod;
	}

	ll res = modpow(n, k, mod)+mod;
	cout << (res-tot)%mod << endl;
	return 0;
}
