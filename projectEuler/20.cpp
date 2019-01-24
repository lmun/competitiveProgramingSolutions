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
char * multiar(char* c,char *b){
	char a[3000];
	for (int i = 0; c[i]>='0'; ++i)
	{
		a[i]=c[i];
	}
	for (int i = 0; i < 3000; ++i)
	{
		c[i]='0';
	}
	c[2999]=0;
	for (int i = 0; a[i]>='0'; ++i){
		if(a[i]=='0'){
			continue;
		}
		int carri=0;
		int j;
		for (j = 0; b[j]>='0'; ++j){
			carri+=(a[i]-'0')*(b[j]-'0');
			c[j+i]+=carri%10;
			if(c[j+i]>'9'){
				c[j+i]-=10;
				c[j+i+1]++;
			}
			carri/=10;

		}
		while(carri>0){
			c[j+i]+=carri%10;
			carri/=10;
		}
	}
	return c;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t,num;
	int dp[1100];
	char res[3000];
		res[0]='1';
		res[1]=0;
		char fac[3000];
		fac[0]='1';
		for (int i = 1; i < 3000; ++i)
		{
			fac[i]=0;
		}

		for (int i = 1; i < 1020; ++i){
			fac[0]++;
			int j=0;
			while(fac[j]>'9'){
				fac[j]='0';
				if(fac[++j]<'0'){
					fac[j]='1';
				}else{
					fac[j]++;
				}
			}
			//cout << i << '\t'<< res << endl << fac<< endl;
			multiar(res,fac);
			int resultado=0;
			for (int i = 0; i < 2999; ++i)
			{
				resultado+=res[i]-'0';
			}
			dp[i+1]=resultado;
		}
		dp[0]=1;
		dp[1]=1;
		dp[2]=2;
		//cout << multiar(ot,n) << endl;
		
	cin>>t;
	// cin.ignore(); must be there when using getline(cin, s)
	while(t--){
		cin >> num;
		
		
		cout << dp[num] << endl;
	}

	return 0;
}
