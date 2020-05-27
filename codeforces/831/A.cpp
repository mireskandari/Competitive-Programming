#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int i = 1;
    while (i < n && a[i - 1] < a[i]) i++;
    while (i < n && a[i - 1] == a[i]) i++;
    while (i < n && a[i - 1] > a[i]) i++;
    cout << (i == n ? "YES" : "NO");
    return 0;
}