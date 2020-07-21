#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long;
using ld = long double;

template<class T = int>
using V = vector<T>;
template<class T = int>
using VV = V<V<T>>;
template<class I, class J>
using P = pair<I, J>;
template<class T = int>
using PP = P<T, T>;

//source : Benq
int constexpr MOD = 1e9 + 7;

struct Mint {
  typedef decay<decltype(MOD)>::type T;
  T v;

  explicit operator T() const { return v; }

  Mint() { v = 0; }

  Mint(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }

  friend bool operator==(const Mint &a, const Mint &b) {
    return a.v == b.v;
  }

  friend bool operator!=(const Mint &a, const Mint &b) {
    return !(a == b);
  }

  friend bool operator<(const Mint &a, const Mint &b) {
    return a.v < b.v;
  }

  friend string to_string(Mint a) { return to_string(a.v); }

  friend ostream &operator<<(ostream &os, Mint a) {
    return os << to_string(a);
  }

  Mint &operator+=(const Mint &m) {
    if ((v += m.v) >= MOD)
      v -= MOD;
    return *this;
  }

  Mint &operator-=(const Mint &m) {
    if ((v -= m.v) < 0)
      v += MOD;
    return *this;
  }

  Mint &operator*=(const Mint &m) {
    v = (long long) v * m.v % MOD;
    return *this;
  }

  Mint &operator/=(const Mint &m) {
    return (*this) *= inv(m);
  }

  friend Mint pow(Mint a, long long p) {
    Mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
    return ans;
  }

  friend Mint inv(const Mint &a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }

  Mint operator-() const { return Mint(-v); }

  Mint &operator++() { return *this += 1; }

  Mint &operator--() { return *this -= 1; }

  friend Mint
  operator+(Mint a, const Mint &b) { return a += b; }

  friend Mint
  operator-(Mint a, const Mint &b) { return a -= b; }

  friend Mint
  operator*(Mint a, const Mint &b) { return a *= b; }

  friend Mint
  operator/(Mint a, const Mint &b) { return a /= b; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << pow(Mint(3), 3 * n) - pow(Mint(7), n);
  return 0;
}
