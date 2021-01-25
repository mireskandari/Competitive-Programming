#include <bits/stdc++.h>
using namespace std;

int main() {
        int tc;
        scanf("%d", &tc);
        while (tc--) {
                long long n;
                scanf("%lld", &n);
                if (__builtin_popcountll(n) > 1) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
        }
}