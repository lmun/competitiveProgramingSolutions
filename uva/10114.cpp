#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
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
	int m, d;
	long double dp,  al;
	while(cin >> m >> dp >> al >> d){
		if(m<0){
			break;
		}
		long double cuo = al/m;
		std::vector<long double> v(m+10,0);
		int i = -1;
		int a;
		long double b;
		while(d--){
			cin >> a >> b;
			while(++i < a){
				v[i] = v[i-1];
			}
			v[i] = b;

		}
		while(i < m + 5){
			v[i++] = b;
		}
		long double ini = dp + al;
		long double act = ini;
		for (int i = 0; i <= m+1; ++i) {
			act = act-act*v[i];
			ll spe = cuo * i;
			// cout << i << ' ' << act << '=' << al-spe << endl;
			if (al-spe < act) {
				cout << i << " month" << (i!=1?"s\n":"\n");
				break;
			}
		}
	}
	return 0;
}
