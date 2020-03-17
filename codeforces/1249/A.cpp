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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;
        vector<int> in(n);
        forn (0, n, i) cin >> in[i];
        sort(all(in));
        vector<vector<int>> gp;
        vector<char> mark(n, 0);
        forn (0, n, i) {
            if (!mark[i]) {
                gp.resize(gp.size() + 1);
                gp.back().push_back(i);
                mark[i] = 1;
                forn (i + 1, n, j) {
                    if (!mark[j] && in[gp.back().back()] + 2 <= in[j]) {
                        gp.back().push_back(j);
                        mark[j] = 1;
                    }
                }
            }
        }
        // for (auto i : gp) {
        //     for (auto j : i) cout << j << ' ';
        //     cout << '\n';
        // }
        cout << gp.size() << '\n';

    }
    return 0;
}