#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int in[100000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    bool isrev = false, rev = false;
    int l = 0, r = 0;
    cin >> n;
    forn (0, n, i) cin >> in[i];
    forn (1, n, i) {
        if (in[i] < in[i - 1]) {
            if (isrev) {
                r++;
            } else if (rev) {
                cout << "no";
                return 0;
            } else {
                l = i - 1;
                r = i;
                rev = isrev = true;
            }
        }
    }
    if (!rev) cout << "yes\n1 1";
    else {
        reverse(in + l, in + r + 1);
        if (is_sorted(in, in + n)) {
            cout << "yes\n" << l + 1 << ' ' << r + 1;
        } else {
            cout << "no";
        }
    }
    return 0;
}