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

ll gcd(ll a, ll b){
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	vi nums(12, 0);
	int n;
	for (int t = 0; t < T; t++)	{
		cin >> n;
		ll mult = 1;
		ll nume = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			mult *= nums[i];
		}
		for (int i = 0; i < n; ++i)
		{
			nume += mult / nums[i];
		}
		mult *= n;
		ll comun = gcd(nume, mult);
		cout << "Case " << t+1 << ": " << mult/comun << '/' << nume/comun << endl;
	}
	return 0;
}
