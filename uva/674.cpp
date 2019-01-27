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
std::vector<std::vector<int> > v(7500,std::vector<int> (5,-1));

int ways(int n,int k){
	if (n <= 0) {
		return 0;
	}
	if (k == 0 && n > 0) {
		return 1;
	}
	if (v[n][k] >= 0) {
		return v[n][k]; 
	}
	if (k == 4) {
		v[n][k] = ways(n-50, k) + ways(n, 3);
		if (n==50) {
			v[n][k]++;
		}
		
	} else if (k == 3) {
		v[n][k] = ways(n-25, k) + ways(n, 2);
		if (n == 25) {
			v[n][k]++;
		}
	} if(k == 2) {
		v[n][k] = ways(n-10, k) + ways(n, 1);
		if (n == 10) {
			v[n][k]++;
		}
	} if(k == 1) {
		v[n][k] = ways(n-5, k) + ways(n, 0);
		if (n == 5) {
			v[n][k]++;
		}
	}
	
	return v[n][k];
}

int main()
{
	
	int n;
	
	while(cin>>n){
		cout << ways(n,4) << endl;
	}
	return 0;
}
