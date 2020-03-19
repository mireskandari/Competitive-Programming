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

        int n, m;
        cin >> n >> m;
        vector<vector<int>> par(n, vector<int>(26, 0));
        vector<int> fin(26, 0);
        string s;
        cin >> s;
        par[0][s[0] - 'a']++;
        forn (1, n, i) {
            par[i] = vector<int>(all(par[i - 1]));
            par[i][s[i] - 'a']++;
        }
        forn (0, m, i) {
            int x;
            cin >> x;
            forn (0, 26, j) {
                fin[j] += par[x - 1][j];
            }
        }
        forn (0, 26, i) cout << fin[i] + par[n - 1][i] << ' ';
        cout << '\n';
    }
    return 0;
}