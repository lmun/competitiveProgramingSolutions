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

void fun(string pala, string obj, stack<char> sta, int np, int no, string res) {
	if (no == obj.size()){
		cout << res << endl;
	}
	if(np < pala.size()) {
		sta.push(pala[np]);
		fun(pala, obj, sta, np + 1, no, res + " i");
		sta.pop();
	}
	if (!sta.empty() && sta.top() == obj[no]){
		sta.pop();
		fun(pala, obj, sta, np, no + 1, res + " o");
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	string pala, obj;
	// cin.ignore(); must be there when using getline(cin, s)
	while (cin >> pala >> obj)
	{
		//cout << pala << obj << endl;
		cout << "[\n";
		if (pala.size() == obj.size()) {
			stack <char> sta;
			string res = "i";
			sta.push(pala[0]);
			fun(pala, obj, sta, 1, 0, res);
		}
		cout << "]\n";
	}
	return 0;
}
