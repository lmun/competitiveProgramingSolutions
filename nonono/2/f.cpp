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
char pala[1000];
int coun[1000];
int main()
{
	std::ios::sync_with_stdio(false);
	string wo;
	// cin.ignore(); must be there when using getline(cin, s)
	while (true) {
		int koko = scanf("%999s", pala);
		int le = strlen(pala);
		if(pala[0] == '#') {
			break;
		}
		int ult = 0;
		char mini = pala[le-1];
		int minipo = le - 1;
		char ultle = pala[le-1];
		bool posi = true;
		for (int i = le-1; i > 0; i--) {
			if(pala[i] > pala[i-1]) {
				ult = i-1;
				ultle = pala[i-1];
				posi = false;
				break;
			}
		}
		mini = pala[ult+1];
		minipo = ult+1;
		for (int i = ult+1; i < le; ++i){
			if (pala[i] > ultle) {
				if (pala[i] < mini)	{
					mini = pala[i];
					minipo = i;
				}
			}
		}

		if(!posi){
			pala[ult] = 0;
			pala[minipo] = ultle;
			//cout<< pala + ult+1 <<  endl;
			sort(pala + ult+1, pala+le);
			//cout << pala << ' ' << mini << ' ' << pala + ult+1 <<  endl;
			cout << pala << mini << pala + ult+1 <<  endl;
		}else{
			cout << "No Successor\n";
		}
	}
	return 0;
}
