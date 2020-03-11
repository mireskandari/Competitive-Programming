#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define forrn(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

ll cnt;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    forn (0, n, i) {
        string s;
        cin >> s;
        if (s == "Tetrahedron") cnt += 4;
        if (s == "Cube") cnt += 6;
        if (s == "Octahedron") cnt += 8;
        if (s == "Dodecahedron") cnt += 12;
        if (s == "Icosahedron") cnt += 20;
    }

    cout << cnt;
    
    return 0;
}