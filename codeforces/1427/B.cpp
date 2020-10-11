#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr int N = 2e5 + 10;

char s[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    vector<int> wins;
    for (int i = 0; i < n; ++i)
      if (s[i] == 'W') wins.push_back(i);
    vector<pair<int, int>> diff;
    for (int i = 1; i < (int) wins.size(); ++i)
      diff.emplace_back(wins[i] - wins[i - 1], i - 1);
    sort(begin(diff), end(diff));
    for (auto &win : diff) {
      auto [_, idx] = win;
      int i = wins[idx];
      // fprintf(stderr, "i = %d\n", i);
      for (++i; k; ++i)
        if (s[i] != 'W') {
          s[i] = 'W';
          --k;
        } else {
          break;
        }
      if (!k) break;
    }
    if (!wins.empty()) {
      for (int i = wins.front() - 1; i >= 0 && k; --i)
        if (s[i] != 'W') {
          s[i] = 'W';
          --k;
        }
      for (int i = wins.back() + 1; i < n && k; ++i)
        if (s[i] != 'W') {
          s[i] = 'W';
          --k;
        }
    } else {
      for (int i = 0; i < n && k; ++i) 
        if (s[i] != 'W') {
          s[i] = 'W';
          --k;
        }
    }
    // fprintf(stderr, "----%s\n", s);
    int score = 0;
    for (int last_w = false, i = 0; i < n; ++i)
      if (s[i] == 'W') {
        if (last_w) score += 2;
        else score += 1;
        last_w = true;
      } else {
        last_w = false;
      }
    printf("%d\n", score);
  }
  return 0;
}
