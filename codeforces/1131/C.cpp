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
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)

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
    rep (0, n, i) cin >> in[i];
    sort(all(in));
    deque<int> fin;
    fin.push_back(in.back());
    repr (n - 2, 0, i) {
        if (i % 2 == 1) fin.push_back(in[i]);
        else fin.push_front(in[i]);
    }
    rep (0, n, i) cout << fin[i] << ' ';
    return 0;
}