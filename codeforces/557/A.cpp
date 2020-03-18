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

    int n;
    cin >> n;
    pair<int, int> f, s, t;
    cin >> f.X >> f.Y >> s.X >> s.Y >> t.X >> t.Y;

    int of, os;
    of = min(f.Y, n - s.X - t.X);
    n -= of;
    os = min(s.Y, n - t.X);
    n -= os;
    cout << of << ' ' << os << ' ' << n;
    return 0;
}