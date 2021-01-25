#include <bits/stdc++.h>
using namespace std;

int main() {
        int tc;
        scanf("%d", &tc);
        while (tc--) {
                int n;
                scanf("%d", &n);
                for (int i = 0; i < 1000; ++i) {
                        if (i * 2021 - n >= 0 && i * 2021 - n <= i) {
                                puts("YES");
                                goto FINISH;
                        }
                }
                puts("NO");
FINISH:;
        }
}