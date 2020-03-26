#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef string str;
void debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) { cerr << H << ' '; debug(T...); }
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n, k;
        cin >> n >> k;
        string s(n, 'a');
        ld a = 1.0/2.0, b = -1.0/2.0, c = -k;
        ld n1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        ld n2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        ld xx = (n1 > 0 ? n1 : n2);
        int dx = (ceil(xx) * (ceil(xx) - 1) / 2) - k;
        int x = ceil(xx) - 1;
//        debug(x, dx);
        s[x - dx - 1] = 'b';
        s[x] = 'b';
        reverse(all(s));
        cout << s << '\n';
    }
    return 0;
}