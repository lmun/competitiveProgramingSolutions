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
	long long n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	long long x=31622778;
	std::vector<int> criba(x,0);
	std::vector<int> pri;
	for (long long i = 2; i < x; ++i){
		if(criba[i]==0){
		//	cout << i << endl;
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i*i;a<x;a+=i){
				criba[a] = i;
				
			}
		}
	}
	int res=0;
	//cout << "ok"<< endl;
	while(n>=x){
		for (int i = 0; i < (int)pri.size(); ++i)
		{
			if(n%pri[i]==0){
				//res++;
				//cout << pri[i]<< endl;
				int div=pri[i];
				int veces=0;
				while(n>1 && n%div==0){
					n/=div;
					veces++;
				}
				//cout << veces << endl;
				int posi=0;
		while((posi*(posi+1))/2<=veces){
			posi++;
		}
		res+=posi-1;
				break;
			}
		}
	}
	//cout << res << endl;
	while(n>1){
		//printf("%lld\t%d\n",n,pri[n] );
		//res++;
		int div=criba[n];
		int veces=0;
		while(n>1 && n%div==0){
			n/=div;
			veces++;
		}
		int posi=0;
		while((posi*(posi+1))/2<=veces){
			posi++;
		}
		res+=posi-1;
	}
	cout << res << endl;
	return 0;
}
