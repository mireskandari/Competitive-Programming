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
    vector<ll> in(n);
    stack<ll> s;
    vector<ll> sz(n);
    rep (0, n, i) {
        cin >> in[i];
        while (!s.empty() && in[s.top()] >= in[i]) {
            s.pop();
        }
        sz[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    s = stack<ll>();
    repr (n - 1, 0, i) {
        while (!s.empty() && in[s.top()] >= in[i]) {
            s.pop();
        }
        sz[i] = (s.empty() ? n - 1 : s.top() - 1) - sz[i];
        s.push(i);
    }
    vector<ll> mx(n + 1, 0);
    rep (0, n, i) {
        mx[sz[i]] = max(mx[sz[i]], in[i]);
    }
    repr (n - 1, 1, i) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    rep (1, n + 1, i) {
        cout << mx[i] << ' ';
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX