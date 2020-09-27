#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    string s;
    cin >> s;
    int n = int(s.size());
    string ans;
    auto No = [&]() {
        cout << "No solution";
        exit(0);
    };
    if (s.find('@') == string::npos) No();
    for (int i = 0; i < n; ) {
        if (s[i] == '@') {
            if (i == n - 1 || s[i + 1] == '@' || ans.empty() || ans.back() == ',') No();
            ans += s[i];
            ans += s[i + 1];
            if (s.find('@', i + 2) == string::npos) {
                ans += s.substr(i + 2);
                break;
            } else {
                ans += ',';
            }
            i += 2;
        } else {
            ans += s[i];
            ++i;
        }
    }
    cout << ans;
    return 0;
}
