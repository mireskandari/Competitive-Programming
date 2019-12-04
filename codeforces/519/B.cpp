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
#define printarr(arr, y) for(auto ar : arr) cerr << " = " << ar << endl

int main(){
    fast_io;
    int n, temp;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a.pshb(temp);
    }
    for(int i = 0; i < n-1; i++){
        cin >> temp;
        b.pshb(temp);
        a.erase(find(all(a), temp));
    }
    for(int i = 0; i < n-2; i++){
        cin >> temp;
        b.erase(find(all(b), temp));
    }
    cout << *(a.begin()) << endl << *(b.begin());
    return 0;
}