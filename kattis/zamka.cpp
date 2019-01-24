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
int pred(int a, int b){
	if(a==0){
		return b;
	}else{
		return pred(a/10,b+a%10);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int l,d,x;
	cin>>l>>d>>x;
	for (int i = l; i <=d; ++i)
	{
		if(pred(i,0)==x){
			cout << i << endl;
			break;
		}
	}
	for (int i = d;i >= l; i--)
	{
		if(pred(i,0)==x){
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
