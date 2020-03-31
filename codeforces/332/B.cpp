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
    int n, k;
    cin >> n >> k;
    vector<ll> in(n), s(n), maxsum(n - k + 1), sum(n - k + 1);
    rep (0, n, i) cin >> in[i];
    partial_sum(all(in), s.begin());
//    vector<vector<pair<ll, int>>> ss(k);
    rep (0, n - k + 1, i) {
        sum[i] = i == 0 ? s[i + k - 1] : s[i + k - 1] - s[i - 1];
    }
//    rep (0, n - k, i) cerr << sum[i] << ' ';
//    cerr << '\n';
    maxsum.back() = n - k;
//    cerr << maxsum.back() << ' ';
    repr (n - k - 1, 0, i) {
        maxsum[i] = sum[maxsum[i + 1]] <= sum[i] ? i : maxsum[i + 1];
    }
//    cerr << maxsum[0] <<'\n';
    ll bestx = -1, besty = -1, best = -INT_MAX;
    repr (n - k - 1, 0, i) {
//        cerr << maxsum[i + k] << '\n';
        if (i + k < n - k + 1 && sum[i] + sum[maxsum[i + k]] >= best) {
//            cerr << i << '\n';
            best = sum[i] + sum[maxsum[i + k]];
            bestx = i;
            besty = maxsum[i + k];
        }
    }
    cout << bestx + 1 << ' ' << besty + 1;
    return 0;
}