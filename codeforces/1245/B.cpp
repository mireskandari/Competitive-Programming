#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

void run_case() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    string t = s;
    vector<bool> mk(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!a) break;
        if (!mk[i] && s[i] == 'S') {
            t[i] = 'R';
            a--;
            cnt++;
            mk[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!b) break;
        if (!mk[i] && s[i] == 'R') {
            t[i] = 'P';
            b--;
            cnt++;
            mk[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!c) break;
        if (!mk[i] && s[i] == 'P') {
            t[i] = 'S';
            c--;
            cnt++;
            mk[i] = true;
        }
    }
    string rm = string(a, 'R') + string(b, 'P') + string(c, 'S');
    for (int i = 0; i < n; i++) {
        if (!mk[i]) {
            t[i] = rm.back();
            rm.pop_back();
        }
    }
    if (cnt >= (n + 1) / 2) {
        cout << "YES\n" << t << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}