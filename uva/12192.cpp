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
	int W, H;
	while(cin >> H >> W){
		// cout << H << endl;
		if (H == 0 && W==0)
		{
			break;
		}
		vvi nums(H, vi(W, 0));
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				cin >> nums[i][j];
			}
		}
		int q;
		cin >> q;
		while(q--){
			int ma, mi;
			cin >> mi >> ma;
			int resq = 0;
			for (int i = 0; i < H; ++i) {
				int lo = 0, hi = W-1;
				while(hi > lo) {
					int mid = (hi+lo)/2;
					if (nums[i][mid] < mi)
					{
						lo = mid+1;
					} else {
						hi = mid;
					}
				}
				int a = hi;
				if (nums[i][a] < mi){
					continue;
				}
				lo = 0;
				hi = min(H-i,W-hi) - 1;
				while(hi > lo) {
					int mid = (hi+lo+1)/2;
					if(nums[i+mid][a+mid] > ma){
						hi = mid-1;
					}else{
						lo = mid;
					}
				}
				if(nums[i+lo][a+lo] > ma){
					continue;
				}
				resq = max(resq, lo+1);
			}
			cout << resq << endl;
		}
		cout << "-\n";
	}	
	return 0;
}
