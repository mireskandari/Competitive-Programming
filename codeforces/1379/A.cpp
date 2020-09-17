#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) 0
// #define dbg(a) cerr << __LINE__ << " \"" << #a << "\":" << a << '\n'

const string S = "abacaba";
const int L = int(S.size());

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string found;
        for (int i = 0; i + L - 1 < n; ++i) {
            bool ok = true;
            for (int j = 0; j < L; ++j) {
                if (s[i + j] == '?') continue;
                if (s[i + j] != S[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            string temp = s;
            for (int j = 0; j < L; ++j) {
                if (temp[i + j] == '?') temp[i + j] = S[j];
            }
            for (int j = 0; j < n; ++j) {
                if (temp[j] == '?') temp[j] = 'z';
            }
            int cnt = 0;
            for (int j = 0; j + L - 1 < n; ++j) {
                string sub = temp.substr(j, L);
                if (sub == S) ++cnt;
            }
            if (cnt != 1) continue;
            found = temp;
            break;
        }
        if (found != "") {
            cout << "YES\n" << found << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
