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
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(...) cerr<<"[ "<<#__VA_ARGS__<<" ]: "<<debug_out(__VA_ARGS__)
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl

int constexpr N = 1e5;
int constexpr MOD = 998244353;
int constexpr INF = 1e9;

template <int MOD>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using Mint = Modular<MOD>;
vector<Mint> fact(1);
void ffact(long long n) { fact[0]=1; for(int i=1; i<=n; i++) fact.emplace_back(fact[i-1]*i); }
Mint nCrmod(long long n, long long r) { ffact(n); return fact[n]*inverse(fact[r])*inverse(fact[n-r]); }
// real nCr;
vector<vector<Mint>> nCr;
void fnCr(long long n) {
    nCr.assign(n+1, vector<Mint>(n+1, 1));
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
        nCr[i][j]=i>=j?(i-1>=0&&j-1>=0?nCr[i-1][j-1]:0)+(i-1>=0&&i>=j&&i-1>=j?nCr[i-1][j]:0):0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) return cout << 10, 0;
    if (n == 2) return cout << 180 << ' ' << 10, 0;
    rep (1, n, i) {
        Mint sum;
//        cerr << 1 ;
        sum = (n - 2 - i + 1) * 9 * 9 * mexp(Mint(10), n - i - 1);
//        cerr << 1;
        sum += 2 * 9 * mexp(Mint(10), n - i);
        cout << sum << ' ';
    }
    cout << 10;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX