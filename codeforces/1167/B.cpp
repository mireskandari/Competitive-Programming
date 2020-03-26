#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ' '; debug_out(T...); }
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(...) cerr<<"[ "<<#__VA_ARGS__<<" ]: ";debug_out(__VA_ARGS__)
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<'\n'
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<'\n'
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<'\n'

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
//    ios::sync_with_stdio(false);cin.tie(0);

    const int p[] = {4, 8, 15, 16, 23, 42};
    int a[6] = {};
    map<pair<int, int>, int> mul;
    rep (0, 6, i) {
        rep (i + 1, 6, j) {
            mul[{p[i], p[j]}] = p[i] * p[j];
        }
    }
//    for (auto c : mul) cerr << c.X.X << ' ' << c.X.Y << ' ' << c.Y << endl;

    cout << "? 1 2" << endl;
    int s, ss;
    cin >> s;
    auto f = find_if(all(mul), [s](const auto& v) {return v.Y == s;});
//    cerr << f->X.X << ' ' << f->X.Y << ' ';
    cout << "? 1 3" << endl;
    cin >> ss;
    auto ff = find_if(all(mul), [ss](const auto& v) {return v.Y == ss;});
    map<int, int> cnt;
    for (auto fff : {*f, *ff}) {
        if (cnt[fff.X.X] != 0) a[0] = fff.X.X;
        if (cnt[fff.X.Y] != 0) a[0] = fff.X.Y;
//        cerr << fff.X.X << ' ' << fff.X.Y << ' ';
        cnt[fff.X.X]++;
        cnt[fff.X.Y]++;
    }
    a[1] = s / a[0];
    a[2] = ss / a[0];
    cout << "? 1 4" << endl;
    int sss;
    cin >> sss;
    a[3] = sss / a[0];
    cout << "? 4 5" << endl;
    int ssss;
    cin >> ssss;
    a[4] = ssss / a[3];
    cnt = {{4, 0}, {8, 0}, {15, 0}, {16, 0}, {23, 0}, {42, 0}};
    rep (0, 5, i) {
        cnt[a[i]]++;
    }
    for (auto c : cnt) {
        if (c.Y == 0) a[5] = c.X;
    }
    cout << "! ";
    rep (0, 6, i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX