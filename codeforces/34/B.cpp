#include <bits/stdc++.h>
using namespace std;

int constexpr N = 100;

int n, m;
int arr[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    long long sum = accumulate(arr, arr + n, 0, [&](long long s, int x) {
        cnt++;
        return s + (x < 0 && cnt <= m ? x : 0);
    });
    cout << abs(sum);
    return 0;
}