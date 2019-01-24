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
	int k;
	string n;
	cin >> k >> n;
	//int ult=n.size()-1-(k-1)/9;
	int estaSum=0;
	for (unsigned i = 0; i < n.size(); ++i)
	{
		estaSum+=(n[i]-'0');
	}
	int j=0;
	sort(n.begin(), n.end());
	//cout << n;
	if(k>estaSum){
		for (unsigned i = 0; i < n.size(); i++)
		{	j++;
			estaSum+=('9'-n[i]);
			printf("%d\t%d\t\n",j,estaSum );
			if(estaSum>=k){
				break;
			}
		}
	}
	cout << j << endl;

	return 0;
}
