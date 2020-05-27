#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnta = 0, cntb = 0, cnt = 0;
    for (auto &i : s) {
        if ((cnta + cntb) & 1) {
            if (i == 'a' && cnta > cntb) {
                i = 'b';
                cnt++;
            }
            else if (i == 'b' && cntb > cnta) {
                i = 'a';
                cnt++;
            }
            cnta = cntb = (cnta + cntb + 1) / 2;
        } else {
            (i == 'a' ? cnta : cntb)++;
        }
    }
    cout << cnt << '\n' << s;
    return 0;
}