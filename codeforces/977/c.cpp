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
	int n,k;
	cin>>n>>k;
	std::vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	v.push_back(((int)pow(10,9))+100);
	sort(v.begin(), v.end());
	int res;
	if(k==0){
		if(v[0]>1){
			res=1;
		}else{
			res=-1;
		}
	}else if(v[k-1]==v[k]){
		res=-1;
	}else{
		res=v[k-1];
	}
	
	cout << res << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
