#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int a = 1, b = 1, c = 1;
        set<int> used;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                a = i;
                used.insert(i);
                break;
            }
        }
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0 && !used.count(i) && !used.count(n / i) && n / i != i) {
                b = n / i;
                c = i;
                break;
            }
        }
        if (a == 1 || b == 1 || c == 1) cout << "NO\n";
        else cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}