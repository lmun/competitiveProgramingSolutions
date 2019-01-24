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
	cin>>t;
	// cin.ignore(); must be there when using getline(cin, s)
	int a, b, c, d, pro;

	while(t--){
		vll visi(10000,-1);

		cin >> a >> b >> c >> d;
		int ini = 1000*a + 100*b + 10*c + d;
		cin >> a >> b >> c >> d;
		int tar = 1000*a + 100*b + 10*c + d;
		cin >> pro;
		while(pro--){
			cin >> a >> b >> c >> d;
			int pron = 1000*a + 100*b + 10*c + d;
			visi[pron] = inf;
		}
		queue<pii> q;
		int res = -1;
		q.push(mp(ini,0));
		while(!q.empty()) {
			pii u = q.front();
			q.pop();
			if(u.f == tar){
				res = u.s;
				break;
			}
			d = u.f%10;
			c = (u.f/10)%10;
			b = (u.f/100)%10;
			a = (u.f/1000)%10;
			for (int i = 0; i < 8; ++i){
				int d1 = d, c1 = c, b1 = b, a1 = a;
				int x = i/2;
				if(x==0){
					d1+=(i%2?1:9);
					d1%=10;
				}else if (x==1){
					c1+=(i%2?1:9);
					c1%=10;
				}else if (x==2){
					b1+=(i%2?1:9);
					b1%=10;
				}else if (x==3){
					a1+=(i%2?1:9);
					a1%=10;
				}
				int num = 1000*a1 + 100*b1 + 10*c1 + d1;
				if(visi[num] < 0){
					visi[num] = u.s+1;
					q.push(mp(num,u.s+1));
				}
			}

		}
		cout << res << endl;
	}
	return 0;
}
