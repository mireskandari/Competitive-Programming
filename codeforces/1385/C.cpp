#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

template <class ...A>
void err(A ...a) {
  fprintf(stderr, a...);
}

constexpr int N = 2e5 + 10;

int a[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    int end_ = n - 1;
    while (end_ > 0 && a[end_] <= a[end_ - 1]) --end_;
    if (end_ <= 1) {
      puts("0");
      continue;
    }
    int begin_ = end_;
    while (begin_ > 0 && a[begin_] >= a[begin_ - 1]) --begin_;
    printf("%d\n", begin_);
  }
  return 0;
}
