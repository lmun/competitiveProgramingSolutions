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

struct SegmentTree{
    vector<int>ST;
    vector<int> A;
    int n;
    void init(int i, int l, int r, vector<int>&a){
        if (l == r){
            ST[i]=l;
            return;
        }
        init(i*2, l, (l+r)/2, a);
        init(i*2+1, (l+r)/2+1, r, a);
        // ST[i]=min(ST[2*i], ST[2*i+1]);
        ST[i] = A[ST[2*i]] > A[ST[2*i+1]]? ST[2*i]:ST[2*i+1];
    }
    SegmentTree(vector<int>&a){
        n=a.size();
        A = a;
        ST.resize(4*n+5, INT_MAX);
        init(1, 0, n-1, a);
    }
    void update(int i, int l, int r, int pos, int val){
        if (r<pos or l>pos)
            return;
        if (l==pos and r==l){
            A[l] = val;
            ST[i]=l;
            return;
        }
        update(2*i, l, (l+r)/2, pos, val);
        update(2*i+1, (l+r)/2+1, r, pos, val);
        ST[i]=A[ST[2*i]] > A[ST[2*i+1]]? ST[2*i]:ST[2*i+1];
    }
    int query(int i, int l, int r, int a, int b){
        if (r<a or l>b)
            return -1;
        if (l>=a and r<=b)
            return ST[i];
        int qa = query(2*i, l, (l+r)/2, a, b);
        int qb = query(2*i+1, (l+r)/2+1, r, a, b);
        if(qa==-1){
            return qb;
        } if(qb==-1){
            return qa;
        }
        return A[qa]>A[qb]?qa:qb;
    }


    int query(int a, int b){
        if(b<a){
            return -1;
        }
        return query(1, 0, n-1, a, b);
    }
    void update(int pos, int val){
        update(1, 0, n-1, pos, val);
    }
};

/*
    vector<int>v(10, 0);    //Crea un vector v de tamano 10 lleno de 0's
    SegmentTree S(v); //Crea un SegmentTree llamado S con vector inicial v
    S.update(pos, val); //Cambia la posicion pos del arreglo al valor val
    S.query(a, b); //Pregunta del rango [a, b].
*/
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    // cin.ignore(); must be there when using getline(cin, s)
    vi nums(n, 0);
    for(int i = 0; i< n;i++){
        cin >> nums[i];
    }
    SegmentTree seg = SegmentTree(nums);
    int q;
    cin >> q;
    while(q--){
        char ch;
        int a,b;
        cin >> ch >> a >> b;
        if(ch == 'U'){
            a--;
            seg.update(a,b);
            nums[a] = b;
        } else {
            a--,b--;
            int res = seg.query(a,b);
            if(a==res){
                cout << nums[res] + nums[seg.query(res+1,b)] << endl;
            } else if (b==res){
                cout << nums[res] + nums[seg.query(a,res-1)] << endl;
            }else{
                cout << nums[res] + max(nums[seg.query(res+1,b)],nums[seg.query(a,res-1)]) << endl;
            }
        }
    }
    // for(auto nu:nums){
    //     cout << nu << ';';
    // }
    // cout << endl;
    return 0;
}