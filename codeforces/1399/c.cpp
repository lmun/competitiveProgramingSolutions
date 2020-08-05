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
vi nums;
unsigned int n;
vvi mat;
ll auxi(int aa, int bb){
	int a = aa;
	int b = bb;
	if (mat[a][b]>0)
	{
		return mat[a][b];
	}
	ll su = nums[a]+nums[b];
	int co = 1;
	a++,b--;
	while(b>a){
		if (nums[a]+nums[b]==su)
		{
			co += auxi(a,b);
			break;
		} else if(nums[a]+nums[b]<su){
			a++;
		} else{
			b--;
		}
	}
	mat[aa][bb] = co;
	return co;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		cin >> n;
		map<ll,ll> mapa;
		nums.assign(n,0);
		mat.assign(n,vi(n,0));
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n-1; ++i) {
			for (int j = i+1; j < n; ++j) {
				ll co = auxi(i,j);
				if (mapa.count(nums[i]+nums[j]) == 0 or mapa[nums[i]+nums[j]] < co) {
					mapa[nums[i]+nums[j]] = co;
				}
			}
		}
		int resp = 0;
		for(auto const& a:mapa) {
			// cout << a.f << ' ' << a.s << endl;;
			if (a.s > resp) {
				resp = a.s;
			}
		}
		cout<< resp << endl;
	}
	return 0;
}
