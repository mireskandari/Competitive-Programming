#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> in(n);
    vector<pair<int, int>> moves;
    moves.reserve(n);
    forn (0, n, i) cin >> in[i];
    int cnt = 0;
    forn (0, n, i) {
        int besti = min_element(in.begin() + i, in.end()) - in.begin();
        if (besti != i) {
            swap(in[i], in[besti]);
            cnt++;
            moves.push_back(make_pair(i, besti));
        }
    }
    cout << cnt << '\n';
    for (auto mv : moves) {
        cout << mv.FV << ' ' << mv.SV << '\n';
    }
    return 0;
}