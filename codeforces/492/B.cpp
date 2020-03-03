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
#define set_random       mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
#define getarr(arr, y)   for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl
    
double a[1002];
int main(){
    fast_io;
    ll n;
    ld l;
    cin >> n >> l;
    // a[0] = 0;
    // a[n+1] = l;
    getarr(a, n);
    sort(a, a+n);
    ld maxx = 0;
    for(int i = 1; i < n; i ++) if(maxx < (a[i] - a[i-1]) / 2.0) maxx = (a[i] - a[i-1]) / 2.0;
    maxx = max(ld(a[0] - 0), max(l - a[n-1], maxx));
    cout << fixed << setprecision(15) << maxx;
    return 0;
}