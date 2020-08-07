#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int mn_a = *min_element(a.begin(), a.end());
    int mn_b = *min_element(b.begin(), b.end());
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] - mn_a < b[i] - mn_b) {
        cnt += a[i] - mn_a;
        b[i] -= a[i] - mn_a;
        a[i] = mn_a;
      } else {
        cnt += b[i] - mn_b;
        a[i] -= b[i] - mn_b;
        b[i] = mn_b;
      }
    }
    for (int i = 0; i < n; i++) {
      cnt += b[i] - mn_b;
      cnt += a[i] - mn_a;
    }
    cout << cnt << '\n';
  }
  return 0;
}
