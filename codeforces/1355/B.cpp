#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//    cout << fixed << setprecision(15);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(all(a));
        int cnt = 0;
        for (int i = 0; i < n; ) {
            bool filled = false;
            int mx = a[i], sz = 1;
            i++;
            while (i <= n && !filled) {
                if (mx == sz) {
                    filled = true;
                    break;
                }
                if (i == n) break;
                mx = max(a[i], mx);
                sz++;
                i++;
            }
            cnt += filled;
        }
        cout << cnt << '\n';
    }
    return 0;
}