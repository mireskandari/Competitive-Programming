#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 3e5 + 10;

char s[N];
int nxt[N][2];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < N; ++i) {
    fill_n(nxt[i], 2, n);
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i < n - 1) {
      memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
    }
    nxt[i][s[i] - 'A'] = i;
  }
  long ans = 0;
  for (int l = 0; l < n; ++l) {
    int j = s[l] - 'A';
    int nx = l == n - 1 ? n : nxt[l][!j];
    int sz = nx - l;
    //err("l = %d nx = %d\n", l, nx);
    if (sz == 1) {
      if (nx != n) {
        j = s[nx] - 'A';
        int nx2 = nxt[nx][!j];
        sz = nx2 - nx;
        ans += sz;
      }
    } else {
      if (nx != n) {
        ++ans;
      }
    }
    ++ans;
  }
  printf("%lld", (1ll * n * (n + 1) / 2) - ans); // retarded
  return 0;
}
