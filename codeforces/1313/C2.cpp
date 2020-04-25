#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> in(n), dpl(n), dpr(n);
    vector<int> l(n), r(n);
    stack<int> s;
    rep (0, n, i) {
        cin >> in[i];
        while (!s.empty() && in[s.top()] >= in[i]) {
            s.pop();
        }
        l[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    stack<int>().swap(s);
    repr (n - 1, 0, i) {
        while (!s.empty() && in[s.top()] >= in[i]) {
            s.pop();
        }
        r[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    rep (0, n, i) {
        if (l[i] == -1) dpl[i] = (i - l[i]) * in[i];
        else dpl[i] = (i - l[i]) * in[i] + dpl[l[i]];
        int j = n - i - 1;
        if (r[j] == -1) dpr[j] = (r[j] - j) * in[j];
        else dpr[j] = (r[j] - j) * in[j] + dpr[r[j]];
    }
    ll best = 0, besti = -1;
    rep (0, n, i) {
        if (dpl[i] + dpr[i] - in[i] > best) {
            best = dpl[i] + dpr[i] - in[i];
            besti = i;
        }
    }
    repr (besti - 1, 0, i) {
        in[i] = min(in[i], in[i + 1]);
    }
    rep (besti + 1, n, i) {
        in[i] = min(in[i], in[i - 1]);
    }
    rep (0, n, i) cout << in[i] << ' ';
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX