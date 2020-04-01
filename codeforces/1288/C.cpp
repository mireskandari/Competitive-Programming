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
#define acm_input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
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

template <int MOD>
struct Modular {
    int val;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { val = v % MOD; if (val < 0) val += MOD;}
    Modular(long long a, long long b) : val(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {val += b.val; if (val >= MOD) val -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {val -= b.val; if (val < 0) val += MOD;return *this;}
    Modular& operator*=(Modular const& b) {val = (long long)val * b.val % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular mexp(long long a, long long e) { return mexp(Modular(a), e); }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
    friend Modular inverse(long long a) { return mexp(Modular(a), MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.val;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.val == b.val;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.val != b.val;}
};
using Mint = Modular<MOD>;
vector<Mint> fact;
void ffact(long long n) { fact.assign(n+1,0); for(int i=1; i<=n; i++) fact[i]=fact[i-1]*i; }
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

    ll n, m;
    cin >> n >> m;

    fnCr(max(n, m));
    Mint cnt = 0;
    rep (1, n + 1, i) {
        ll d = i, t = n - i + 1;
        Mint l = 0, r = 0;
        rep (0, min(d, m), j) {
            l += nCr[d - 1][j] * nCr[m - 1][j];
        }
        rep (1, min(m, t) + 1, j) {
            r += nCr[t][j] * nCr[m - 1][j - 1];
        }
//        cerr << l << ' ' << r << '\n';
        cnt += l * r;
    }
    cout << cnt;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX