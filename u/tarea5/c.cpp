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
	int n,yo,a;
	cin>>n>> yo;
	// cin.ignore(); must be there when using getline(cin, s)
	int ini=yo;
	int x=1001;
	std::vector<int> v(x);
	for (int i = 1; i < n; ++i){
		cin >> a;
		v[a]++;
	}
	int actual=0;
	for (int i = x; i >=0 && yo <= i; --i){
		actual+=v[i];
		if(yo+actual>i){
			yo=i+1;
		}else{
			yo+=actual;
		}

	}
	cout << yo-ini << endl;
	return 0;
}
