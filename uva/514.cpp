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
	int t;
	
	// cin.ignore(); must be there when using getline(cin, s)
	int wa = 0;
	while (cin >> t) {
		if(t == 0){
			break;
		}
		int n;
		
		while(cin >> n){
			if(n == 0){
				break;
			}
			vi nums(t+1, 0);
			vi visi(t+1, 0);
			nums[0] = n;
			for (int i = 1; i < t; ++i)
			{
				cin >> nums[i];
			}
			int maxi = n;
			visi[n] = 1;
			int mini = n-1;
			bool posi = true;
			for (int i = 1; i < t; ++i)
			{
				int este = nums[i];
				//cout << este<< endl;
				if(este > maxi) {
					visi[este] = 1;
					mini = este - 1;
					maxi = este;
				}else{
					while(visi[mini] && mini > 0){
						mini--;
					}
					//cout << este << ' ' << mini<< ' ' << i << endl;
					visi[este] = 1;
					if(este != mini){
						posi = false;
						//
					}
				}
			}
			cout << (posi?"Yes":"No") << endl;
		}
		cout << endl;
	}
	return 0;
}
