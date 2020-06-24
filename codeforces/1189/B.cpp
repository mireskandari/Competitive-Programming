#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    deque<int> ans;
    int par = 0;
    while (!a.empty()) {
        if (par) ans.emplace_back(a.back());
        else ans.emplace_front(a.back());
        par ^= 1;
        a.pop_back();
    }
    for (int i = 0; i < n; i++) {
        int pre = (i - 1 + n) % n;
        int nex = (i + 1) % n;
        if (ans[pre] + ans[nex] <= ans[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (auto &i : ans) cout << i << ' ';
    return 0;
}