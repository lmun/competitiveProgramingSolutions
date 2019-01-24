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
	int a,b,c;
pair<int,int> visita(std::vector<std::vector<int> > &nums,std::vector<string> &v,int i,int j,int k){
	int d1=0,d2=0;
	//printf("%d\t%d\n", i,j);
	if(i<0||j<0||i>=a||j>=b){
		return mp(k,-1);
	}
	if(nums[i][j]>=0){
		return mp(nums[i][j],k-nums[i][j]);
	}
	nums[i][j]=k;
	if(v[i][j]=='W'){
		d1=-1;
		d2=0;
	}else if(v[i][j]=='E'){
		d1=1;
		d2=0;
	}else if(v[i][j]=='S'){
		d1=0;
		d2=1;
	}else if(v[i][j]=='N'){
		d1=0;
		d2=-1;
	}
	return visita(nums,v,i+d2,j+d1,k+1);
}
int main(){
	std::ios::sync_with_stdio(false);


	while(cin>>a>>b>>c){
		if(a==0&&b==0&&c==0){
			break;
		}
		std::vector<string> v(a);
		std::vector<std::vector<int> > nums(a,std::vector<int> (b,-1));
		for (int i = 0; i < a; ++i)
		{
			cin >> v[i];
		}
		pii r=visita(nums,v,0,c-1,0);
		if(r.s>0){
			printf("%d step(s) before a loop of %d step(s)\n",r.f,r.s);
		}else{
			printf("%d step(s) to exit\n",r.f );
		}
	}
	
	
	return 0;
}
