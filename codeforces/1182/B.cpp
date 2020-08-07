#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
typedef long double ld;

int const dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> mark(n, vector<bool>(m, false));
  function<void(int, int, vector<int> &, vector<int> &)> dfs = [&](int vx, int vy, vector<int> &x, vector<int> &y) {
    mark[vx][vy] = true;
    x.emplace_back(vx);
    y.emplace_back(vy);
    for (int i = 0; i < 4; i++) {
      int nx = vx + dx[i];
      int ny = vy + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '*' && !mark[nx][ny]) {
        dfs(nx, ny, x, y);
      }
    }
  };
  vector<vector<int>> xc, yc;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*' && !mark[i][j]) {
        xc.emplace_back();
        yc.emplace_back();
        dfs(i, j, xc.back(), yc.back());
      }
    }
  }
  if (xc.empty() || (int) xc.size() > 1) {
    cout << "NO\n";
    return 0;
  }
  int xx = min_element(xc[0].begin(), xc[0].end()) - xc[0].begin();
  int xxx = max_element(xc[0].begin(), xc[0].end()) - xc[0].begin();
  int yy = min_element(yc[0].begin(), yc[0].end()) - yc[0].begin();
  int yyy = max_element(yc[0].begin(), yc[0].end()) - yc[0].begin();
  int good_sz = (xc[0][xxx] - xc[0][xx] + 1) + (yc[0][yyy] - yc[0][yy] + 1) - 1;
  if (yc[0][xxx] == yc[0][xx] && xc[0][yy] == xc[0][yyy] && xc[0][xx] < xc[0][yy] &&
      xc[0][xxx] > xc[0][yy] && yc[0][yy] < yc[0][xx] && yc[0][yyy] > yc[0][xx] && (int) xc[0].size() == good_sz) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  // probably over complicated this a bit :|
  return 0;
}
