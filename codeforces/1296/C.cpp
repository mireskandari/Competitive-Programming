#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 3 * 1e5;
char s[N];
map<pair<int, int>, vector<int>> pos;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {

        int n;
        cin >> n >> s;
        
        pos.clear();
        // cout << s << '\n';
        pair<int, int> now = make_pair(0, 0);
        int i = -1;
        // pos[now] = vector<int>();
        pos[now].push_back(i);
        for(i = 0; i < n; i++) {
            if(s[i] == 'U') now.SV += 1;
            if(s[i] == 'D') now.SV -= 1;
            if(s[i] == 'R') now.FV += 1;
            if(s[i] == 'L') now.FV -= 1;
            // cout << now.FV << ' ' << now.SV << '\n';
            // if(pos.find(now) == pos.end()) pos[now] = vector<int>();
            pos[now].push_back(i);
        }
        int bestd = 100000000;
        pair<int, int> best;
        for(auto ps : pos) {
            sort(all(ps.SV));
            // cout << ps.FV.FV << ' ' << ps.FV.SV << '\n';
            // for(auto pp : ps.SV) cout << pp << ' ';
            // cout << '\n';
            if(ps.SV.size() > 1) {
                forn(0, ps.SV.size() - 1, i)
                    if(ps.SV[i + 1] - ps.SV[i] + 1 < bestd) {
                        bestd = ps.SV[i + 1] - ps.SV[i] + 1;
                        best = make_pair(ps.SV[i] + 1, ps.SV[i + 1]);
                    }
            }
        }
        if(bestd >= 100000000) cout << -1 << '\n';
        else cout << best.FV + 1 << ' ' << best.SV + 1 << '\n';
    }
    return 0;
}