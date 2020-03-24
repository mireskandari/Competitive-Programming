#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) { cerr << H << ' '; debug(T...); }
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

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

    int n, m;
    cin >> n >> m;
    if (n == 2) cout << 0;
    else cout << (n - 2) * nCrmod(m, n - 1) * mexp(Mint(2), n - 3);
    return 0;
}