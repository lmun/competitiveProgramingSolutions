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

int calc(int i,std::vector<int> &v){
	if(v[i]==-1||v[i]==i){
		return i;
	}else{
		int a=calc(v[i],v);
		v[i]=a;
		return a;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	while(n--){
		int w;
		cin >> w;
		std::vector<int> vecoi(30,0);
		std::vector<int> vecof(30,0);
		std::vector<int> vcon(30,-1);
		string st;
		while(w--){
			cin >> st;
			//cout << st << endl;
			int ult=st[st.size()-1]-'a';
			int pri=st[0]-'a';
			//cout << pri << ' ' << ult<< endl;
			vecoi[pri]++;
			vecof[ult]++;
			int mi=(int)min(ult,pri);
			int ma=(int)max(ult,pri);
			vcon[mi]=max(ma,vcon[mi]);
			//vcon[ma]=ma;
			//cout << ma << endl;

		}
		bool seabre=true;
		int mu=-1;
		for(int i=0;i<30;i++){
			if(vcon[i]>=0){
				int res=calc(i,vcon);
				//cout << res << endl;
				if(mu<0){
					mu=res;
				}else{
					if(mu!=res){
						seabre=false;
						cout << (char)('a'+mu)<<' '<<(char)('a'+res) << endl;
						break;
					}
				}
			}

		}
		int dist=0;
		for(int i=0;i<30;i++){
			int difi=vecoi[i]-vecof[i];
			if(difi!=0){
				dist++;
			}
			
			if(difi*difi>1){
				seabre=false;
			}

		}
		seabre=seabre&&dist<=2;
		cout << (!seabre?"The door cannot be opened.":"Ordering is possible.") << endl;
	}
	
	return 0;
}
