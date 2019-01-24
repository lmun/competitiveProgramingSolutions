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
int costo(string &wor){
	int res = 0;
	for (int i = 0; i < (int)wor.size(); ++i)
	{
		res+=wor[i]-64;
	}
	return res;
}
int main()
{
	std::ios::sync_with_stdio(false);
	string str;
	std::vector<string> v;
	
	while(cin >> str){
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	long long total=0;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		total+=((i+1)*costo(v[i]));
	}
	cout << total << endl;
	return 0;
}
