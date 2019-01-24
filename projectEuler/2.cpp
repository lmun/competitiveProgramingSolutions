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
ll t,n;
int main()
{
	std::ios::sync_with_stdio(false);

	cin >> t;
	std::vector<ll> v(82,0);
	std::vector<ll> acc(82,0);
	v[0]=1;
	v[1]=1;
	for (int i = 2; i < 82; ++i)
	{
		v[i]=v[i-1]+v[i-2];
	}
	for (int i = 1; i < 82; ++i)
	{
		acc[i]=acc[i-1];
		if(i%3==2){
			acc[i]+=v[i];
		}
	}
	while(t--){
		cin >> n;
		int a=0,b=81;
		while(a<b){
			int mid=(a+b+1)/2;
			if(v[mid]<n){
				a=mid;
			}else{
				b=mid-1;
			}
		}
		cout << acc[a] << endl;	
	}
	
	return 0;
}
