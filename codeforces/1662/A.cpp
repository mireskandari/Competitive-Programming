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
		int n; cin>>n;
		int mx[11]={};
		FOR(i,1,n){
			int b,d; cin>>b>>d;
			mx[d]=max(mx[d],b);
		}
		int ans=0;
		FOR(i,1,10) if(mx[i]==0){
			cout<<"MOREPROBLEMS\n";
			return;
		}else ans+=mx[i];
		cout<<ans<<'\n';
	}

	int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--) Main();

	return 0;
	}
