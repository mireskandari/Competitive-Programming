#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { 
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

signed main() {
    int n, q;
    scanf("%d %d", &n, &q);
    set<int> s;
    map<int, int> diff;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s.emplace(x);
    }
    for (auto it = next(s.begin()); it != s.end(); ++it) 
        diff[*it - *prev(it)]++;
    printf("%d\n", *s.rbegin() - *s.begin() - (!diff.empty() ? diff.rbegin()->first : 0));
    auto dec = [&](int a) {
        if (--diff[a] == 0) diff.erase(a);
    };
    while (q--) {
        int t, x;
        scanf("%d %d", &t, &x);
        if (t == 0) {
            auto p = s.find(x);
            if (p == s.begin()) {
                if ((int) s.size() > 1) dec(*next(p) - x);
            } else if (p == prev(s.end())) {
                dec(x - *prev(p));
            } else {
                dec(*next(p) - x);
                dec(x - *prev(p));
                diff[*next(p) - *prev(p)]++;
            }
            s.erase(p);
        } else {
            auto p = s.lower_bound(x);
            if (!s.empty()) {
                if (p == s.begin()) {
                    diff[*p - x]++;
                } else if (p == s.end()) {
                    diff[x - *prev(p)]++;
                } else {
                    dec(*p - *prev(p));
                    diff[*p - x]++;
                    diff[x - *prev(p)]++;
                }
            }
            s.emplace(x);
        }
        if (s.empty()) printf("%d\n", 0);
        else printf("%d\n", *s.rbegin() - *s.begin() - (!diff.empty() ? diff.rbegin()->first : 0));
    }
    return 0;
}
