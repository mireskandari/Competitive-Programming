#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    long long sum1 = 2 * t1 + s * v1, sum2 = 2 * t2 + s * v2;
    cout << (sum1 < sum2 ? "First" : (sum1 == sum2 ? "Friendship" : "Second"));
    return 0;
}