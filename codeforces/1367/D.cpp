#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

void run_case() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> sz(27);
    for (auto &c : s) sz[c - 'a']++;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    string t(n, '0');
    vector<int> mk(n, false);
    int now = 25;
    while (count(t.begin(), t.end(), '0')) {
        vector<int> z;
        for (int i = 0; i < n; i++) {
            cerr << a[i] << ' ';
            if (!mk[i] && !a[i]) {
                z.emplace_back(i);
                mk[i] = true;
            }
        }
        cerr << '\n';
        while (now >= 0 && sz[now] < size(z)) now--;
        for (auto &i : z) {
            t[i] = (char)now + 'a';
            sz[now]--;
        }
        now--;
        for (int i = 0; i < n; i++) {
            if (mk[i]) continue;
            for (auto &j : z) {
                a[i] -= abs(i - j);
            }
        }
    }
    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}