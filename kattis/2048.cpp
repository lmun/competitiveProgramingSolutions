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
	std::vector<std::vector<int> > v(4,std::vector<int> (4,0));
	std::vector<std::vector<int> > res(4,std::vector<int> (4,0));
	// cin.ignore(); must be there when using getline(cin, s)
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> v[i][j];
		}
	}
	int dir;
	cin >> dir;
	if(dir==0){
		for (int i = 0; i < 4; ++i){
			int act=0;
			int p=0;
			
			for(int j=0;j<4;j++){
				if(act==0){
					act=v[i][j];
					continue;
				}
				if(v[i][j] > 0){
					if(v[i][j]==act){
						res[i][p++]=2*act;
						act=0;
					}else{
						res[i][p++]=act;
						act=v[i][j];
					}
				}
			}
			res[i][p++]=act;
			while(p<4){
				res[i][p++]=0;
			}
		}
	}else if(dir==1){
		for (int i = 0; i < 4; ++i){
			int act=0;
			int p=0;
			
			for(int j=0;j<4;j++){
				if(act==0){
					act=v[j][i];
					continue;
				}
				if(v[j][i] > 0){
					if(v[j][i]==act){
						res[p++][i]=2*act;
						act=0;
					}else{
						res[p++][i]=act;
						act=v[j][i];
					}
				}
			}
			res[p++][i]=act;
			while(p<4){
				res[p++][i]=0;
			}
		}
	}else if(dir==2){
		for (int i = 0; i < 4; ++i){
			int act=0;
			int p=3;
			
			for(int j=4;j>=0;j--){
				if(act==0){
					act=v[i][j];
					continue;
				}
				if(v[i][j] > 0){
					if(v[i][j]==act){
						res[i][p--]=2*act;
						act=0;
					}else{
						res[i][p--]=act;
						act=v[i][j];
					}
				}
			}
			res[i][p--]=act;
			while(p>=0){
				res[i][p--]=0;
			}
		}
	}else if(dir==3){
		for (int i = 0; i < 4; ++i){
			int act=0;
			int p=3;
			
			for(int j=3;j>=0;j--){
				if(act==0){
					act=v[j][i];
					continue;
				}
				if(v[j][i] > 0){
					if(v[j][i]==act){
						res[p--][i]=2*act;
						act=0;
					}else{
						res[p--][i]=act;
						act=v[j][i];
					}
				}
			}
			res[p--][i]=act;
			while(p>=0){
				res[p--][i]=0;
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << res[i][j] << ' ';
		}
		cout << res[i][3] << endl;
	}

	return 0;
}
