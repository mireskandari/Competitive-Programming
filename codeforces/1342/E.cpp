#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vc = vector<T>;

int constexpr MOD = 998244353;

int64_t binpow(int64_t a, int y) {
  int64_t res = 1;
  while (y) {
    if (y & 1) res = res * a % MOD;
    a = a * a % MOD;
    y >>= 1;
  }
  return res;
}

void norm(int64_t &a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;

  vc<int64_t> fact(n + 1), inv(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
  inv[n] = binpow(fact[n], MOD - 2);
  for (int i = n; i >= 1; --i) inv[i - 1] = inv[i] * i % MOD;

  auto C = [&](int K, int R) -> int64_t {
    if (R > K || K < 0 || R < 0) return 0;
    return fact[K] * inv[R] % MOD * inv[K - R] % MOD;
  };

  if (k > n) {
    cout << 0;
    exit(0);
  }
  if (k == 0) {
    cout << fact[n];
    exit(0);
  }
  
  int64_t ways = 0;
  for (int i = 0; i <= n - k; ++i) {
    if (i & 1) norm(ways -= C(n - k, i) * binpow(n - k - i, n) % MOD);
    else norm(ways += C(n - k, i) * binpow(n - k - i, n) % MOD);
  }
  
  cout << 2ll * ways % MOD * C(n, k) % MOD;
  return 0;
}
