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
	ll a, b;
	cin >> a >> b;
	ll lim = 15000000;
	vi cri(lim,0);
	vi prim(0);
	prim.push_back(1);
	for (int i = 2; i < lim; ++i){
		if(cri[i] == 0){
			cri[i] = i;
			prim.push_back(i);
			for (int j = i+i; j < lim; j+=i){
				cri[j] = i;
			}
		}
	}
	ll ab = a+b;
	int hi=prim.size()-1;
	int lo=0;
	while(hi>lo){
		mid=(hi+lo+1)/2;
		if(pri[mid]*pri[mid] > ab){
			hi=mid-1;
		}else{
			lo=mid;
		}
	}
	for (int i = lo; i >= 0 ; i--)
	{
		if(ab % prim[])
	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
