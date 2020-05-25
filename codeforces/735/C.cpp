#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> f, s;
    f = {1, 2};
    s = {1, 3};
    for (int i = 2; ; i++) {
        if (f.back() >= n) break;
        f.emplace_back(i + 1);
        f.back() += s[i - 2];
        s.emplace_back(f.back() + s.back());
    }
    cout << f.size() - 1;
    return 0;
}