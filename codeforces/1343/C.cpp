#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<ll> in(n);
        rep (0, n, i) cin >> in[i];
        vector<ll> subp;
        for (auto i : in) {
            if (!subp.empty() && i < 0) {
                if (subp.back() >= 0) subp.push_back(i);
                else if (subp.back() < i) {
                    subp.pop_back();
                    subp.push_back(i);
                }
            } else {
                if (subp.empty() || subp.back() < 0) subp.push_back(i);
                else if (subp.back() < i) {
                    subp.pop_back();
                    subp.push_back(i);
                }
            }
        }
        ll sum = accumulate(all(subp), 0LL);
        vector<ll> subn;
        for (auto i : in) {
            if (!subn.empty() && i >= 0) {
                if (subn.back() < 0) subn.push_back(i);
                else if (subn.back() < i) {
                    subn.pop_back();
                    subn.push_back(i);
                }
            } else {
                if (subn.empty() || subn.back() >= 0) subn.push_back(i);
                else if (subn.back() < i) {
                    subn.pop_back();
                    subn.push_back(i);
                }
            }
        }
        sum = subp.size() >= subn.size() ? sum : accumulate(all(subn), 0LL);
        cout << sum << '\n';
    }
    return 0;
}