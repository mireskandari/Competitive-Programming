#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif


int const N = 110;
vector<char> C;
int const dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

vector<int> kk;
char mp[N][N];
int col[N][N];
int cnt[N];
int n, m, k;

inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(char dir, int c, int x, int y) {
    col[x][y] = C[c];
    if (mp[x][y]) cnt[c]++;
    if (cnt[c] == kk[c]) {
        c++;
        if (c == k) return;
    }
    int nx = x + dx[dir], ny = y + dy[dir];
    if (!check(nx, ny) || col[nx][ny] != -1) {
        dir++;
        dir %= 4;
    }
    nx = x + dx[dir], ny = y + dy[dir];
    dfs(dir, c, nx, ny);
}

void dfs2(int x, int y, int c) {
    col[x][y] = c;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && col[nx][ny] == -1) dfs2(nx, ny, c);
    }
}

void run_case() {
    cin >> n >> m >> k;
    fill(cnt, cnt + N, 0);
    fill(&col[0][0], &col[n - 1][m - 1] + 1, -1);
    int cntr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            mp[i][j] = mp[i][j] == 'R';
            cntr += mp[i][j];
        }
    }
    int each = cntr / k;
    int rm = cntr % k;
    if (each) kk.resize(k);
    else if (rm) kk.resize(1);
    fill(kk.begin(), kk.end(), each);
    for (int i = 0; i < rm; i++) kk[i]++;
    dfs(0, 0, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (col[i][j] != -1) dfs2(i, j, col[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << char(col[i][j]);
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (char i = '0'; i <= '9'; i++) C.emplace_back(i);
    for (char i = 'a'; i <= 'z'; i++) C.emplace_back(i);
    for (char i = 'A'; i <= 'Z'; i++) C.emplace_back(i);

    int tc;
    cin >> tc;
    while (tc--) {
        run_case();
    }
    return 0;
}