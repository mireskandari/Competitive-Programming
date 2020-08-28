#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define vc vector

int constexpr MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vc<int64_t> fact(n + 1), pw2(n + 1);
  fact[0] = pw2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (1ll * fact[i - 1] * i) % MOD;
    pw2[i] = (1ll * pw2[i - 1] * 2) % MOD;
  }
  cout << (fact[n] - pw2[n - 1] + MOD) % MOD;
  return 0;
}
