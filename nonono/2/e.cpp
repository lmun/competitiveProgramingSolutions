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
void priti(int n){
	int x = 3;
	cout << endl;
	while(x--){
		int y = 3;
		while(y--){
			cout << (n & 1);
			n >>= 1;
		}
		cout<< endl;
	}
}

int sigi(int ant){
	int res = 0;
	res ^= (ant >> 3);
	res ^= (ant << 3);
	res ^= ((ant << 1) & (~(1<<3)) & (~(1<<6)));
	res ^= ((ant >> 1) & (~(1<<2)) & (~(1<<5)));
	res %= (1<<9);
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	// cin.ignore(); must be there when using getline(cin, s)
	// t =1;
	while (t--)
	{
		int e = 9;
		vi nums(0);
		int nunu = 0;
		while(e--){
			char xx;
			cin >> xx;
			nunu <<= 1;
			nunu += xx-'0';
		}
		bool falta = true;
		while(falta) {
			for (int i = 0; i < nums.size(); ++i)
			{
				if(nums[i] == nunu){
					cout << (i-1) << endl;
					falta = false;
					break;
				}
			}
			nums.push_back(nunu);
		//	priti(nunu);
			nunu=sigi(nunu);
		}
		//cout << endl ;
	}
	return 0;
}
