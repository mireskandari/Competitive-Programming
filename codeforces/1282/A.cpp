#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("O2")

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
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define FOR(x, y, z) for(int z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;

int MAIN(){
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if(a > b) swap(a, b);
    pii ra(c - r, c + r);
    if(ra.Y > b) ra.Y = b;
    if(ra.X < a) ra.X = a;
    debugp(ra);
    cout << (b - a) - (ra.Y - ra.X > 0 ? ra.Y - ra.X : 0) << endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        MAIN();
    }
    return 0;
}