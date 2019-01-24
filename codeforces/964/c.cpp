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
#define mod 1000000009
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
ll wtf(ll ap,ll bp,ll count,bool bbb){
	if(count==0){
		return 1;
	}
	if(bbb){
		return (ap*wtf(ap,bp,count-1,true)+bp*wtf(ap,bp,count-1,false))%mod;
	}else{
		return (bp*wtf(ap,bp,count-1,false))%mod;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string s;
	cin >> s;
	long long ans=0;
	for (int i = 0; i < k; ++i)
	{
		ll ab=(modpow(a,k-i-1,mod)*modpow(b,i,mod));
		ab%=mod;
		if(s[i]=='+'){
			ans+=ab;
		}else{
			ans-=ab;
		}
		
		//cout << ans << endl;
		while(ans<0){
			ans+=(10000000ll*mod);
		}
		ans%=mod;
	}
	while(ans<0){
		ans+=(100ll*mod);
	}
	ans%=mod;
	int count=(n+1)/k;
	//cout << count << endl;
	//return 1;
	//ll res=0;
	ll ap=modpow(a,k,mod);
	ll bp=modpow(b,k,mod);
	//ll lastbp=bp;
	ll okokok=wtf(ap,bp,count-1,true);
/*
	cout << "ok -"<<okokok << endl;

	for (int i = 0; i < count; ++i)
	{
		ll opt=((modpow(ap,count-i-1,mod)*modpow(bp,i,mod)));
		res+=opt;
		res%=mod;
		
	}*/
	//cout << res << endl;
	ll final=(okokok*ans)%mod;
	cout << final << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
