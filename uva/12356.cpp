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
	int s, b;
	// cin.ignore(); must be there when using getline(cin, s)
	while (cin >> s >> b) {
		if(s == 0 && b == 0){
			break;
		}
		vi izq(s, -1);
		vi der(s, -1);
		for (int i = 1; i < s; ++i) {
			izq[i] = i;
		}
		for (int i = 0; i < s-1; ++i)
		{
			der[i] = i+2;
		}
		while(b--) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			int le, ri;
			le = izq[l];
			ri = der[r];
			if(le!=-1){
				der[le-1] = ri;
				cout << le << ' ';
			}else{
				cout << "* ";
			}
			if (ri!=-1) {
				izq[ri-1] = le;
				cout << ri;
			}else{
				cout << "*";
			}
			cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
