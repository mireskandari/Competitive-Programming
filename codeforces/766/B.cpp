#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define FOR(x, y, z) for(int z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)

vector<int> edge;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    edge.resize(n);
    FOR (0, n, i) cin >> edge[i];
    sort(all(edge));
    FOR (0, n - 2, i){
        if (edge[i] + edge[i + 1] > edge[i + 2] &&
            edge[i + 1] + edge[i + 2] > edge[i] &&
            edge[i] + edge[i + 2] > edge[i + 1]){

                cout << "YES";
                return 0;
            }
    }
    cout << "NO";
    return 0;
}