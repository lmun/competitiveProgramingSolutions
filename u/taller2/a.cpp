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
	int s,v1,v2,t1,t2;
	cin>>s>>v1>>v2>>t1>>t2;
	int fir=s*v1+2*t1;
	int sec=s*v2+2*t2;
	if(fir==sec){
		cout << "Friendship\n";
	}else{
		cout << ((fir<sec)?"First":"Second") << endl;
	}
	return 0;
}
