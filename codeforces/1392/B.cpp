#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

#define int ll

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      a[i] = -a[i] + mx;
    }
    --k;
    mx = *max_element(a.begin(), a.end());
    if (k & 1) {
      for (int i = 0; i < n; ++i) {
        a[i] = -a[i] + mx;
      }
    }
    for (auto &i : a) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
