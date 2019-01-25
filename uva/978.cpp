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
	int t;
	cin >> t;
	// cin.ignore(); must be there when using getline(cin, s)
	int bf, green, blue;
//	while (t--) {
	for(int kk = 0; kk < t; kk++) {
		if(kk){
			cout << endl;
		}
		cin >> bf >> green >> blue;
		vi greenArmy(green, 0);
		vi blueArmy(blue, 0);
		vi bf1(bf, 0);
		vi bf2(bf, 0);

		for (int i = 0; i < green; ++i) {
			cin >> greenArmy[i];
		}

		for (int i = 0; i < blue; ++i) {
			cin >> blueArmy[i];
		}

		make_heap(greenArmy.begin(), greenArmy.end());
		make_heap(blueArmy.begin(), blueArmy.end());
		while(greenArmy.size() > 0 && blueArmy.size() > 0){
			int ubf = 0;
			for (int i = 0; i < bf && greenArmy.size() > 0 && blueArmy.size() > 0; ++i) {
				bf1[i] = greenArmy.front();
				bf2[i] = blueArmy.front();
				pop_heap(greenArmy.begin(), greenArmy.end());
				pop_heap(blueArmy.begin(), blueArmy.end());
				greenArmy.pop_back();
				blueArmy.pop_back();
				//cout << bf1[i] << ' ' << bf2[i] << endl;
				ubf++;
			}
			while(ubf--) {
				int difi = bf1[ubf]-bf2[ubf];
				if (difi > 0){
					greenArmy.push_back(difi);
					push_heap(greenArmy.begin(), greenArmy.end());
				}
				if(difi < 0){
					blueArmy.push_back(0-difi);
					push_heap(blueArmy.begin(), blueArmy.end());
				}
			}
		}
		if (greenArmy.size() > 0)
		{
			sort(greenArmy.begin(), greenArmy.end(), std::greater<int>());
			cout << "green wins\n";
			for(int gre: greenArmy){
				cout << gre << endl;
			}
		}
		if (blueArmy.size() > 0)
		{
			sort(blueArmy.begin(), blueArmy.end(), std::greater<int>());
			cout << "blue wins\n";
			for(int gre: blueArmy){
				cout << gre << endl;
			}
		}
		if (!blueArmy.size() && !greenArmy.size())
		{
			cout << "green and blue died\n";
		}
	}
	return 0;
}
