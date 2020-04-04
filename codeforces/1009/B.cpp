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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    reverse(all(s));
    vector<pii> tz;
    int cntz = 0, cnto = 0;
    rep (0, s.size(), i) {
        if (s[i] == '0') cntz++;
        else if (s[i] == '2') {
            tz.push_back({i, cntz});
            cntz = 0;
        } else cnto++;
    }
    reverse(all(tz));
    cout << string(cntz, '0') << string(cnto, '1');
    for (auto t : tz) {
        cout << 2 << string(t.Y, '0');
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX//
// Created by mrskndri on 4/4/20.
//

