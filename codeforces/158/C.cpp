#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string p = "/";
    while (n--) {
        string c;
        cin >> c;
        if (c == "pwd") cout << p << '\n';
        else {
            string np;
            cin >> np;
            if (np[0] == '/') p.clear();
            string f;
            static auto Clear = [&]() {
                int j = p.size() - 1;
                while (j >= 1 && p[j - 1] == '/') {
                    p.pop_back();
                    j--;
                }
            };
            for (int i = 0; i < np.size(); i++) {
                if (np[i] == '/') {
                    p += f;
                    p += '/';
                    f = "";
                    Clear();
                    continue;
                }
                if (np[i] == '.') {
                    if (p.back() == '/') p.pop_back();
                    for (int j = (int) (p.size()) - 1; j >= 0 && p[j] != '/'; j--) {
                        p.pop_back();
                    }
                    p += '/';
                    Clear();
                    i += 2;
                    continue;
                }
                f += np[i];
            }
            p += f + '/';
            Clear();
        }

    }
    return 0;
}