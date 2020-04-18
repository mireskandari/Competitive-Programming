#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> day(n, 0), in(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        int mx = 1;
        while (!st.empty() && in[st.top()] < in[i]) {
            mx = max(mx, day[st.top()] + 1);
            st.pop();
        }
        if (!st.empty()) day[i] = mx;
        st.push(i);
    }
    cout << *max_element(day.begin(), day.end());
    return 0;
}