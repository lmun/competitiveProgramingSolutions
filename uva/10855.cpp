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

char big[1000][1000];
char small[1000][1000];
char temp[1000][1000];

int serepe(char biga[1000][1000], int m, char small[1000][1000], int n){
	ll tot = 0;
	/*
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << small[i][j];
		}
		cout << endl;
	}*/
	for (int i = 0; i < m-n+1; ++i) {
		for (int j = 0; j < m-n+1; ++j) {
			bool esta = true;
			for (int ii = 0; ii < n; ++ii)
			{
				for (int jj = 0; jj < n; ++jj)
				{
					esta = esta && biga[i+ii][j+jj]==small[ii][jj];
				}
			}
			if (esta) {
				tot++;
			}
		}
	}
	return tot;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int m, n;
	
	// cin.ignore(); must be there when using getline(cin, s)
	while (scanf("%d %d", &m, &n)){
		if(m == 0 && n == 0){
			break;
		}

		for (int i = 0; i < m; ++i) {
			scanf("%s", big[i]);
		}

		for (int i = 0; i < n; ++i) {
			scanf("%s", small[i]);
		}
		
		for (int i = 0; i < 4; ++i)
		{
			if (i)
			{
				cout << ' ';
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						temp[j][k]=small[n-1-k][j];
					}
				}
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						small[j][k]=temp[j][k];
					}
				}
			}
			cout << serepe(big, m, small, n);	
		}
		cout << endl;

	}
	return 0;
}
