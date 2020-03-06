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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> b(n);
    forn (0, n, i) cin >> b[i];
    cin >> m;
    vector<int> g(m);
    forn (0, m, i) cin >> g[i];


    sort(all(b));
    sort(all(g));
    int i, j, t = 0;
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if (abs(b[i] - g[j]) <= 1) {
                t++;
                g[j] = 999999;
                break;
            }
        }
    }
    cout << t;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX