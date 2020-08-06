#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
#define V(...) vector<__VA_ARGS__>
#define PP(...) pair<__VA_ARGS__, __VA_ARGS__>

int constexpr N = 1e5 + 10;

ll n, S, s;
V(PP(ll)) g[N];
V(bool) leaf; // for less memory
int cntlow[N];
priority_queue<pair<ll, PP(ll)>> pq; // w, cnt

inline void prep() {
  s = 0;
  while (!pq.empty()) pq.pop();
  leaf.resize(n);
  fill(leaf.begin(), leaf.end(), false);
  fill(cntlow, cntlow + n, 0);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
}

void dfs(int v, int p) {
  int j = 0;
  for (auto &u : g[v]) {
    if (u.first == p) continue;
    dfs(u.first, v);
    s += u.second * cntlow[u.first];
    cntlow[v] += cntlow[u.first];
    pq.emplace(((u.second + 1) / 2) * cntlow[u.first], PP(ll){u.second, cntlow[u.first]});
    j++;
  }
  if (!j) cntlow[v]++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> S;
    prep();
    for (int i = 0; i < n - 1; i++) {
      ll v, u, w;
      cin >> v >> u >> w;
      g[--v].emplace_back(--u, w);
      g[u].emplace_back(v, w);
    }
    dfs(0, -1);
    ll cntmv = 0;
    while (s > S) {
      auto edge = pq.top();
      s -= edge.first;
      pq.pop();
      ll w = edge.second.first / 2;
      pq.emplace(((w + 1) / 2) * edge.second.second, PP(ll){w, edge.second.second});
      cntmv++;
    }
    cout << cntmv << '\n';
  }
  return 0;
}
