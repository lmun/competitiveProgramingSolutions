#include <bits/stdc++.h>
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
	string s;

	// cin.ignore(); must be there when using getline(cin, s)
	//for(int k=1;k<1000;k++)
	for (;;)
	{
		cin >> s;
		//s=to_string(k);

		if (s[0] == '0') {
			break;
		}
		std::vector<long long> v(s.size(), 0);
		v[0] = 1;
		if (s.size() > 1) {
			v[1] = ((s[0] == '2' && s[1] < '7' && s[1] != '0') || (s[0] == '1' && s[1] != '0')) ? 2 : 1;

		}
		for (unsigned int i = 2; i < s.size(); ++i)
		{
			if ((s[i - 1] == '2' && s[i] < '7') || (s[i - 1] == '1')) {
				v[i] = v[i - 1] + v[i - 2];
			} else {
				v[i] = v[i - 1];
			}
			if (s[i] == '0') {
				v[i] = v[i - 2];
			}
		}
		cout << v[s.size() - 1]  << endl;
		//printf("%d\t%lld\n", k,v[s.size()-1]);
	}
	return 0;
}