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
	ll gcd( ll a, ll b )
	{
		if(b==0)
		{
		     return a;
		}
		else
		{
		     return gcd( b, a%b );
		}
	}
	ll lcm (ll a, ll b)
	{
		return (a*b)/gcd(a,b);
	}
ll divide(ll a){
	ll tot=0;
	while(a%2==0){
		a/=2;
		tot++;
	}
	while(a%3==0){
		a/=3;
		tot++;
	}
	while(a%5==0){
		a/=5;
		tot++;
	}
	return a==1?tot:-1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	// cin.ignore(); must be there when using getline(cin, s)
	ll c=gcd(a,b);
	ll da=divide(a/c);
	ll db=divide(b/c);
	if(da >= 0 && db >= 0){
		cout << (da+db) << endl;	
	}else{
		cout << -1 << endl;
	}
	return 0;
}
