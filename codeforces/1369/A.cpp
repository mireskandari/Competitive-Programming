#include <bits/stdc++.h>

int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::cin >> n;
        std::cout << (n % 4 ? "NO\n" : "YES\n");
    }
    return 0;
}