#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int best = INT_MIN;
    for (int i = 0; i <= n * n; i++) {
      int cnt = 0, last = n - 1;
      for (int j = 0; j < n; j++) {
        for (int jj = last; jj > j; jj--) {
          if (a[j] + a[jj] == i) {
            cnt++;
            last = jj - 1;
            break;
          }
        }
      }
      best = max(best, cnt);
    }
    cout << best << '\n';;
  }
  return 0;
}
