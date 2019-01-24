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
	int n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	long long x=1000000000000;
	int c=0, res=0;
	std::vector<ll> v;
	for(long long mul=1, i=1;;){
		while(mul%10==0){
			mul/=10;
			c++;
		}if(c==n){
			res++;
			v.push_back(i);
		}if(c>n){
			break;
		}
		mul*=(++i);
		mul%=x;
	}
	cout << res << endl;
	for (unsigned i = 0; i < v.size(); ++i)
	{

		cout << (i?" ":"") << v[i];
	}
	cout << endl;
	return 0;
}
