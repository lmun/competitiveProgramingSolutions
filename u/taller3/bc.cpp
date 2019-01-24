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
	int x1,y1,x2,y2,x,y;
	cin>>x1>>y1>>x2>>y2>>x>>y;
	bool sepuede=true;
	int k=100001;
	x1+=k;
	x2+=k;
	y1+=k;
	y2+=k;
	if(y2%y != y1%y){
		//printf("%d\t%d\n",y2%y, y1%y);
		sepuede=false;
	}
	if (x2%x != x1%x)
	{
		//printf("%d\t%d\n",x2%x, x1%x);
		sepuede=false;
	}
	if(((((y2-y1)/y)*x+x1-x2)/x)%2){
		//printf("%d\t%d\n",((((y2-y1)/y)*x+x1-x2)/x)%,(((y2-y1)/y)) );
		sepuede=false;
	}
	cout << (sepuede?"YES":"NO")<< endl;
	return 0;
}
