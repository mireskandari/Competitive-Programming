#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

template<typename T>
struct Modular {
    long long val;
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

//struct VarMod { static int value; };
//int VarMod::value;
//int &MOD = VarMod::value;
//using Mint = Modular<VarMod>;

int constexpr MOD = 1e9 + 7;
using Mint = Modular<std::integral_constant<int, MOD>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), 'm') || count(s.begin(), s.end(), 'w')) {
        cout << 0;
        return 0;
    }
    int n = size(s);
    vector<Mint> dp(n + 1);
    dp[0] = 1;
    auto &&can_pass = [&](int i) {
        return (s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n');
    };
    for (int i = 1; i <= n; i++) {
        if (i - 1 > 0 && can_pass(i - 1)) dp[i] += dp[i - 2];
        dp[i] += dp[i - 1];
    }
    cout << dp[n];
    return 0;
}