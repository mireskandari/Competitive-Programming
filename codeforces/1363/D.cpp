#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int ask(vector<int> &a) {
    cout << "? " << a.size() << ' ';
    for (auto &i : a) cout << i + 1 << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector<int> sub[1000];
vector<int> ans, a;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        fill(sub, sub + k, vector<int>());
        for (int i = 0; i < k; i++) {
            int sz;
            cin >> sz;
            for (int j = 0; j < sz; j++) {
                int a;
                cin >> a;
                sub[i].push_back(--a);
            }
        }

        a.resize(n);
        iota(all(a), 0);
        int mxall = ask(a);
        int l = 0, r = k - 1;
        for (int i = 0; i < 10; i++) {
            int m = (r + l) / 2;
            a.clear();
            for (int j = 0; j <= m; j++) {
                for (auto &x : sub[j]) a.push_back(x);
            }
            if (a.empty()) break;
            if (ask(a) == mxall) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        ans.resize(k);
        for (int i = 0; i < k; i++) {
            if (i == l) {
                a.clear();
                vector<bool> has(n + 1, true);
                for (auto &x : sub[l]) {
                    has[x] = false;
                }
                for (int x = 0; x < n; x++) {
                    if (has[x]) a.push_back(x);
                }
                ans[i] = ask(a);
            } else {
                ans[i] = mxall;
            }
        }
        cout << "! ";
        for (auto &i : ans) cout << i << ' ';
        cout << endl;
        string ok;
        cin >> ok;
    }
    return 0;
}