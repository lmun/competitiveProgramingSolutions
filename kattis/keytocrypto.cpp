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
int main()
{
	std::ios::sync_with_stdio(false);
	
	string msg,key;
	cin >> msg >> key;
	// cin.ignore(); must be there when using getline(cin, s)
	char ori[1500];
	int ks=key.size();
	strncpy(ori,key.c_str(),ks);
	for(int i=0;i< (int)msg.size();i++){
		ori[i+ks]=msg[i]-ori[i]+'A';
		if(ori[i+ks]<65){
			ori[i+ks]+=26;
		}
	}
	ori[msg.size()+ks]=0;

	cout << ori+ks << endl;
	
	return 0;
}
