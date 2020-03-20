#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

template<typename T> void nxt() {T a; cin >> a; return a;}

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> in(n);
    forn (0, n, i) cin >> in[i];

    ll best = 0;
    forn (0, n, i) best += (in[i] == 0 ? 0 : 1);
    vector<int> seg;
    forn (0, n, i) {
        forn (i, n, j) {
            ll ab = 0, rab = 0;
            forn (i, j + 1, u) {
                ab += (in[u] == 0 ? 0 : 1);
                rab += (in[u] == 0 ? 1 : 0);
            }
            seg.push_back(rab - ab);
            // cout << seg.back() << '\n';
        }
    }
    cout << best + *max_element(all(seg));
    return 0;
}