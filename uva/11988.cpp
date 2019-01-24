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
char buf[1000000];
int main()
{
	std::ios::sync_with_stdio(false);
	string st;
	// cin.ignore(); must be there when using getline(cin, s)
	while (true)
	{
		deque<char *> deq;
		int ini = scanf("%s", buf);
		if(ini != 1 ){
			break;
		}
		int le = strlen(buf);
		deq.push_front(buf);
		for (int i = 0; i < le; ++i)
		{
			//cout << buf[i] << '.';
			if (buf[i] == '[')
			{
				deq.push_front((buf+1+i));
				buf[i] = 0;
			}else if(buf[i] == ']') {
				//cout << 13 << endl;
				deq.push_back((buf+1+i));
				buf[i] = 0;
			}
		}
		for(char* a :deq){
			cout << a;
		}
		cout << endl;
		//cout << buf << endl;
	}
	return 0;
}
