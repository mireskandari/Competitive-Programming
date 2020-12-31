#include <bits/stdc++.h>
using namespace std;
#define long long long int
#define err(a...) fprintf(stderr, a)

constexpr int M = 1000 * 1000 * 1000 + 7;

int mul(int a, int b) { return 1ll * a * b % M; }
int power(int a, int x) { 
  int res = 1; 
  for ( ; x; x >>= 1, a = mul(a, a)) if (x & 1) res = mul(res, a); 
  return res; 
}
int sub(int a, int b) { a -= b; return a < 0 ? a + M : a; }
int add(int a, int b) { a += b; return a >= M ? a - M : a; }

constexpr int N = 5e5 + 10;

int h, w;
int fact[N], invfact[N];

void initfact() {
  int n = h + w + 10;
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
  invfact[n] = power(fact[n], M - 2);
  for (int i = n; i > 0; --i) invfact[i - 1] = mul(invfact[i], i);
}
int paths(int x, int y) {
  return mul(fact[x + y], mul(invfact[y], invfact[x]));
}

pair<int, int> a[N];
int dp[N];

int main() {
  int n;
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a, a + n);
  a[n] = {h, w};
  ++n;

  initfact();

  for (int i = 0; i < n; ++i) {
    dp[i] = paths(a[i].first - 1, a[i].second - 1);
    for (int j = 0; j < i; ++j) {
      if (a[i].first >= a[j].first && a[i].second >= a[j].second)
        dp[i] = sub(dp[i], mul(dp[j], paths(a[i].first - a[j].first, a[i].second - a[j].second)));
    }
  }
  
  printf("%d", dp[n - 1]);
  return 0;
}
