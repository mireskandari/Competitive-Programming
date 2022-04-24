// oooo
/*
 har chi delet mikhad bebar ~
 gitar o ba khodet nabar! ~
 ;Amoo_Hasan;
*/

#include<bits/stdc++.h>
//#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
//#pragma GCC target("avx2,fma")

using namespace std;

typedef long long ll;
typedef long double ld;

#define wtf(x) cout<<#x <<" : " <<x <<endl
#define pii pair<int,int>
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define S second
#define F first
#define pb push_back
#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()

constexpr ll inf = 1e18, N = 1e6 + 10, mod = 1e9 + 7, SQ = 100;

int n;
bitset<N> bt;
int p[N], sz[N];
vector<int> child[N], G[N];

void dfs(int x) {
	sz[x] = 1;
	for(auto i : child[x]) {
		dfs(i);
		sz[x] += sz[i];
	}
}

int get_centroid(int x) {
	for(auto i : child[x]) {
		if(sz[i] * 2 > n) return get_centroid(i);
	}
	return x;
}

void main_dfs(int x, int p = 0) {
	sz[x] = 1;
	for(auto i : G[x]) {
		if(i == p) continue;
		main_dfs(i, x);
		sz[x] += sz[i];
	}
}

void knapsack(vector<int> vc){
	bool b[n+1]={};
	b[0]=1;
	deque<pii> v2;
	sort(all(vc));
	v2.pb({vc.front(),1});
	FOR(i,1,SZ(vc)-1){
		if(vc[i]==vc[i-1]) v2.back().S++;
		else v2.pb({vc[i],1});
	}
	int ps[n+1]={};
	while(SZ(v2)&&v2.front().F<=SQ){
		int c=v2.front().S;
		int v=v2.front().F;
		FOR(i,0,v-1) ps[i]=b[i];
		FOR(i,v,n) ps[i]=b[i]+ps[i-v];
		FOR(i,0,n){
			int B;
			if(i>=v*c+v) B=ps[i-v*c-v];
			else B=0;
			b[i]=((ps[i]-B)>0);
		}
		v2.pop_front();
	}
	FOR(i,0,n) bt[i]=b[i];
	while(SZ(v2)){
		FOR(j,1,v2.front().S){
			bt=(bt<<v2.front().F)|bt;
		}
		v2.pop_front();
	}
}


int32_t main() {
    ios :: sync_with_stdio(0), cin.tie(0);

	cin >>n;
	for(int i = 2; i <= n; i++) {
		cin >>p[i];
		child[p[i]].push_back(i);
		G[p[i]].push_back(i), G[i].push_back(p[i]);
	}

	dfs(1);

	int root = get_centroid(1);

	main_dfs(root);


	vector<int> vc;

	for(auto i : G[root]) {
		vc.push_back(sz[i]);
	}

	knapsack(vc);


	int val = 0;
	for(int ind = bt._Find_first(); ind < SZ(bt); ind = bt._Find_next(ind)) {
		val = max(val, 1ll * ind * (n - 1 - ind));
	}
	
	int ans = val;


	for(int i = 1; i <= n; i++) ans += sz[i];

	cout<<ans;
	

    return 0;
}


