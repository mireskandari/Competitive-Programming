#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

char s1[10001], s2[10001];
pair<char, char> nequal[10001];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {

        int n, t = 0;
        // pair<char, char> nequal;
        cin >> n >> s1 >> s2;
        forn(0, n, i) {
            if(s1[i] != s2[i]) {
                nequal[t] = make_pair(s1[i], s2[i]);
                t++;
            }
        }
        if(t == 2 && nequal[0] == nequal[1]) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}