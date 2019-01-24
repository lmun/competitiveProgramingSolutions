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
	printf("%d:\n",n);
	for (int i = 2; i <= n/2+1; ++i)
	{
		if(n%(i+i-1)==0||n%(i+i-1)==i){
			printf("%d,%d\n",i,i-1);
		}if(n%i==0){
			printf("%d,%d\n",i,i);
		}
	}
	
	return 0;
}
