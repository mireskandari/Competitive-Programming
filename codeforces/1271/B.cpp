#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = s;
    // white
    int sum = 'W' + 'B';
    vector<int> moves;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'B') {
            s[i] = 'W';
            s[i + 1] = sum - s[i + 1];
            moves.emplace_back(i + 1);
        }
    }
    // black
    if (set<char>(all(s)).size() != 1) {
        moves.clear();
        s = ss;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'W') {
                s[i] = 'B';
                s[i + 1] = sum - s[i + 1];
                moves.emplace_back(i + 1);
            }
        }
    }
    if (set<char>(all(s)).size() != 1) return cout << -1, 0;
    cout << moves.size() << '\n';
    for (auto m : moves) cout << m << ' ';
    return 0;
}