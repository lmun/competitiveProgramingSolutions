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
    int c;
    cin >> c;
    int aa = c;
    // cin.ignore(); must be there when using getline(cin, s)
    while (c--) {
        if (aa-1!=c)
        {
            cout << endl;
        }
        int n, t, m;
        cin >> n >> t >> m;
        int arivalTime;
        string arivalbank;
        deque<pii> arleft;
        deque<pii> arright;
        vi res(m, 0);
        for (int i = 0; i < m; ++i){
            cin >> arivalTime >> arivalbank;    
            if (arivalbank == "left") {
                arleft.push_front(mp(arivalTime, i));
            } else {
                arright.push_front(mp(arivalTime, i));
            }
        }
        int time = 0;
        bool left = true;
        int cap = 0;
        deque<int> ferry;
        while(m) {
            //cout << 'x' << endl;
            while(!ferry.empty()){
                res[ferry.front()] = time;
                ferry.pop_front();
                m--;
                //cout << 'a' << endl;
            }
            while(left && !arleft.empty() && arleft.back().f <= time && ferry.size() < n){
                ferry.push_front(arleft.back().s);
                arleft.pop_back();
                cap++;
                //cout << 'b' << endl;
            }
            while(!left && !arright.empty() && arright.back().f <= time && ferry.size() < n) {
                ferry.push_front(arright.back().s);
                arright.pop_back();
                cap++;
                //cout << 'c' << endl;
            }
            if (ferry.size() > 0 || (left && !arright.empty() && arright.back().f <= time) || (right && !arleft.empty() && arleft.back().f <= time))
            {
                left = !left;
                time +=t;
            } else{
                int nexttime = mod;
                if(!arright.empty()) {
                    nexttime = min(nexttime, arright.back().f);
                }
                if (!arleft.empty()) {
                    nexttime = min(nexttime, arleft.back().f);
                }
                time = nexttime;
            }
        }
        for(int ti: res){
            cout << ti <<endl;
        }
    }
    return 0;
}
