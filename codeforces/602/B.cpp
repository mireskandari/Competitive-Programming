#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr int N = 1e5 + 10;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  auto solve = [&](int mid) {
    bool ok = false;
    map<int, int> mp;
    auto dec = [&](int val) {
      if (--mp[val] == 0) mp.erase(val);
    };
    for (int i = 0; i < mid; ++i) {
      mp[a[i]]++;
    }
    if (mp.begin()->first >= mp.rbegin()->first - 1) {
      ok = true;
    }
    for (int i = mid; i < n; ++i) {
      dec(a[i - mid]);
      mp[a[i]]++;
      if (mp.begin()->first >= mp.rbegin()->first - 1) {
        ok = true;
      }
    }
    return ok;
  };
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (r + l) >> 1;
    if (solve(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%d", solve(r) ? r : l);
  return 0;
}
