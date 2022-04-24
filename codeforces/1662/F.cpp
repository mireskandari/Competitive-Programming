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
const int N=2e5+4;
struct sg{
	int seg[4*N];
	int a[N];
	int big(int i,int j){
		if(a[i]>a[j]) return i;
		return j;
	}
	void build(int id,int l,int r){
		if(l+1==r){
			seg[id]=l;
			return;
		}
		int mid=(r+l)/2;
		build(2*id,l,mid);
		build(2*id+1,mid,r);
		seg[id]=big(seg[2*id],seg[2*id+1]);
	}
	int get(int id,int l,int r,int st,int en){
		if(st>=r||en<=l) return 0;
		if(st<=l&&en>=r) return seg[id];
		int mid=(r+l)/2;
		return big(get(2*id,l,mid,st,en),get(2*id+1,mid,r,st,en));
	}
	void upd(int id,int l,int r,int ind,int x){
		if(ind>=r||ind<l) return;
		if(l+1==r){
			a[l]=x;
			return;
		}
		int mid=(r+l)/2;
		upd(2*id,l,mid,ind,x);
		upd(2*id+1,mid,r,ind,x);
		seg[id]=big(seg[2*id],seg[2*id+1]);
	}
};
sg seg1,seg2;
int dist[N],p[N];
int n;
deque<int> dq;

	void rm(int v){
		seg1.upd(1,1,n+1,v,0);
		seg2.upd(1,1,n+1,v,0);
	}

	int adj(int v){
		int mx2=seg2.get(1,1,n+1,v,min(n+1,v+p[v]+1));
		int mx1=seg1.get(1,1,n+1,max(1LL*1,v-p[v]),v+1);
		if(seg2.a[mx2]>=(n+1-v)) return mx2;
		if(seg1.a[mx1]>=(v)) return mx1;
		return -1;
	}

	void Main(){
		dq.clear();
		cin>>n;
		int a,b; cin>>a>>b;
		dq.pb(a);
		FOR(i,1,n) cin>>p[i];
		FOR(i,1,n) seg1.a[i]=p[i]+i;
		FOR(i,1,n) seg2.a[i]=p[i]+(n+1-i);
		seg1.build(1,1,n+1);
		seg2.build(1,1,n+1);
		FOR(i,1,n) dist[i]=1e8;
		dist[a]=0;
		rm(a);
		while(!dq.empty()){
			int v=dq.front();
			dq.pop_front();
			int u=-1;
			while(1){
				u=adj(v);
				if(u==-1) break;
				dq.pb(u);
				rm(u);
				dist[u]=dist[v]+1;
			}
		}
		cout<<dist[b]<<'\n';
	}

	int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--) Main();

	return 0;
	}
