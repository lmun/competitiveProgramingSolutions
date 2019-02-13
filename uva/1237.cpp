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
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		if(t){
			cout << endl;
		}
		int n;
		cin >> n;
		std::vector<pair<string, pii > > v;
		while(n--){
			string name;
			int mi, ma;
			cin >> name >> mi >> ma;
			v.push_back(mp(name,mp(mi, ma)));
		}
		int q;
		cin >> q;
		while(q--){
			int cost;
			cin >> cost;
			string resp = "UNDETERMINED";
			int hay = 0;
			for(auto ww:v){
				if(ww.s.f <= cost && ww.s.s >= cost){
					hay++;
					resp = ww.f;
				}
			}
			if(hay >1){
				cout << "UNDETERMINED\n";
			}else{
				cout << resp << endl;
			}
		}
	}
	return 0;
}
