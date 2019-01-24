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
	int n,a,b;
	cin >> n >> a >> b;
	// cin.ignore(); must be there when using getline(cin, s)
	string s;
	cin >> s;
	int total=0;
	if(s[0]=='.'){
		if(a<b){
			s[0]='b';
			b--;
		}else{
			s[0]='a';
			a--;
		}
		total++;
	}

	for (int i = 1; i < n; ++i)
	{
		if(a<=0&&b<=0){
			break;
		}
		if(s[i]=='.'){
			if(s[i-1]=='a'&& b > 0){
				s[i]='b';
				b--;
				total++;
			}else if(s[i-1]=='b'&& a > 0){
				s[i]='a';
				total++;
				a--;
			}else if(s[i-1]!='a'&&s[i-1]!='b'){
				if(a>b){
					s[i]='a';
					total++;
					a--;
				}else{
					s[i]='b';
					b--;
					total++;
				}
			}
		}
	}
	cout << total << endl;
	return 0;
}
