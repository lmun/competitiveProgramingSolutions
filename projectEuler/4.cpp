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
bool ispal(int nu){
	string s=to_string(nu);
	int fin=s.size()-1;
	int it=0;
	while(2*it < (int)s.size()){
		if(s[it]!=s[fin-it]){
			return false;
		}
		it++;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	std::vector<int> pals;
	for (int i = 100; i < 1000; ++i){
			for (int j = i; j < 1000; ++j){
				int mul=i*j;
				if(ispal(mul)){
					pals.push_back(mul);
				}
			}
		}
	sort(pals.begin(), pals.end());
	while(n--){
		ll num;
		cin >> num;
		int a=0,b=pals.size()-1;
		while(a<b){
			int mid=(a+b+1)/2;
			if(pals[mid]<num){
				a=mid;
			}else{
				b=mid-1;
			}
		}
		cout << pals[a] << endl;
	}
	/*
	for (int i = 0; i < (int)pals.size(); ++i)
	{
		cout << pals[i]<< ' ';
	}
	cout << endl;*/
	return 0;
}
