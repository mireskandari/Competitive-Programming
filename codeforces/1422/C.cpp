#include <bits/stdc++.h>
using namespace std;
#define long long long int
#define err(a...) fprintf(stderr, a)

constexpr int M = 1000 * 1000 * 1000 + 7;

int power(int n, int x) {
  int res = 1;
  for ( ; x; x >>= 1, n = 1ll * n * n % M)
    if (x & 1) res = 1ll * res * n % M;
  return res;
}

constexpr int N = 1e5 + 10;

char s[N];
int f[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  reverse(s, s + n);

  for (int i = 0; i < n; ++i) {
    if (i > 0) f[i] = f[i - 1];
    (f[i] += 1ll * power(10, i) * (i + 1) % M) %= M;
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = (int) (s[i] - '0');
    if (i > 0) (ans += 1ll * f[i - 1] * c % M) %= M;
    if (i < n - 1) (ans += 1ll * (1ll * c * power(10, i) % M) * (1ll * (n - i - 1) * (n - i) / 2 % M) % M) %= M;
  }

  printf("%d", ans);
  return 0;
}
