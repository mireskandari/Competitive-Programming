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

char s[200003];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        cin >> s;
        int n = strlen(s);
        vector<int> ps;
        ps.push_back(-1);
        forn (0, n, i) {
            if (s[i] == 'R') {
                ps.push_back(i);
            }
        }
        ps.push_back(n);
        int mx = 0;
        forn (1, ps.size(), i) {
            mx = max(mx, ps[i] - ps[i - 1]);
        }
        cout << mx << '\n';
    }
    return 0;
}