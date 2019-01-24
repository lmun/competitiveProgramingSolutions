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
	int n,a,b,c;
	cin>>n;
	while(n--){
		cin >> a >> b >> c;
		std::vector<int> v(6,-1);
		v[0]=a+b;
		v[1]=a-b;
		v[2]=b-a;
		v[3]=a*b;
		v[4]=(a%b==0?a/b:-1);
		v[5]=(b%a==0?b/a:-1);
		bool posible=false;
		for (int i = 0; i < 6; ++i)
		{
			if(v[i]==c){
				posible=true;
			}
		}
		cout << (posible?"Possible":"Impossible") << endl;
	}
	
	return 0;
}
