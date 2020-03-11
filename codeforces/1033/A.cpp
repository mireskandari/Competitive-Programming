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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    pair<int, int> a, b, c;
    cin >> n >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;
    if ((a.X > b.X && a.X > c.X && a.Y > b.Y && a.Y > c.Y) ||
        (a.X < b.X && a.X < c.X && a.Y > b.Y && a.Y > c.Y) ||
        (a.X > b.X && a.X > c.X && a.Y < b.Y && a.Y < c.Y) ||
        (a.X < b.X && a.X < c.X && a.Y < b.Y && a.Y < c.Y)) {

        cout << "YES";
    } 
    else {
        cout << "NO";
    }

    return 0;
}