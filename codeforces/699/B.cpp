#include <bits/stdc++.h>

using namespace std;
char a[1010][1010];
int main() {
    int n, m;
    scanf("%d %d ", &n, &m);
    map<int, int> x, y;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == '*') {
                x[i]++;
                y[j]++;
                cnt++;
            }
        }
    }
    if (cnt == 0) {
        puts("YES\n 1 1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i] + y[j] + (a[i][j] != '*') > cnt) {
                printf("YES\n%d %d", i + 1, j + 1);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}