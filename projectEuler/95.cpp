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
	long long  x=10000001;
	std::vector<long long> v(x,0);
	std::vector<long long> sumd(x,0);
	for (long long i = 2; i < x; ++i){
		//cout << i<<"a\n";
		if(v[i]==0){
			v[i]=i;
			for (long long j = i*i; j < x; j+=i){
				v[j]=i;
			}
		}
	}
	//cout << "a" << endl;
	for (long long i = 2; i < x; ++i){
		//printf("%lld %lld\n",i,v[i]);
		vector<pair<int,int> > seti;
		set<long long> setd;
		//seti.push_back(1);
		
		sumd[i]=1;
		long long a=i;
		while(a>1){
			int divi=v[a];
			int coun=0;
			while(a%divi==0){
				coun++;
				a/=divi;
			}
			sumd[i]*=((pow(divi,coun+1)-1)/(divi-1));
		
		}

		sumd[i]-=i;
	}
	
	ll ind=1;
	std::vector<long long> amiable(x,0);
	amiable[0]=ind++;
	amiable[1]=ind++;
	ll ml=0;
	for (long long i = 2; i < x; ++i){
		if(amiable[i]==0){
			amiable[i]=ind++;
			ll j=sumd[i];
			while(j < x && amiable[j] == 0){
				amiable[j] = ind++;
				if(sumd[j]>=x){
					break;
				}
				if(amiable[sumd[j]]==0){
					j=sumd[j];
				}

			}
			if(j < x && sumd[j] < x && amiable[sumd[j]]>=amiable[i] && amiable[j]-amiable[i] >= ml){
				printf("%lld %lld %lld %lld %lld %lld %lld\n", amiable[j]-amiable[i],i,j,ind,sumd[j],amiable[j],amiable[sumd[j]]-amiable[j]);
				ml=amiable[j]-amiable[sumd[j]];
			}
		}
		
	}
	long long tt,nt;
	cin >> tt;
	while(tt--){
		cin >> nt;
		ll esteres=0;
		for (int i = 0; i < (int)amiable.size(); ++i)
		{
			if(amiable[i]<nt){
				esteres+=amiable[i];
			}
		}
		cout << esteres << endl;
	}
	// cin.ignore(); must be there when using getline(cin, s)
	ll p=2856;
	for (int i = 0; i < 100; ++i)
	{
		cout << sumd[p]<< '\t' << amiable[p]<< endl;
		p=sumd[p];
	}
	return 0;
}