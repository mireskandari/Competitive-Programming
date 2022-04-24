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
	vector<int> ans;
	ans.push_back(1), ans.push_back(2);
	int gc = __gcd(n - 1, m - 1);
	for(int i = 1; i * i <= gc; i++) {
		if(gc % i == 0) {
			ans.push_back(i);
			ans.push_back(gc / i);
		}
	}
	gc = __gcd(n, m - 2);
	for(int i = 1; i * i <= gc; i++) {
		if(gc % i == 0) {
			ans.push_back(i);
			ans.push_back(gc / i);
		}
	}
	gc = __gcd(n - 2, m);
	for(int i = 1; i * i <= gc; i++) {
		if(gc % i == 0) {
			ans.push_back(i);
			ans.push_back(gc / i);
		}
	}
	sort(All(ans));
	ans.erase(unique(All(ans)), ans.end());
	cout<<Sz(ans) <<' ';
	for(auto i : ans) cout<<i <<" ";
	cout<<'\n';
}

int main() {
    ios :: sync_with_stdio(0), cin.tie(0);

	int t; cin >>t;
	while(t--) solve();


    return 0;
}


