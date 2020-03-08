#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int cnt[1001];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    forn (0, n, i) {
        int in; 
        cin >> in;
        cnt[in]++;
    }
    cout << *max_element(cnt, cnt + 1001) << ' '; 
    cout << count_if(cnt, cnt + 1001, [](int x) {
        return x > 0;
    });
    return 0;
}