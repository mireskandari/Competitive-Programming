#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define err(a...) fprintf(stderr, a)
typedef long long ll;

constexpr int N = 60;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    puts("0");
    exit(0);
  }
  vector<vector<int>> query;
  auto Work = [&](vector<int> mv) {
    vector<vector<int>> res;
    for (int i = 1, cnt = 1, j = 0; i <= n; ++i, ++cnt) {
      if (res.empty()) {
        res.emplace_back(1, a[i]);
      } else {
        res.back().push_back(a[i]);
      }
      if (cnt == mv[j]) {
        res.emplace_back();
        cnt = 0;
        ++j;
      }
    }
    reverse(res.begin(), res.end());
    int i = 1;
    for (auto &v : res) {
      for (auto &j : v) {
        a[i] = j;
        ++i;
      }
    }
  };
  auto Make = [&](int sz, bool in_end, int now) {
    query.emplace_back();
    if (in_end) {
      int i;
      for (i = n; n - i + 1 <= sz; --i) {
        query.back().push_back(1);
      }
      query.back().push_back(0);
      for (; i > 0; --i) {
        query.back().back()++;
        if (a[i] == now) query.back().push_back(0);
      }
      if (!query.back().empty() && query.back().back() == 0) {
        query.back().pop_back();
      }
      reverse(query.back().begin(), query.back().end());
    } else {
      int i;
      for (i = 1; i <= sz; ++i) {
        query.back().push_back(1);
      }
      query.back().push_back(0);
      for (; i <= n; ++i) {
        query.back().back()++;
        if (a[i] == now) query.back().push_back(0);
      }
      if (!query.back().empty() && query.back().back() == 0) {
        query.back().pop_back();
      }
    }
    if (query.back().size() == 1) {
      query.pop_back();
      return;
    }
    Work(query.back());
  };
  for (int i = 1; i < n; ++i) {
    Make(i - 1, i & 1, i);
  }
  if (a[1] == n) {
    query.emplace_back();
    for (int i = 0; i < n; ++i) {
      query.back().push_back(1);
    }
  }
  /*for (int i = 1; i <= n; ++i) {
    err("%d ", a[i]);
  }
  err("\n");*/
  printf("%ld\n", query.size());
  for (auto &q : query) {
    printf("%ld ", q.size());
    for (auto &i : q) {
      printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
