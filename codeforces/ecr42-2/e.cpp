#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#define endl "\n"
#define s second

using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<char> vc(n);
	std::vector<int> vi(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vi[i] >> vc[i];
	}
	long long sumb = 0;
	long long sumr = 0;
	int lastr = 10000000;
	int lastb = 10000000;
	long long total=0;
	for (int i = 0; i < n; ++i)
	{
		if(vc[i]=='R'){
			if(lastr==10000000){
				lastr=i;
			}else{
				sumr+=vi[i]-vi[lastr];
				total+=vi[i]-vi[lastr];
				lastr=i;
			}
		}else if(vc[i]=='B'){
			if(lastb==10000000){
				lastb=i;
			}else{
				sumb+=vi[i]-vi[lastb];
				total+=vi[i]-vi[lastb];
				lastb=i;
			}
			
		}else if(vc[i]=='P'){
			if(lastr==10000000){
				lastr=i;
			}
			if(lastb==10000000){
				lastb=i;
			}if(lastr==lastb&&lastr<i){
				sumr+=vi[i]-vi[lastr];
				sumb+=vi[i]-vi[lastb];
				total+=vi[i]-vi[lastr];
				//printf("sr %d\t%d\n", lastr,i);
				lastb=i;
				lastr=i;
			}else{
			 if(lastb<i){
				sumb+=vi[i]-vi[lastb];
				total+=vi[i]-vi[lastb];
				lastb=i;
			} if(lastr<i){
				sumr+=vi[i]-vi[lastr];
				total+=vi[i]-vi[lastr];
				lastr=i;
			}
		}
		}
	}
	cout << total << endl;
	
	return 0;
}
