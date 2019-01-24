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
int main()
{
	std::ios::sync_with_stdio(false);
	int w,l;
	cin>>w>>l;
	// cin.ignore(); must be there when using getline(cin, s)
	w--;
	std::vector<ll> v(w);
	for (int i = 0; i < w; ++i)
	{
		cin >> v[i];
	}
	for (int i = l; i < w; ++i)
	{
		ll cap=v[i];
		ll count=0;
		for (int j = max(i-l,0); j < i; j++)
		{
			if(count==cap){
				break;
			}
			if(v[j] > 0 && count < cap){
				if(v[j] <= (cap-count)){
					count+=v[j];
					v[j]=0;
				}else{
					v[j]=v[j]-cap+count;
					count=cap;
				}
			}
		}
		v[i]=count;
	}
	ll total=0;
	for (int i = 1; i <= l; ++i)
	{
		total+=v[w-i];
	}
	cout << total << endl;
	return 0;
}
