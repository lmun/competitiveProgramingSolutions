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
	int n;
	vi nums;
	int le = 0;
	while (cin >> n) {
		nums.push_back(n);
		le++;
	}
	vi maa(le, 0);
	vi lis;
	for (int i = 0; i < le; ++i) {
		auto low = lower_bound(lis.begin(), lis.end(), nums[i]);
		if (low == lis.end()) {
			lis.push_back(nums[i]);
			maa[i] = lis.size();
		} else {
			*low = nums[i];
			maa[i] = (low - lis.begin()) + 1;
		}
	}
	int laaa = lis.size();
	cout << laaa << "\n-\n";
	vi resp(laaa, 0);
	for (int i = le - 1; i >= 0; --i) {
		if (maa[i] == laaa) {
			resp[--laaa] = nums[i];
		}
	}
	for (int aaa : resp) {
		cout << aaa << endl;
	}
	return 0;
}
