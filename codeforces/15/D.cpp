#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 1010;

deque<pair<int, int>> dq;
void push(pair<int, int> val) {
  while (!dq.empty() && dq.back().second >= val.second)
    dq.pop_back();
  dq.push_back(val);
}

int a[N][N], mn[N][N];
long sum[N][N];
bool mark[N][N];

int main() {
  int n, m, h, w; 
  scanf("%d %d %d %d", &n, &m, &h, &w);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i) {
    dq.clear();
    for (int j = 0; j < w; ++j) push({j, a[i][j]}), sum[i][0] += a[i][j];
    mn[i][0] = dq.front().second;
    for (int j = 1; j + w <= m; ++j) {
      sum[i][j] = sum[i][j - 1] + a[i][j + w - 1] - a[i][j - 1];
      if (dq.front().first == j - 1) dq.pop_front();
      push({j + w - 1, a[i][j + w - 1]});
      mn[i][j] = dq.front().second;
    }
  }
  vector<tuple<long, int, int>> cand; cand.reserve(n * m);
  for (int j = 0; j + w <= m; ++j) {
    dq.clear();
    long s = 0;
    for (int i = 0; i < h; ++i) push({i, mn[i][j]}), s += sum[i][j];
    cand.emplace_back(s - (1ll * dq.front().second * h * w), 0, j);
    for (int i = 1; i + h <= n; ++i) {
      s += sum[i + h - 1][j]; s -= sum[i - 1][j];
      if (dq.front().first == i - 1) dq.pop_front();
      push({i + h - 1, mn[i + h - 1][j]});
      cand.emplace_back(s - (1ll * dq.front().second * h * w), i, j);
    }
  }
  sort(begin(cand), end(cand));
  vector<tuple<long, int, int>> anss; anss.reserve(n * m);
  for (auto &c : cand) {
    auto [val, i, j] = c;
    if (mark[i][j]) continue;
    for (int ki = max(0, i - h + 1); i + h > ki && ki + h <= n; ++ki) 
      for (int kj = max(0, j - w + 1); j + w > kj && kj + w <= m; ++kj) mark[ki][kj] = true;
    anss.emplace_back(val, i, j);
  }
  printf("%d\n", (int) anss.size());
  for (auto &c : anss) {
    auto [val, i, j] = c;
    printf("%d %d %lld\n", i + 1, j + 1, val);
  }
  return 0;
}

