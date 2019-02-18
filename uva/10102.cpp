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
char mat[100][100];
int m, res;
vvi nums;
int dir[4][2] = {{0,1},{0,-1}, {1, 0},{-1, 0}};
void bfs(int i, int j, int a){
		if (i < 0 || j < 0 || j>=m || i >=m)
		{
		return;
		}
		if(nums[i][j] <= a){
			return;
		}
		nums[i][j] = a;
		for (int e = 0; e < 4; 	e++)
		{
			bfs(i+dir[e][0], j+dir[e][1], a+1);
		}
}

int main()
{
	std::ios::sync_with_stdio(false);
	while(scanf("%d", &m) > 0){
		for (int i = 0; i < m; ++i)
		{
			scanf("%s", mat[i]);
		}
		res = 0;
		nums.clear();
		nums.resize(m);
		for (int i = 0; i < m; ++i)
		{
			nums[i] = std::vector<int> (m, mod);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(mat[i][j] == '3'){
					//printf("%d\t%d\n", i, j);
					bfs(i, j, 0);
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(mat[i][j] == '1'){
					res = max(res, nums[i][j]);
				}
			}
		}
		printf("%d\n", res);
	}
	// cin.ignore(); must be there when using getline(cin, s)
	return 0;
}
