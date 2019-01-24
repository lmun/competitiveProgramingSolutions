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
	long long x=100001;
	std::vector<int> v(x,0);
	std::vector<int> pri;
	for (int i = 2; i < x; ++i)
	{
		if(v[i]>0){
			continue;
		}else{
			pri.push_back(i);
			for(long long a=i+i;a<x;a+=i){
				if (v[a] == 0){
					v[a] = i;
				}
			}
		}
	}
	long long a,b;
	std::vector<int> pokes(x,0);

	for (int i = 0; i < T; ++i)
	{
		cin >> b;
		a=b;
		while(v[a]!=0){
			pokes[v[a]]++;
			long long c=a;
			while(!(a%v[c])) {
			    a/=v[c];
			}
		}if(a>1){
			pokes[a]++;
		}
	}
	long long max = pokes[0];
	//long long ind = 0;
	for (int i = 2; i < x; ++i)
	{
		if(pokes[i] > max){
			max = pokes[i];
			//ind = i;
		}
	}
	if(max == 0 && T > 0){
		max=1;
	}
	cout << max << endl;
	return 0;
}
