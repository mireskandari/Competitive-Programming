#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ' '; debug_out(T...); }
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

int constexpr N = 2 * 1e5 + 10;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

bool mark[2][N + 1];
int mp[2][N];
int n;

bool check(int x, int y) {
    return (x < 2 && x >= 0 && y < n && y >= 0);
}

void dfs(int x, int y, int dix, int diy) {

    mark[x][y] = true;
    if (mp[x][y] >= 3) {
        swap(dix, diy);
        for (auto dx : {dix, -dix}) {
            for (auto dy : {diy, -diy}) {
                int nx = x + dx, ny = y + dy;
                if (nx == 1 && ny == n) mark[nx][ny] = true;
                if (check(nx, ny) && !mark[nx][ny]) {
                    dfs(nx, ny, dx, dy);
                }
            }
        }
    } else {
        int nx = x + dix, ny = y + diy;
        if (nx == 1 && ny == n) mark[nx][ny] = true;
        if (check(nx, ny) && !mark[nx][ny]) {
            dfs(nx, ny, dix, diy);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        fill(&mark[0][0], &mark[1][n] + 1, false);
        rep (0, 2, i) {
            rep (0, n, j) {
                char c;
                cin >> c;
                mp[i][j] = c - '0';
            }
        }
        dfs(0, 0, 0, 1);
        cout << (mark[1][n] ? "YES\n" : "NO\n");
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX