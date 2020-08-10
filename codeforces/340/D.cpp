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
  int n;
  cin >> n;
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto p = lower_bound(dp.begin(), dp.end(), a);
    if (p == dp.end()) {
      dp.emplace_back(a);
    } else if (*p > a) {
      *p = a;
    }
  }
  cout << (int) dp.size();
  return 0;
}
