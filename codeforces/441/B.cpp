//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

int main() {
  int n, v;
  scanf("%d%d", &n, &v);
  vector<int> a(3010);
  for (int i = 0; i < n; ++i) {
    int f, s;
    scanf("%d%d", &f, &s);
    a[f] += s;
  }
  int before = 0, ans = 0;
  for (int i = 0; i < 3010; ++i) {
    before = min(before, v);
    if (before < v) {
      int rm = min(a[i], v - before);
      a[i] -= rm;
      ans += before + rm;
      before = a[i];
    } else {
      ans += before;
      before = a[i];
    }
  }
  printf("%d", ans);
  return 0;
}
