#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &s : a) cin >> s;
        static auto &&Hamming = [](string &a, string &b) {
            int cnt = 0;
            for (int i = 0; i < a.size(); i++) {
                cnt += a[i] != b[i];
            }
            return cnt;
        };
        string s;
        for (auto &i : a) {
            s = i;
            for (int j = 'a'; j <= 'z'; j++) {
                for (int idx = 0; idx < m; idx++) {
                    char temp = s[idx];
                    s[idx] = j;
                    for (auto &ss : a) {
                        if (Hamming(ss, s) > 1) {
                            goto bad;
                        }
                    }
                    cout << s << '\n';
                    goto found;
                    bad:;
                    s[idx] = temp;
                }
            }
        }
        cout << -1 << '\n';
        found:;
    }
    return 0;
}