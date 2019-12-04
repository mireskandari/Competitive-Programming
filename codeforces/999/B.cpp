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
typedef string str;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

vector<int> div(int n){
    vector<int> divis;
    for(int i = 1; i <= n / 2; i++){
        if(n % i == 0) divis.pshb(i);
    }
    divis.pshb(n);
    return divis;
}

int main(){
    fast_io;
    int n;
    str t;
    cin >> n >> t;
    vector<int> divis = div(n);
    for(auto div : divis){
        reverse(t.begin(), t.begin() + div);
    }
    cout << t;
    return 0;
}