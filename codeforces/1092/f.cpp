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
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
std::vector<int> cost;
class Key
{
  public: 
    Key(int s, int i)
    {
      this->s = s;
      this->i = i;
    }
    int s;
    int i;
    bool operator<(const Key& k) const
    {
      int s_cmp = this->s - k.s;
      if(s_cmp == 0){
        return this->i < k.i;
      }
      return s_cmp < 0;
    }
};
ll waa(int x, int y, map<Key, ll> &non, map<Key, ll> &nin, vvi &mat){
	// cout << x << ' ' << y << endl;
	Key xy = Key(x, y);
	map<Key, ll>::iterator aa = non.find(xy);
	if(aa != non.end()){
		return aa->s;
	}
	ll res = cost[y];
	ll acc = cost[y];
	for(int kk: mat[y]){
		if(kk == x){
			continue;
		}
		res += waa(y, kk, non, nin, mat);
		Key yk = Key(y, kk);
		res += nin[yk];
		acc += nin[yk];
	}
	non[xy] = res;
	nin[xy] = acc;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	// cin.ignore(); must be there when using getline(cin, s)
	cost.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
	}
	vvi mat(n, vi());
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		x--,y--;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	map<Key, ll> nono;
	map<Key, ll> nini;
	ll maxi = 0;
	for (int i = 0; i < n; ++i){
		if(mat[i].size() == 1)
		maxi = max(maxi, waa(-10, i, nono, nini, mat) - nini[Key(-10, i)]);
		//cout << nini[Key(-10, i)] << endl;
		//cout << nono[Key(-10, i)] << endl << endl;
	}
	//ll maxi = 0;
	//for (map<Key, ll>::iterator it=nono.begin(); it!=nono.end(); ++it){
    //	maxi = max(maxi, it->second);
	//}
	cout << maxi << endl;
	return 0;
}
