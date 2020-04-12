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

bool is_pali(string s) {
    string ss = s;
    reverse(all(ss));
    return ss == s;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<string, int> cnt;
    map<string, bool> isp;
    rep (0, n, i) {
        string s;
        cin >> s;
        cnt[s]++;
    }

    for (const auto& s : cnt) {
        isp[s.X] = is_pali(s.X);
    }

    string ss, ess;
    string bigp;
    for (const auto& sss : cnt)
        if (isp[sss.X] && (bigp.empty() || sss.X > bigp) && (cnt[sss.X] & 1)) bigp = sss.X;
    map<string, bool> mark;
    for (const auto& sss : cnt) {
        if (mark[sss.X]) continue;
        string rev = sss.X;
        reverse(all(rev));
        if(!isp[sss.X]) {
            mark[rev] = true;
            rep (0, min(sss.Y, cnt[rev]), i) {
                ss += sss.X;
                ess += sss.X;
            }
        }
        else if (isp[sss.X] && sss.Y % 2 == 0) {
            rep (0, sss.Y / 2, i) {
                ss += sss.X;
                ess += sss.X;
            }
        }
    }
    ss += bigp;
    reverse(all(ess));
    ss += ess;


    cout << ss.size() << '\n';
    cout << ss;
    return 0;
}