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
	string m;
	cin>>m;
	int a=1,b=0,c=0;
	for(char g:m){
		if(g=='A'){
			a^=b;
			b^=a;
			a^=b;
		}else if(g=='B'){
			b^=c;
			c^=b;
			b^=c;
		}else{
			c^=a;
			a^=c;
			c^=a;
		}
	}
	cout << (a+b*2+c*3) << endl;
	return 0;
}
