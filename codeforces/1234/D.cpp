#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    auto s = new char[N + 1];
    vector<set<int>> pos(26);
    cin >> s;
    rep (0, strlen(s), i) {
        pos[s[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int sw; cin >> sw;
        if (sw == 1) {
            int p;
            char c;
            cin >> p >> c;
            p--;
            pos[s[p] - 'a'].erase(p);
            pos[c - 'a'].insert(p);
            s[p] = c;
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            int cnt = 0;
            rep (0, 26, i) {
                auto p = pos[i].lower_bound(l);
                if (p != pos[i].end() && l <= *p && *p < r) cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}