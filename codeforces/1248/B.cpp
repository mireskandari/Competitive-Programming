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
    deque<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    long long w = 0, h = 0;
    bool forw = true;
    while (!a.empty()) {
        if (forw) {
            w += a.back();
            a.pop_back();
        } else {
            h += a.front();
            a.pop_front();
        }
        forw = !forw;
    }
    cout << w * w + h * h << '\n';
    return 0;
}