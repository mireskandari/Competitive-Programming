#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Modular {
    int val;
    static int constexpr mod() { return T::value; };

    Modular(long long v = 0) {
        val = v % mod();
        if (val < 0) val += mod();
    }

    Modular(long long a, long long b) : val(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        val += b.val;
        if (val >= mod()) val -= mod();
        return *this;
    }

    Modular &operator-=(Modular const &b) {
        val -= b.val;
        if (val < 0) val += mod();
        return *this;
    }

    Modular &operator*=(Modular const &b) {
        val = (long long) val * b.val % mod();
        return *this;
    }

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return mexp(a, mod() - 2);
    }

    Modular &operator/=(Modular const &b) {
        return *this *= inverse(b);
    }

    friend Modular
    operator+(Modular a, Modular const b) { return a += b; }

    friend Modular
    operator-(Modular a, Modular const b) { return a -= b; }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular
    operator*(Modular a, Modular const b) { return a *= b; }

    friend Modular
    operator/(Modular a, Modular const b) { return a /= b; }

    friend Modular operator%(Modular a, Modular const b) {
        return a.val %= b.val;
    }

    friend std::ostream &
    operator<<(std::ostream &os, Modular const &a) {
        return os << a.val;
    }

#define IMPLEMENT_COMPARE_OPERATOR(x) \
    friend bool operator x (Modular const& a, Modular const& b) { \
            return a.val x b.val; \
    }

    IMPLEMENT_COMPARE_OPERATOR(<)

    IMPLEMENT_COMPARE_OPERATOR(>)

    IMPLEMENT_COMPARE_OPERATOR(<=)

    IMPLEMENT_COMPARE_OPERATOR(>=)

    IMPLEMENT_COMPARE_OPERATOR(==)

    IMPLEMENT_COMPARE_OPERATOR(!=)
};

struct VarMod { static int value; };
int VarMod::value;
int& MOD = VarMod::value;
using Mint = Modular<VarMod>;

//int constexpr MOD = 1e9 + 7;
//using Mint = Modular<std::integral_constant<int, MOD>>;

int dp[1010][1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    if (n >= m) {
        cout << "YES\n";
        return 0;
    }
    dp[0][0] = 1;
    MOD = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = dp[i - 1][j];
            Mint last = j;
            last -= Mint(a[i - 1]);
            dp[i][j] = max(dp[i - 1][last.val] ? dp[i - 1][last.val] + 1 : 0, dp[i][j]);
        }
    }
    cout << (dp[n][0] >= 2 ? "YES" : "NO");
    return 0;
}