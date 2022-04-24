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

#define Sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
#define wtf(x) cout<<#x <<" : " <<x <<endl

constexpr ll inf = 1e18, N = 1e6 + 10, mod = 1e9 + 7, pr = 1000696969;

void solve() {
	int n, m; cin >>n >>m;
	int mx = 0, mx2 = 0;
	for(int i = 0; i < m; i++) {
		int l, r; cin >>l >>r;
		mx = max(mx, l);
		mx2 = max(mx2, r);
	}
	if(mx + mx2 > n) {
		cout<<"IMPOSSIBLE\n";
		return;
	}
	for(int i = 0; i < max(mx, n - mx2); i++) cout<<'R';
	for(int i = 0; i < mx2; i++) cout<<'W';
	cout<<'\n';
}

int main() {
    ios :: sync_with_stdio(0), cin.tie(0);

	int t; cin >>t;
	while(t--) solve();

    return 0;
}


