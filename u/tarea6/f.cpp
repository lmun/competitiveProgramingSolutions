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
	int n;
	cin>>n;
	string s;
	while(n--){
		std::vector<string> v(0);
		cin >> s;
		v.push_back(s);
		int ls = s.size();
		for (int i = 1; i < ls; ++i){
			cin >> s;
			v.push_back(s);
		}
		int maxpos = 0;
		int idpos = 0;
		for (int i = 0; i < ls; ++i){
			std::vector<int> dist(ls,0);
			for (int j = 0; j < ls; ++j){
				if (v[i][j]=='Y'){
					for (int k = 0; k < ls; ++k){
						if (v[j][k]=='Y' && v[i][k]=='N'){
							dist[k]=1;
						}
					}
				}
			}
			int ams = 0;
			for (int j = 0; j < ls; ++j){
				if (dist[j] == 1 && i!=j){
					ams++;
				}
			}
			if (ams > maxpos)
			{
				maxpos = ams;
				idpos = i;
			}
		}
		cout << idpos << ' ' << maxpos << endl;
	}
	
	return 0;
}
