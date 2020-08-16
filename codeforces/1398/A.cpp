#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    if (a[0] + a[1] > a.back()) {
      cout << -1 << '\n';
    } else {
      cout << 1 << ' ' << 2 << ' ' << n << '\n';
    }
  }
  return 0;
}
