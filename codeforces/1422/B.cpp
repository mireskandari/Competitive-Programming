#include <bits/stdc++.h>
using namespace std;
#define long long long int
#define err(a...) fprintf(stderr, a)

constexpr int N = 110;

long best_value(vector<int> &a) {
  auto solve = [&](long x) {
    long k = 0;
    for (long v : a) k += abs(x - v);
    return k;
  };

  int low = 0, high = 1e9 + 10;
  while (high - low > 2) {
    int m1 = low + (high - low) / 3;
    int m2 = high - (high - low) / 3;
    if (solve(m1) < solve(m2))
      high = m2;
    else
      low = m1;
  }
  long best = -1;
  for ( ; low <= high; ++low)
    if (best == -1 || solve(best) > solve(low)) best = low;
  //err("%lld %lld ---", best, solve(best));
  //for (int v : a) err("%d ", v);
  //err("\n");
  return solve(best);
}

int a[N][N];
bool mark[N][N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    memset(mark, 0, sizeof(mark));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= m; ++j)
        scanf("%d", &a[i][j]);
    long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (mark[i][j]) continue;
        vector<int> val;
        auto add = [&](int i, int j) {
          if (!mark[i][j]) {
            mark[i][j] = true;
            val.push_back(a[i][j]);
          }
        };
        add(n - i + 1, j);
        add(i, m - j + 1);
        add(n - i + 1, m - j + 1);
        add(i, j);
        assert(!val.empty());
        ans += best_value(val);
      }
    printf("%lld\n", ans);
  }
  return 0;
}
