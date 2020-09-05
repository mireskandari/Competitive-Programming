#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;

vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n + 3, string(m + 3, '.'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<array<int, 2>>> compo;
    vector<vector<bool>> mark(n + 3, vector<bool>(m + 3));
    auto Check = [&](int x, int y) {
        return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
    };
    function<void(int, int, int, bool&)> Dfs = [&](int vx, int vy, int idx, bool &side) {
        mark[vx][vy] = true;
        if (vx < 1 || vx > n || vy < 1 || vy > m) side = true;
        compo[idx].push_back({vx, vy});
        for (int d = 0; d < 4; ++d) {
            int nx = vx + dx[d], ny = vy + dy[d];
            if (Check(nx, ny) && !mark[nx][ny] && a[nx][ny] == '.') {
                Dfs(nx, ny, idx, side);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '.' && !mark[i][j]) {
                bool side = false;
                compo.emplace_back();
                Dfs(i, j, (int) compo.size() - 1, side);
                if (side) compo.pop_back();
            }
        }
    }
    sort(all(compo), [](const auto &x, const auto &y) {
        return x.size() < y.size();
    });
    dbg(compo.size());
    int diff = (int) compo.size() - k;
    int sum = 0;
    for (int i = 0; i < diff; ++i) {
        sum += (int) compo[i].size();
        for (auto &p : compo[i]) {
            a[p[0]][p[1]] = '*';
        }
    }
    cout << sum << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}

