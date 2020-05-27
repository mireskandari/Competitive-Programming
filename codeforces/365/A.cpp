#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        vector<char> mark(k + '0' + 1, false);
        string s;
        cin >> s;
        for (auto &c : s) if (c <= k + '0') mark[c] = true;
        cnt += all_of('0' + all(mark), [](auto &a) { return a; });
    }
    cout << cnt;
    return 0;
}