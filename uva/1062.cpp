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
//char pala[10000];
int fun(string pala, string res, int i) {
	if (i == pala.size()) {
		return res.size();
	}
	char esta = pala[i];
	for (int j = 0; j < res.size(); ++j)
	{
		if(esta < res[j]){
			res[j] = esta;
			return fun(pala, res, i+1);
		} else if (esta == res[j]){
			return fun(pala, res, i+1);
		}
	}
	string apo = res + esta;
	return fun(pala, apo, i+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	string pala;
	// cin.ignore(); must be there when using getline(cin, s)
	int resnum = 1;
	while (cin >> pala) {
		if (pala == "end"){
			break;
		}
		string res(1, pala[0]);
		int tot = fun(pala, res, 1);
		// cout <<  pala << endl;
		cout << "Case "<< resnum++ << ": " << tot << endl;
	}
	return 0;
}
