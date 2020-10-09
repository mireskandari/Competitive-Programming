#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 2e5 + 10;

char s[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", s);
    int n = strlen(s);
    reverse(s, s + n);
    vector<int> ones;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') ones.push_back(i);
    }
    ones.push_back(n);
    int ans = 0;
    for (int l = 0; l < n; ++l) {
      int sum = 0;
      int r = l;
      for (; r - l < 21 && r < n; ++r) {
        if (s[r] == '1') sum += (1 << (r - l));
        if (sum == r - l + 1) {
          //err("sum = %d l = %d r = %d\n", sum, l, r);
          ++ans;
        }
      }
      --r;
      if (sum > r - l + 1 && l + sum <= n) {
        auto it = upper_bound(begin(ones), end(ones), r);
        if (*it >= l + sum) ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
