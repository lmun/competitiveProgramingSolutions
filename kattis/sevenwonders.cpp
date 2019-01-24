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
char cartas[3]={'T','G','C'};
int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<ll> v(130,0);
	string w;
	cin>>w;
	for(char ch:w){
		v[ch]++;
	}
	long long total=0;
	long long minimo=inf;
	for (int i = 0; i < 3; ++i)
	{
		total+=v[cartas[i]]*v[cartas[i]];
		minimo=min(minimo,v[cartas[i]]);
	}
	total+=7*minimo;
	cout << total << endl;
	
	return 0;
}
