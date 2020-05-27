#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int mxteam = n - m + 1;
    int mnteam = n / m;
    int rm = n - mnteam * m;
    auto Sum = [](long long n) {
        return n * (n - 1) / 2;
    };
    long long cntless = rm * Sum(mnteam + 1), cntgr = (m - rm) * Sum(mnteam);
    cout << cntless + cntgr << ' ' << Sum(mxteam);
    return 0;
}