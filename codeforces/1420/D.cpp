#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int M = 998244353;

int mul(int a, int b) { return 1ll * a * b % M; }
void norm(int &a) { if (a >= M) a -= M; if (a < 0) a += M; }
int power(int n, int x) {
  int res = 1;
  for (; x; x >>= 1, n = mul(n, n)) if (x & 1) res = mul(res, n);
  return res;
}

constexpr int N = 3e5 + 10;

int fact[N], invfact[N];
void init_fact() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
  invfact[N - 1] = power(fact[N - 1], M - 2);
  for (int i = N - 1; i > 0; --i) invfact[i - 1] = mul(invfact[i], i);
}
int ncr(int n, int k) {
  if (k > n) return 0;
  return mul(fact[n], mul(invfact[n - k], invfact[k]));
}

int a[N][2];

int main() {
  int n, k; scanf("%d %d", &n, &k);
  init_fact();
  for (int i = 0; i < n; ++i) scanf("%d %d", &a[i][0], &a[i][1]);
  vector<pair<int, bool>> point; point.reserve(2 * n);
  for (int i = 0; i < n; ++i) point.emplace_back(a[i][0], 0), point.emplace_back(a[i][1], 1);
  sort(begin(point), end(point));
  int open = 0, ans = 0;
  for (auto &p : point) {
    if (!p.second) { norm(ans += ncr(open, k - 1)); ++open; }
    else { --open; }
  }
  printf("%d", ans);
  return 0;
}
