#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
long long modpow(long long base, long long exp, long long m) {

   long long result = 1;

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
	int n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	string s;
	set<int> se;
	for (int i = 0; i < n; ++i)
	{
		std::vector<int> v(30,0);
		cin >> s;
		for (int j = 0; j < (int)s.size(); ++j){
			v[s[j]-'a'+1]++;
		}
		long long p=1;
		long long res=0;
		for (int k = 0; k < 30; ++k)
		{
			if(v[k]>0){
				res+=((k*p)%mod);
			}
			p*=26;
			p%=mod;
			//cout << res << '\t'<<k<< endl;
		}
		se.insert(res);
	}
	cout << se.size() << endl;
	return 0;
}
