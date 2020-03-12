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
        double c;
        cin >> c;
        double n = 360.0 / (180.0 - c);
        cout << (n == floor(n) ? "YES\n" : "NO\n");
    }
    return 0;
}