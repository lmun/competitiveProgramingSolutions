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
	int n,k;
	cin>>n >> k;
	std::vector<std::vector<int> > pos(n,std::vector<int> (n,0));
	std::vector<string> v(n);
	// cin.ignore(); must be there when using getline(cin, s)
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i){	
		int mal=0;
		for (int p = 0; p < k-1; ++p){
			if(v[i][p]=='#'){
				mal++;
			}
		}
		for (int j = k-1; j < n; ++j){
			if(v[i][j]=='#'){
				mal++;
			}
			if(mal==0){
				for (int t = 0; t < k; ++t){
					pos[i][j-t]++;
				}
			}
			if(v[i][j-k+1]=='#'){
				mal--;
			}
		}
	}
	for (int i = 0; i < n; ++i){	
		int mal=0;
		for (int p = 0; p < k-1; ++p){
			if(v[p][i]=='#'){
				mal++;
			}
		}
		for (int j = k-1; j < n; ++j){
			if(v[j][i]=='#'){
				mal++;
			}
			if(mal==0){
				for (int t = 0; t < k; ++t){
					pos[j-t][i]++;
				}
			}
			if(v[j-k+1][i]=='#'){
				mal--;
			}
		}
	}
	ll max=0;
	int maxy=1;
	int maxx=1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(pos[i][j]>max){
				max=pos[i][j];
				maxy=i+1;
				maxx=j+1;

			}
			//printf("%d\t",pos[i][j]);
		}
		//printf("\n");
	}
	cout << maxy << ' ' << maxx << endl;
	return 0;
}
