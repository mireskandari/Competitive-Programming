#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
#define V(...) vector<__VA_ARGS__>
#define PP(...) pair<__VA_ARGS__, __VA_ARGS__>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  V(ll) a(n), cnt(100001);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll mx = *max_element(a.begin(), a.end());
  V(ll) dp(mx + 2);
  dp[0] = dp[1] = 0;
  for (int i = 2; i <= mx + 1; i++) {
    dp[i] = max(cnt[i - 1] * (i - 1) + dp[i - 2], dp[i - 1]);
  }
  cout << dp[mx + 1];
  return 0;
}
