#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<pair<Int, Int>> moves;
    Int ans = n;
    for (int i = n - 1; i > 0; --i) {
      moves.emplace_back(ans, i);
      ans = (ans + i + 1) >> 1;
    }
    printf("%lld\n", ans);
    for (auto &move : moves) {
      auto [x, y] = move;
      printf("%lld %lld\n", x, y);
    }
  }
  return 0;
}
