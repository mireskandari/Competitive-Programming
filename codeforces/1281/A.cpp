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

void solve(){
    str s;
    cin >> s;

    if(s[SZ(s)-2] == 'p' && s[SZ(s)-1] == 'o'){
        cout << "FILIPINO" << endl;
        return;
    }
    if((s[SZ(s)-4] == 'd' && s[SZ(s)-3] == 'e' && s[SZ(s)-2] == 's' && s[SZ(s)-1] == 'u') ||
    (s[SZ(s)-4] == 'm' && s[SZ(s)-3] == 'a' && s[SZ(s)-2] == 's' && s[SZ(s)-1] == 'u')){
        cout << "JAPANESE" << endl;
        return;
    }
    if(s[SZ(s)-5] == 'm' && s[SZ(s)-4] == 'n' && s[SZ(s)-3] == 'i' && s[SZ(s)-2] == 'd' && s[SZ(s)-1] == 'a'){
        cout << "KOREAN" << endl;
        return;
    }
    
}
int main(){
    fast_io;
    int N;
    cin >> N;
    while(N --){
        solve();
    }
    return 0;
}