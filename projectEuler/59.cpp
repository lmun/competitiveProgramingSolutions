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
	std::vector<char> v;
	int n;
	while(cin>>n){
		v.push_back((char)n);
	}
	/*
	for(char c:v){
		cout << (int)c << endl;
	}*/
	cout << "empieza\n";
	string key="god";
	//for (char j ='a'; j <= 'z'; ++j){
		//cout << j<<' ';
		bool puede=true;
		long long total=0;
		//cout << endl << j << endl;
		for (int i = 0; i < (int)v.size(); i++)
		{
			char este=(v[i]^key[i%3]);
			total+=(int)este;
			//char este=(v[i]^j);
			//cout <<este;
			//if(este!=32&&(este>'z'||este<'a')&&(este>'Z'||este<'A')){
			if(este<32){
				puede=false;
				cout << i << este << endl;
				break;
			}else{
				cout << este;
			}
			//cout << este;
		}
		if(puede){
			//cout << j << endl;
		}
		cout << endl << total << endl;
		//cout << (puede?"Si"+j:"No") <<endl;
	//}
	
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
