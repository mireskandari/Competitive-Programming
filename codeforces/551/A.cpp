#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> in(n);
    vector<int> ans(n);
    forn (0, n, i) {
        cin >> in[i].FV;
        in[i].SV = i;
    }
    sort(all(in), greater<pair<int, int>>());
    int now = 1;
    ans[in[0].SV] = 1;
    forn (1, n, i) {
        ans[in[i].SV] = (in[i].FV != in[i - 1].FV ? (now = i + 1) : now);
    }
    forn (0, n, i) cout << ans[i] << ' ';
    return 0;
}