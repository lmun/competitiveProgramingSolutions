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
	string tg;
	cin>>n;
	cin >> tg;
	std::vector<int> v(700,0);
	for (int i = 0; i < n-1; ++i)
	{
		v[((tg[i]-'A')*26)+tg[i+1]-'A']++;
		
	}
	int maxi=0;
	int res=0;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		
		if(v[i]>maxi){
			maxi=v[i];
			res=i;
		}
	}
	cout << (char)((res/26)+'A') << (char)((res%26)+'A') << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
