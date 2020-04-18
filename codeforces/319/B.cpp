#include <bits/stdc++.h>

int constexpr N = 1e5 + 10;
int day[N], in[N];
int main() {

    int n;
    scanf("%d", &n);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        int mx = 1;
        while (!st.empty() && in[st.top()] < in[i]) {
            mx = std::max(mx, day[st.top()] + 1);
            st.pop();
        }
        if (!st.empty()) day[i] = mx;
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, day[i]);
    }
    printf("%d", ans);
    return 0;
}