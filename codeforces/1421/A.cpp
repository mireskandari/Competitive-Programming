#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define ERR(a...) fprintf(stderr, a)

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    int xxor = a & b;
    cout << (a ^ xxor) + (b ^ xxor) << '\n';
  }
  return 0;
}
