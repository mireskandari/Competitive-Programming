#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//    cout << fixed << setprecision(15);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        vector<pair<int, int>> in;
        for (int c : s) {
            if (in.empty()) {
                in.emplace_back(s[0], 1);
                continue;
            }
            if (in.back().X == c) {
                in.back().Y++;
            } else {
                in.emplace_back(c, 1);
            }
        }
        int sum = '1' + '2' + '3';
        int best = INT_MAX;
        for (int i = 2; i < in.size(); i++) {
            if (in[i - 2].X + in[i - 1].X + in[i].X == sum) {
                int sz = 1 + in[i - 1].Y + 1;
                best = min(best, sz);
            }
        }
        cout << (best == INT_MAX ? 0 : best) << '\n';
    }
    return 0;
}