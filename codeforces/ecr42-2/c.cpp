#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int contai(string &n,string &ab){
	unsigned pos=0;
	for (unsigned i = 0; i < n.size(); ++i)
	{
		if(pos>=ab.size()){
			break;
		}
		if(ab[pos]==n[i]){
			pos++;
		}
	}
	if(pos==ab.size()){
		return n.size()-ab.size();
	}
	return 100;
}

int main()
{
	std::ios::sync_with_stdio(false);
	string n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	int num=stoi(n);
	int res=100;
	for (long long i = 1; i < 100000; ++i)
	{
		long long x=i*i;
		if(x>num){
			break;
		}
		string xs=to_string(x);
		int pos=contai(n,xs);
		res=min(res,pos);
	}
	if(res==100){
		res=-1;
	}
	cout << res << endl;
	return 0;
}
