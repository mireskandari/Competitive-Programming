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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    auto Solve = []() {
        string s, t;
        cin >> s >> t;
        auto mp = new set<int>['z' + 1];
        rep (0, s.size(), i) {
            mp[s[i]].insert(i);
        }
        int i = 0;
        ll cnt = 0;
        while (i < t.size()) {
            cnt++;
            if (mp[t[i]].size() == 0) return cout << "-1\n", 0;
            if (i == t.size() - 1) break;
            int j = *mp[t[i]].begin(), x;
            do {
                i++;
                if (i == t.size()) break;
                if (mp[t[i]].size() == 0) return cout << "-1\n", 0;
                x = j;
                auto p = mp[t[i]].lower_bound(x + 1);
                j = p == mp[t[i]].end() ? -1 : *p;
            } while (x < j);
        }
        cout << cnt << '\n';
        return 0;
    };
    int tc;
    cin >> tc;
    while (tc--) {
        Solve();
    }
    return 0;
}