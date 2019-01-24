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
ll gcdExtended(ll a, ll b, ll *x, ll *y){
    // Base Case
    if (a == 0)    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
gcdExtended

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
	ll c,n,e;
	
	// cin.ignore(); must be there when using getline(cin, s)
	long long x=31623;
	std::vector<int> criba(x,0);
	std::vector<int> pri;
	for (int i = 2; i < x; ++i){
		if(criba[i]==0){
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i*i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	ll onum,unum;
	while(cin>>n>>e>>c)
	{
		
		for (unsigned i = 0; i < pri.size(); ++i)
		{
			if(n%pri[i]==0){
				unum=(pri[i])-1;
				onum=(n/pri[i])-1;
				break;
			}
		}
		ll x,y;
		ll umul=unum*onum;
		gcdExtended(unum*onum,e,&y,&x);
		//printf("%lld\t%lld\t%lld\t%lld\t%lld\t%lld\n",e,unum,onum,x,y ,(x*e)%umul);
		x=x<0?x+umul:x;
		//printf("%lld\t%lld\t%lld\t%lld\t%lld\t%lld\n",e,unum,onum,x,y ,(x*e)%umul);
		ll res=modpow(c,x,n);
		cout << res << endl;
	//	cout << modpow(res-1,e,n)<< endl;
	}

	//cout << modpow(726,71,1073)<< endl;
	return 0;
}
