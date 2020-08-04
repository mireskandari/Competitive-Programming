#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    
  int n, m;
  cin >> n >> m;
  V<tuple<ll, ll, ll>> e;
  V<PP<ll>> dp(n), last_dp(n);
  
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> v >> u >> w;
    e.emplace_back(w, --v, --u);
  }
  sort(e.begin(), e.end());

  auto update = [&](int ii, int jj) {
    for (int i = ii; i < jj; i++) {
      last_dp[get<2>(e[i])] = dp[get<2>(e[i])];
    }
  };
  
  int last = -1;
  for (int i = 0; i < m; i++) {
    if (last == -1 || get<0>(e[i]) > get<0>(e[last])) {
      update((last == -1 ? 0 : last), i);
      last = i;
    }
    int v, u, w;
    tie(w, v, u) = e[i];
    if (dp[v].second < w && dp[u].first < dp[v].first + 1) {
      dp[u] = PP<ll>{dp[v].first + 1, w};
    }
    if (dp[u].first < last_dp[v].first + 1) {
      dp[u] = PP<ll>{last_dp[v].first + 1, w};
    }
  }

  int best = INT_MIN;
  for (auto &i : dp) {
    best = max<ll>(best, i.first);
  }

  cout << best;
  return 0;
}
