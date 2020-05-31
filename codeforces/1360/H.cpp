#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        long long n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &i : a) cin >> i;
        long long mid = ((1LL << m) - 1) / 2, nw = ((1LL << m) - n - 1) / 2LL;
//        cerr << nw << '\n';
        auto &&Format = [&m](string &s) {
            reverse(all(s));
            while (s.size() > m) s.pop_back();
            reverse(all(s));
        };
        for (long long i = max(0LL, mid - 201); i <= min((1LL << m) - 1, mid + 201); i++) {
            long long cntless = i;
            bool ok = true;
            for (auto &s : a) {
                if (auto tmp = bitset<60>(s).to_ullong(); tmp < i) cntless--;
                else if (tmp == i) {
                    ok = false;
                    break;
                }
            }
            if (ok && cntless == nw) {
                string s = bitset<60>(i).to_string();
                Format(s);
                cout << s << '\n';
                break;
            }
        }
    }
    return 0;
}