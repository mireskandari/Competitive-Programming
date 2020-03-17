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

int in[150000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;
        
        forn (0, n, i) cin >> in[i];
        reverse(in, in + n);
        int cnt = 0, mn = in[0];
        forn (1, n, i) {
            if (mn < in[i]) cnt++;
            mn = min(mn, in[i]);
        }
        cout << cnt << '\n';
    }
    return 0;
}