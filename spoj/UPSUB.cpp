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
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
 
using namespace std;
 
void ppp(std::vector<std::vector<int> >* v,int ul,int ma, string s,char x,string* pala,std::vector<string>* resp){
	if(ma==0){
		//cout << s <<'\t'<< ma <<'\t'<<ul<<endl;
		
		(*resp).push_back(s);
		return;
	}
	if(ul<0){
		return;
	}
 
	for (int i = 0; i <= x-'A'; ++i)
	{
		if(((*v)[ul][i]>=ma)&&((*pala)[ul]==(char)(i+'A'))){
			ppp(v,ul-1,ma-1,(char)(i+'A')+s,(char)(i+'A'),pala,resp);
		}
	}
	ppp(v,ul-1,ma,s,x,pala,resp);
	
	
}
int main()
{
		
	int T;
	cin>>T;
		
	while(T--)
	{
		string palabra;
		cin >> palabra;
		std::vector<std::vector<int> > v(palabra.size(), std::vector<int> (60,0));
		v[0][palabra[0]-'A']++;
		for (unsigned int i = 1; i < palabra.size(); ++i)
		{
			v[i] = v[i-1];
			int c = 0;
			for(int x = palabra[i] - 'A'; x >= 0; --x){
				c = max(c, v[i][x]);
			}
			v[i][palabra[i] - 'A'] = c + 1;
		}
		int c=0;
		for(int x=59;x>=0;--x){
			c=max(c,v[palabra.size()-1][x]);
		}
		std::vector<string> resp(0,"");
		ppp(&v,palabra.size()-1,c,"",'z',&palabra,&resp);
			sort(resp.begin(), resp.end());
	for (unsigned int i = 0; i < resp.size(); ++i){
		cout << resp[i]<< endl;
	}
		if(T){
			cout << endl;
		}
	}
 
 
 
	return 0;
}
