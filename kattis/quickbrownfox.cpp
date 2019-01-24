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
	int n;
	cin>>n;
	string s;
	cin.ignore();// must be there when using getline(cin, s)
	while(n--){
		getline(cin,s);
		std::vector<int> v(26,0);
		int dis=0;
		for (int i = 0; i < (int)s.size(); ++i)
		{
			if(s[i]>64&&s[i]<91){
				s[i]+=32;
			}
			if(s[i]>96&&s[i]<123){
				if(v[s[i]-'a']==0){
					v[s[i]-'a']=1;
					dis++;
				}
			}
		}
		if(dis==26){
			cout << "pangram\n";
		}else{
			cout << "missing ";
			for (int i = 0; i < 26; ++i)
			{
				if(!v[i]){
					cout << (char)(i+'a');
				}
			}
			cout << endl;
		}
	}
	return 0;
}
