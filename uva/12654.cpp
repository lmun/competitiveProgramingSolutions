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
int t1, t2, n;

int minn(int i, int k, std::vector<int> &v, std::vector<int> &vn, std::vector< std::vector<int> > &kkk) {
	//printf("%d\t%d\n",i,k );
	if (k <= 0) {
		return 0;
	}
	if (kkk[i][k] < 1000000) {
		return kkk[i][k];
	}
	int total = 0;
	int j1 = i;
	int k1 = k;
	while (total <= t1 && k1 > 0) {
		total += vn[j1 % n];
		j1++;
		k1--;
	}
	int casot1 = t1 + minn(j1 % n, k1, v, vn, kkk);

	total = 0;
	int j2 = i;
	int k2 = k;
	while (total <= t2 && k2 > 0) {
		total += vn[j2 % n];
		j2++;
		k2--;
	}
	int casot2 = t2 + minn(j2 % n, k2, v, vn, kkk);
	kkk[i][k] = min(casot1, casot2);
	return kkk[i][k];

}

int main()
{

	int c, ta, tb;


	while (cin >> n >> c >> ta >> tb)
	{
		t1 = min(ta, tb);
		t2 = max(ta, tb);
		std::vector<int> v(n);
		std::vector<int> vn(n);
		std::vector<int> va(n + 1);

		std::vector<std::vector<int> > kkk(n + 1, std::vector<int> (n + 1, 2000000));
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		// va[0]=v[0]+c-v[n-1];
		// va[n]=v[0]+c-v[n-1];
		vn[n - 1] = v[0] + c - v[n - 1];
		for (int i = 0; i < n - 1; ++i)
		{
			//va[i]=v[i]-v[i-1];
			vn[i] = v[i + 1] - v[i];
			//cout << va[i]<< endl;
		}
		int res = minn(0, n, v, vn, kkk);
		for (int i = 1; i < n; ++i)
		{
			res = min(res, minn(i, n, v, vn, kkk));
		}
		cout << res << endl;
		//cout << va[0] << endl;
	}
	return 0;
}