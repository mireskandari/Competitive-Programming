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
  vector<int> a(n);
  map<int, vector<int>> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]].emplace_back(i);
  }
  int all = 1;
  for (auto &i : cnt) {
    for (int j = 2; j <= (int) i.second.size() && all < 3; j++) {
      all *= j;
    }
    if (all >= 3) break;
  }
  if (all < 3) {
    cout << "NO\n";
    return 0;
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int A, int B) {
    return a[A] < a[B];
  });
  set<int> mark;
  vector<vector<int>> idx2(2, idx);
  for (int x = 0; x < 2; x++) {
    for (int i = 0; i < n - 1; i++) {
      if (!mark.count(i) && (int) cnt[a[idx2[x][i]]].size() > 1 && a[idx2[x][i]] == a[idx2[x][i + 1]]) {
        mark.emplace(i);
        swap(idx2[x][i], idx2[x][i + 1]);
        cerr << i << '\n';
        break;
      }
    }
  }
  cout << "YES\n";
  for (auto &i : idx) cout << i + 1 << ' ';
  cout << '\n';
  for (int x = 0; x < 2; x++) {
    for (auto &i : idx2[x]) cout << i + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
