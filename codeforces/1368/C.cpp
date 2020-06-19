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
    vector<pair<int, int>> p;
    p = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (int i = 2; i < n + 2; i++) {
        vector<pair<int, int>> nw = {{i, i}, {i - 1, i}, {i, i - 1}};
        for (auto &j : nw) p.emplace_back(j);
    }
    cout << size(p) << '\n';
    for (auto &i : p) cout << i.first << ' ' << i.second << '\n';
    return 0;
}