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

using namespace std;
#define LSOne(S) ((S) & -(S))

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
    while(hi > lo){
        int mid = (lo+hi)/2;
        rsq(1,mid) < k? lo=mid+1:hi=mid;    
    }
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
    // cin.ignore(); must be there when using getline(cin, s)
    vector<char> letras(n);
    vi nums(n,0);
    vi vals;
    map<int, int> mapa;
    map<int, int> mapo;
    vals.push_back(-mod);
    vals.push_back(mod);
    for (int i = 0; i < n; i++){
        cin >> letras[i] >> nums[i];
        if (letras[i]=='I' or letras[i]=='D' or letras[i]=='C')
        {
            vals.push_back(nums[i]);
        }
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
    count +=10;
    vi seto(count, 0);
    FenwickTree fen=FenwickTree(count);
    int tam = 0;
    for (int i = 0; i < n; i++)
    {
        if (letras[i]=='I' and seto[mapa[nums[i]]]==0)
        {
            fen.update(mapa[nums[i]], 1);
            seto[mapa[nums[i]]] = 1;
            tam+=1;
        } else if (letras[i]=='D' and seto[mapa[nums[i]]]==1){
            fen.update(mapa[nums[i]], -1);
            seto[mapa[nums[i]]] = 0;
            tam-=1;
        } else if (letras[i]=='C') {
            cout << fen.rsq(mapa[nums[i]]-1) << endl;
        } else if(letras[i]=='K'){
            if (nums[i] > tam){
                cout << "invalid\n";
            } else {
                cout << mapo[fen.select(nums[i])] << endl;
            }
        }
    }
    return 0;
}
