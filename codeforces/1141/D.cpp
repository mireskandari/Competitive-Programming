#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ' '; debug_out(T...); }
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef string str;
#define acm_input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(...) cerr<<"[ "<<#__VA_ARGS__<<" ]: ";debug_out(__VA_ARGS__)
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<'\n'
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<'\n'
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<'\n'

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

//vector<int>* mp;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<char> rin(n), lin(n);
    rep (0, n, i) cin >> lin[i];
    rep (0, n, i) cin >> rin[i];
    auto* lmp = new vector<int>[27];
    auto* rmp = new vector<int>[27];
    rep (0, n, i) {
        lmp[(lin[i] == '?' ? 26 : lin[i] - 'a')].push_back(i);
        rmp[(rin[i] == '?' ? 26 : rin[i] - 'a')].push_back(i);
    }
//    rep (0, 27, i) cerr << lmp[i].size() << ' ' << rmp[i].size() << '\n';
    vector<pii> ps;
    rep (0, 26, i) {
        while (!lmp[i].empty() && !rmp[i].empty()) {
            ps.emplace_back(lmp[i].back(), rmp[i].back());
            lmp[i].pop_back();
            rmp[i].pop_back();
        }
    }
    int i = 0;
    while (!lmp[26].empty() && i < 26) {
        while (!rmp[i].empty() && !lmp[26].empty()) {
            ps.emplace_back(lmp[26].back(), rmp[i].back());
            lmp[26].pop_back();
            rmp[i].pop_back();
        }
        i++;
    }
    i = 0;
    while (!rmp[26].empty() && i < 26) {
        while (!lmp[i].empty() && !rmp[26].empty()) {
            ps.emplace_back(lmp[i].back(), rmp[26].back());
            lmp[i].pop_back();
            rmp[26].pop_back();
        }
        i++;
    }
    while (!rmp[26].empty() && !lmp[26].empty()) {
        ps.emplace_back(lmp[26].back(), rmp[26].back());
        lmp[26].pop_back();
        rmp[26].pop_back();
    }
    cout << ps.size() << '\n';
    for (auto p : ps) cout << p.X + 1 << ' ' << p.Y + 1 << '\n';
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX//
// Created by mrskndri on 3/31/20.
//

