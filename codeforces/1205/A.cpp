#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define vc vector

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  if (!(n & 1)) {
    cout << "NO";
    exit(0);
  }
  vc<int> ans(2 * n);
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      ans[i] = 2 * i + 2;
      ans[i + n] = 2 * i + 1;
    } else {
      ans[i] = 2 * i + 1;
      ans[i + n] = 2 * i + 2;
    }
  }
  cout << "YES\n";
  for (auto &i : ans) cout << i << ' ';
  return 0;
}
