#include <bits/stdc++.h>
using namespace std;

struct Q { int i, j; };

vector<Q> ans;

void solve(int l, int r) {
    if (r - l < 2) return;

    int half = (r - l) >> 1;
    solve(l, l + half);
    solve(l + half, r);
    
    for (int i = l; i + half < r; ++i)
        ans.push_back({i, i + half});
}

int main() {
    ans.reserve(500000);
    
    int n;
    scanf("%d", &n);
    
    int lg = (int) log2(n);
    solve(0, 1 << lg);
    if (n != (1 << lg)) 
        solve(n - (1 << lg), n);
    
    printf("%d\n", (int) ans.size());
    for (auto &q : ans)
        printf("%d %d\n", q.i + 1, q.j + 1);

    return 0;
}
