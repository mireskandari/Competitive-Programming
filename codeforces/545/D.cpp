#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define FV first
#define SV second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define forrn(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;

int constexpr N = 1e5;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n, cnt = 0;
    ll tp = 0;
    deque<int> q;
    cin >> n;
    forn (0, n, i) {
        int t; cin >> t;
        q.push_back(t);
    }
    sort(all(q));
    while (!q.empty()) {
        if (q[0] >= tp) { 
            cnt++;
            tp += q[0];
        }
        q.pop_front();
    }
    cout << cnt;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX