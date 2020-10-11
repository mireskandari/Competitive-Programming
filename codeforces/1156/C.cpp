#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr int N = 2e5 + 10;

int a[N];

int main() {
  int n, z;
  scanf("%d %d", &n, &z);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  auto solve = [&](int mid) {
    int add = n - mid;
    for (int i = 0; i < mid; ++i) {
      if (a[i + add] - a[i] < z) {
        return false;
      }
    }
    return true;
  };
  int low = 0, high = n / 2;
  while (high - low > 1) { // WTF
    int mid = (low + high) >> 1;
    if (solve(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printf("%d", solve(high) ? high : low);
  return 0;
}
