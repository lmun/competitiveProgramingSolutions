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
	char buffer[100];
	int t;
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &t);
	// cin.ignore(); must be there when using getline(cin, s)
	//cout << t << endl;
	int a, b, c;
	char d;
	//cin.ignore();
	fgets(buffer, sizeof(buffer), stdin);
	for(int j=0; j < t; j++){
		vi pena(1200, 0);
		vi solve(1200, 0);
		vi penatot(120, 0);
		vi corre(120, 0);
		vi part(120, 0);
		while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
			if(sscanf(buffer, "%d %d %d %c", &a, &b, &c, &d) != 4){
				// cout << "nonono\n";
				break;
			}
			part[a]++;
			if (d=='I' && solve[a*10 + b]==0)
			{
				pena[a*10 + b] += 1;
			} else if (d == 'C' && solve[a*10 + b]==0) {
				penatot[a] += (pena[a*10 + b]*20 + c);
				solve[a*10 + b] += 1;
				corre[a] += 1;
			}
			// cout << a << ' ' << b<< ' ' << c<< ' ' << d << endl;
		}
		std::vector<pii> resp(0);
		for (int i = 0; i < 120; ++i) {
			if(part[i] > 0){
				resp.push_back(mp(corre[i]*-100000000 + penatot[i], i));
			}
		}
		stable_sort(resp.begin(), resp.end());
		//cout << "fin de la linea\n";
		if(j && resp.size()) {
			cout << endl;
		}
		for (auto xx : resp) {
			cout << xx.s  << ' '<< corre[xx.s] << ' ' << penatot[xx.s] << endl;
		}
	}
	return 0;
}
