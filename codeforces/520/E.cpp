#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

constexpr int M = 1000 * 1000 * 1000 + 7;

int Add(int a, int b) {
  a += b;
  if (a >= M) a -= M;
  if (a < 0) a += M;
  return a;
}
int Power(int a, int x) {
  int res = 1;
  for (; x; x >>= 1, a = 1ll * a * a % M) {
    if (x & 1) res = 1ll * a * res % M;
  }
  return res;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  static char s[112345];
  scanf("%s", s);
  vector<int> fact(n + 1), invfact(n + 1);
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1ll * fact[i - 1] * i % M;
    invfact[i] = Power(fact[i], M - 2);
  }
  auto C = [&](int p, int q) -> int {
    if (q > p || p < 0 || q < 0) return 0;
    return 1ll * fact[p] * invfact[q] % M * 1ll * invfact[p - q] % M;
  };
  vector<int> coeff(n);
  for (int i = 0; i < n; ++i) {
    coeff[i] = Add(i > 0 ? coeff[i - 1] : 0, 1ll * Power(10, i) * C(n - i - 2, k - 1) % M);
//    ERR("coeff[%d] = %d\n", i, coeff[i]);
  }
  int ans = 1ll * (int) (s[n - 1] - '0') * C(n - 1, k) % M;
  for (int i = 0; i < n - 1; ++i) {
    ans = Add(ans, 1ll * coeff[n - i - 2] * (int) (s[i] - '0') % M);
    ans = Add(ans, 1ll * Power(10, n - i - 1) * C(i, k) % M * (int) (s[i] - '0') % M);
  }
  printf("%d", ans);
  return 0;
}