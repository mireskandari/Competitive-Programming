#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define ERR(a...) fprintf(stderr, a)

int main() {
  int n;
  cin >> n;
  int64_t num = 1;
  for (int64_t i = 3; i <= n; ++i) {
      num *= i;
  }
  cout << (num / (n / 2)) / (n / 2) << '\n';
  return 0;
}
