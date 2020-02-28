#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int const N = 1e5 + 1;
int in[N], l[N], sl[N], ans[N], t;
bool iss[N];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    forn(0, n, i) cin >> in[i];
    forn(0, m, i) {
        cin >> l[i];
        l[i]--;
        sl[i] = l[i];
    }
    sl[m] = n;
    sort(sl, sl + m + 1, greater<int>());
    // cout << '\n';
    forn(0, m, i) {
        // cout << sl[i] << '\n';
        forn(sl[i + 1], sl[i], j) {
            // cout << in[j] << ' ';
            if(!iss[in[j]]) {
                iss[in[j]] = true;
                t++;
            }
        }
        // cout << sl[i + 1] << ' ' << t << '\n';
        ans[sl[i + 1]] = t;
    }
    // cout << '\n';
    forn(0, m, i) {
        cout << ans[l[i]] << '\n';
    }
    return 0;
}