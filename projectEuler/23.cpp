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
	long long x=30000;
	std::vector<int> criba(x,0);
	std::vector<int> pri;
	for (int i = 2; i < x; ++i){
		if(criba[i]==0){
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i+i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	std::vector<int> abu;
	for (int i = 2; i < x; ++i){
		long long divi=1;
		
		int a=i;
		while(a>1){
			int fat=criba[a];
			int cu=0;
			while(a%fat==0){
				a/=fat;
				cu++;
			}
			divi*=((pow(fat,cu+1)-1)/(fat-1));
		}
		if(divi>i+i){
			abu.push_back(i);
		}
	}
	std::vector<int> res(x,0);
	for (int i = 0; i < (int)abu.size(); ++i){
		for (int j = i; j < (int)abu.size(); ++j){
			if(abu[i]+abu[j]<x){
				res[abu[i]+abu[j]]++;
			}else{
				break;
			}
		}
	}
	long long respu=0;
	for (int i = 1; i < x; ++i)
	{
		if(res[i]==0){
			respu+=i;
		}
	}
	cout << respu << endl;
	return 0;
}
