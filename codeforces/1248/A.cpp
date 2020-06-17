#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

void run_case() {
    int n;
    cin >> n;
    vector<int> p1(n);
    for (auto &i : p1) cin >> i;
    int m;
    cin >> m;
    vector<int> p2(m);
    for (auto &i : p2) cin >> i;
    long long od1 = 0, od2 = 0, ev1 = 0, ev2 = 0;
    for (auto &i : p1) (i & 1 ? od1 : ev1)++;
    for (auto &i : p2) (i & 1 ? od2 : ev2)++;
    cout << od1 * od2 + ev1 * ev2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}