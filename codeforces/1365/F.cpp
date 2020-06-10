#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    if (n & 1 && a[n / 2] != b[n / 2]) {
        cout << "NO\n";
        return;
    }
    if (n & 1 && a[n / 2] != b[n / 2]) {
        cout << "NO\n";
        return;
    }
    multiset<set<int>> aa, bb;
    for (int i = 0; i < n / 2; i++) {
        aa.insert(set<int>{a[i], a[n - i - 1]});
        bb.insert(set<int>{b[i], b[n - i - 1]});
    }
    cout << (aa == bb ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        run_case();
    }
    return 0;
}