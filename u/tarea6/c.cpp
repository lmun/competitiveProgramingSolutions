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
	vvi mat(n,vi(n,0));
	vvi mama(n,vi(n,mod));
	vi del(n,0);
	vll res(n,0);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> mat[i][j];
			mama[i][j] = mat[i][j];
		}
	}
	for (int i = 0; i < n; ++i){
		cin >> del[i];
		del[i]--;
	}
	for (int i = n-1; i >=0; i--){
		int no=3;
		// cout << del[i] << endl;
		while(no--){
			ll misu=0;
		for (int j = i; j < n; ++j){
			for (int k = i; k < n; ++k){
				if(k==j){
					continue;
				}
				if(mama[del[j]][del[k]] > mama[del[j]][del[i]]+mama[del[i]][del[k]]){
					mama[del[j]][del[k]] = mama[del[j]][del[i]]+mama[del[i]][del[k]];
					// cout << del[i] << del[j] << del[k] << endl;
					cout << "aaa"<<endl;
				}if(mama[del[j]][del[i]] > mama[del[j]][del[k]]+mama[del[k]][del[i]]){
					mama[del[j]][del[i]] = mama[del[j]][del[k]]+mama[del[k]][del[i]];
					//cout << del[i] << del[j] << del[k] << endl;
					cout << "bbb"<<endl;
				}
				misu += mama[del[j]][del[k]];
			}
		}

		// cout << misu << endl;
		res[i] = misu;}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}
