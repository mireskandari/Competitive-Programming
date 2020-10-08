#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 1e5 + 10;

int a[N], st[26][N], lg[N];

int range_gcd(int l, int r) {
  int lo = lg[r - l + 1];
  return __gcd(st[lo][l], st[lo][r - (1 << lo) + 1]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  lg[1] = 0;
  for (int i = 2; i < N; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 0; i < n; ++i) {
    st[0][i] = a[i];
  }
  for (int l = 1; l <= 25; ++l) {
    for (int i = 0; i + (1 << l) <= n; ++i) {
      st[l][i] = __gcd(st[l - 1][i], st[l - 1][i + (1 << (l - 1))]);
    }
  }
  map<int, long> ans;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ) {
      int cur_gcd = range_gcd(l, r);
      ans[cur_gcd] += 1;
      for (int k = 1; k < 26; ++k) {
        if (r + (1 << k) < n && range_gcd(l, r + (1 << k)) == cur_gcd) {
          ans[cur_gcd] += 1 << (k - 1);
        } else {
          r += 1 << (k - 1);
          break;
        }
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", ans[x]);
  }
  return 0;
}
