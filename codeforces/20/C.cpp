#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cout
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long;
using ld = long double;

template<class T = int>
using V = vector<T>;
template<class T = int>
using VV = V<V<T>>;
template<class I, class J>
using P = pair<I, J>;
template<class T = int>
using PP = P<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  VV<PP<ll>> g(n);
  for (int i = 0; i < m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    g[--v].emplace_back(--u, w);
    g[u].emplace_back(v, w);
  }

  V<ll> dist(n, (ll) 1e14);
  V<> from(n);

  from[0] = -1;
  dist[0] = 0;

  set<PP<ll>> q;
  for (int i = 0; i < n; i++) {
    q.emplace(dist[i], i);
  }

  while (!q.empty()) {
    ll v = q.begin()->Y;
    q.erase(q.begin());

    for (auto &u : g[v]) {
      if (dist[u.X] > dist[v] + u.Y) {
        q.erase(PP<ll>(dist[u.X], u.X));
        
        from[u.X] = v;
        dist[u.X] = dist[v] + u.Y;
        q.emplace(dist[u.X], u.X);
      }
    }
  }
  
  if (dist[n - 1] >= (ll)(1e14)) {
    cout << -1;
    return 0;
  }

  V<> ans;
  int v = n - 1;
  ans.emplace_back(n - 1);
  while (from[v] != -1) {
    ans.emplace_back(from[v]);
    v = from[v];
  }

  reverse(all(ans));

  for (auto &i : ans) cout << i + 1 << ' ';
  return 0;
}
