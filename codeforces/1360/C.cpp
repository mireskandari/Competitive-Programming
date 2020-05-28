#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        int cnt = 0;
        for (auto &i : s) if (i & 1) cnt++;
        if (!(cnt & 1)) cout << "YES" << '\n';
        else {
            set<int> aa(s.begin(), s.end());
            bool ok = false;
            for (auto &i : aa) {
                if (s.find(i) != s.end() && s.find(i - 1) != s.end()) {
                    s.erase(s.lower_bound(i));
                    s.erase(s.lower_bound(i - 1));
                    cnt--;
                }
                if (!(cnt & 1)) {
                    ok = true;
                    break;
                }
            }
            if (ok) cout << "YES" << '\n';
            else cout << "NO\n";
        }
    }
    return 0;
}