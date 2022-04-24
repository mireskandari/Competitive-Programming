// Code by Parsa Eslami
 
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define bit(i,j) ((j>>i)&1)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define S second
#define F first
#define pb push_back
#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define err(x) cout<<#x<<": "<<x<<'\n';

using namespace std;

	void Main(){
		int cnt=0;
		string a,b; cin>>a>>b;
		vector<int> vc1,vc2;
		for(char x0:a) if(x0=='B') cnt++;
		else{
			int num=x0-'A';
			if(vc1.empty()||vc1.back()!=num) vc1.pb(num);
			else vc1.pop_back();
		}
		for(char x0:b) if(x0=='B') cnt--;
		else{
			int num=x0-'A';
			if(vc2.empty()||vc2.back()!=num) vc2.pb(num);
			else vc2.pop_back();
		}
		bool ans=1;
		if(cnt%2!=0){
			ans=0;
		}
		if(SZ(vc1)!=SZ(vc2)) ans=0;
		else{
			FOR(i,0,SZ(vc1)-1) if(vc1[i]!=vc2[i]) ans=0;
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}

	int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--) Main();

	return 0;
	}
