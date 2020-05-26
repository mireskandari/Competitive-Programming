#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        n++;
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= i) {
//                cerr << i << ' ' << a[i] << '\n';
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}