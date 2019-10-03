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
#define vpii vector<pii >
#define wgraph vector<vpii >
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define LSOne(S) ((S) & -(S))
/*
* Pashmak and Parmida's problem
*/

using namespace std;

class FenwickTree {                    // remember that index 0 is not used
private: vi ft; int n;        // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int _n) : n(_n) { ft.assign(n+1, 0); }    // n+1 zeroes
  FenwickTree(const vi& f) : n(f.size()-1) { ft.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {                                  // O(n)
      ft[i] += f[i];                                      // add this value
      if (i+LSOne(i) <= n)    // if index i has parent in the updating tree
        ft[i+LSOne(i)] += ft[i]; } }       // add this value to that parent
  int rsq(int j) {                                     // returns RSQ(1, j)
    int sum = 0; for (; j; j -= LSOne(j)) sum += ft[j];
    return sum; }
  int rsq(int i, int j) { return rsq(j) - rsq(i-1); }  // returns RSQ(i, j)
  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, int v) {
    for (; i <= n; i += LSOne(i)) ft[i] += v; }    // note: n = ft.size()-1
  int select(int k) { // O(log^2 n)
    int lo = 1, hi = n;
    for (int i = 0; i < 30; i++) { // 2^30 > 10^9 > usual Fenwick Tree size
      int mid = (lo+hi) / 2;                    // Binary Search the Answer
      (rsq(1, mid) < k) ? lo = mid : hi = mid; }
    return hi; }
};

class RUPQ : FenwickTree {    // RUPQ variant is a simple extension of PURQ
public:
  RUPQ(int n) : FenwickTree(n) {}
  int point_query(int i) { return rsq(i); }
  void range_update(int i, int j, int v) { update(i, v), update(j+1, -v); }
};
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vi nums(n,0);
	vi vals(n,0);
  vi jene(n,0);
	map<int, int> mapa;
  map<int, int> mapo;
  map<int, int> total;
  map<int, int> popo;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		vals[i] = nums[i];
	}
	sort(all(vals));
  int count = 1;
  for(auto aa:vals){
      if(mapa.count(aa)==0){
          count++;
          mapa[aa] = count;
          mapo[count] = aa;
      }
  }
  for (int i = n-1; i >=0; i--)
  {
    if(total.count(nums[i])==0){
      jene[i] = 1;
      total[nums[i]] = 1;
    }else{
      total[nums[i]]+=1;
      jene[i] = total[nums[i]];
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << jene[i] << ';';
  }
  
  cout << endl;
	FenwickTree fen = FenwickTree(n+10);
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    int tinu = mapa[nums[i]];
    if(popo.count(tinu)==0) {
      popo[tinu]=1;
      fen.update(1,1);
    } else {
      fen.update(popo[tinu], -1);
      popo[tinu]+=1;
      fen.update(popo[tinu],1);
    }
    cout << i << 'o' << fen.rsq(10) << 'k' << endl;
    // cout << mapa[nums[i]] << '.' << jene[i] << endl;
  }
  
  cout << 'a' << endl;
	return 0;
}
