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
#define mod 1000000
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
	// cin.ignore(); must be there when using getline(cin, s)
	for (int i = 1; i <= 2000; ++i)
	{
		for (int j = i; j <= 2000 - i; ++j)
		{
			for (int k = j; k <= 2000 - i - j; ++k)
			{
				ll mul = i * j * k - mod;
				if(mul <= 0){
					continue;
				}
				ll l = (i + j + k) * mod / mul;
				if(l < k || i + j + k + l > 2000){
					continue;
				}
							
				if (i * j * k * l / mod == i + j + k + l) {
					printf("%.2f %.2f %.2f %.2f\n",i/100.0,j/100.0,k/100.0,l/100.0 );
				}

			}
		}
	}
	return 0;
}
