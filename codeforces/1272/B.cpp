#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef string str;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define all(x)           (x).begin(),(x).end()
#define Sort(x)          sort(all((x)))
#define X                first
#define Y                second
#define MP               make_pair
#define pshb             push_back
#define ppb              pop_back
#define sep              ' '
#define debug(x)         cerr << #x << " = " << x << endl
#define SZ(x)            ll(x.size())
#define fast_io          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define t_set_bit        __builtin_popcount;
#define set_random       mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
#define getarr(arr, y)   for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl

void solve(){
    str dir;
    int u = 0, d = 0, l = 0, r = 0;
    cin >> dir;
    for(int i = 0; i < dir.length(); i ++){
        if(dir[i] == 'L') l ++;
        if(dir[i] == 'U') u ++;
        if(dir[i] == 'D') d ++;
        if(dir[i] == 'R') r ++;
    }
    int minn_x, minn_y;
    // debug(r);
    // debug(l);
    // debug(u);
    // debug(d);
    minn_x = min(l, r);
    minn_y = min(u, d);
    if(minn_x == 0 && minn_y > 1) minn_y = 1;
    else if(minn_y == 0 && minn_x > 1) minn_x = 1;
    cout << 2 * minn_x + 2 * minn_y << endl;
    for(int i = 0; i < minn_y; i ++) cout << 'U';
    for(int i = 0; i < minn_x; i ++) cout << 'L';
    for(int i = 0; i < minn_y; i ++) cout << 'D';
    for(int i = 0; i < minn_x; i ++) cout << 'R';
    cout << endl;
}
int main(){
    fast_io;
    int q; 
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}