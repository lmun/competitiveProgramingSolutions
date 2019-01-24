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
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<int> v(T);
	std::vector<int> s(T);
	for (int i = 0; i < T; ++i)
	{
		cin >> v[i];
	}
	s[0]=v[0];
	for (int i = 1; i < T; ++i)
	{
		s[i]=v[i]+s[i-1];
	}
	int mid = (s[T-1]+1)/2;
	int j=0;
	while(s[j]<mid){
		j++;
	}
	cout << (j+1) << endl;
	return 0;
}
