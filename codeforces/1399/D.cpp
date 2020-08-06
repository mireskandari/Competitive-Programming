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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    V(V(int)) gps;
    V(priority_queue<PP(int)>) pq(2);
    for (int i = 0; i < n; i++) {
      int b = s[i] == '1';
      if (pq[b].empty()) {
        pq[!b].emplace(1, (int) gps.size());
        gps.emplace_back(1, i);
      } else {
        int sz, idx;
        tie(sz, idx) = pq[b].top();
        pq[b].pop();
        pq[!b].emplace(sz + 1, idx);
        gps[idx].emplace_back(i);
      }
    }
    V(int) p(n);
    for (int i = 0; i < (int) gps.size(); i++) {
      for (auto &j : gps[i]) {
        p[j] = i;
      }
    }
    cout << *max_element(p.begin(), p.end()) + 1 << '\n';
    for (auto &i : p) cout << i + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
