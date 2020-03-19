#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int solve() {
    int n, m;
    cin >> n >> m;
    // cerr << 1 << '\n';
    vector<char> mark(101, 0);
    vector<pair<int, int>> in(n);
    // cerr << 1 << '\n';
    forn (0, n, i) {
        cin >> in[i].X;
        in[i].Y = i;
    }
    // cerr << 1 << '\n';
    // cout << 1 << '\n';
    forn (0, m, i) {
        int x;
        cin >> x;
        mark[x - 1] = 1;
        // cerr << 1 << ' ';
    }
    sort(all(in));
    // cerr << 1 << '\n';
    forn (0, n, i) {
        // cerr << l << ' ' << r << '\n';
        forn (min(in[i].Y, int(i)), max(in[i].Y, int(i)), j) {
            // cerr << j << ' ';
            if (!mark[j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        solve();
        
    }
    return 0;
}