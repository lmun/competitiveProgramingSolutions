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
int x=10002;
std::vector<int> happy(1000,-1);
std::vector<int> pri(x,0);

bool isHappy(int h){
	int po=h;
	if(h<1000 && happy[h]==1){
		return true;
	}if(h<1000 && happy[h]==0){
		return false;
	}
	//cout << h << endl;
	int sum=0;
	while(po>0){
		int dig=po%10;
		sum+=(dig*dig);
		po/=10;
	}
	//cout << sum << endl;
	if(1==sum){
		happy[h]=1;
		return true;
	}else{
		happy[h]=0;
		if(isHappy(sum)){
			happy[h]=1;
		}
	}
	return happy[h]==1;
}

int main()
{
	//std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	int a,b;
	// cin.ignore(); must be there when using getline(cin, s)
	pri[1]=10;
	
	for (int i = 2; i < x; ++i){
		if(!pri[i]){
			for (int j = i*i; j < x; j+=i){
				pri[j]=i;
			}
		}
	}


	while(T--)
	{
		cin >> a >> b;
		/*
		for (b = 0; b < 100; ++b)
		{
			cout << a << ' ' << b << ' ' << ((b>1&&pri[b]==0&&isHappy(b))?"YES":"NO") << endl;	
		}*/
		cout << a << ' ' << b << ' ' << ((b>1&&pri[b]==0&&isHappy(b))?"YES":"NO") << endl;
	}
	return 0;
}
