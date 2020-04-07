#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

set<string> vis;
ll cost;
int n, k;
void bfs(string v) {
    queue<string> q;
    vis.insert(v);
    q.push(v);
    while (!q.empty() && vis.size() < k) {
        v = q.front();
        q.pop();

        rep (0, v.size(), i) {
            string u = v.substr(0, i) + v.substr(i + 1);

            if (!vis.count(u)) {
                vis.insert(u);
                cost += n - u.size();
                q.push(u);
            }
            if (vis.size() == k) return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;
    string s;
    cin >> s;

    bfs(s);
    if (vis.size() < k) return cout << -1, 0;
    else cout << cost;
    return 0;
}