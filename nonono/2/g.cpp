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
	vi nums(0);
	int n;
	// cin.ignore(); must be there when using getline(cin, s)
	int tot = 0;
	while (cin >> n){
		tot++;
		nums.push_back(n);
		sort(nums.begin(), nums.end());
		int wa = tot/2;
		if(tot % 2 == 0){
			cout << (nums[wa]+nums[wa-1])/2 << endl;
		} else {
			cout << nums[wa] << endl;
		}
	}
	return 0;
}
