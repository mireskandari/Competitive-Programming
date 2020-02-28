#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int const N = 5 * 1e5;

int const nums[] = {4, 8, 15, 16, 23, 42};
int numsr[43], in[N];
multiset<int> gs;
int n, r;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    forn(0, 6, i) numsr[nums[i]] = i;

    cin >> n;
    forn(0, n, i) {
        cin >> in[i];
        in[i] = numsr[in[i]];
    }
    forn(0, n, i) {
        if(gs.size() == 0 || gs.find(in[i] - 1) == gs.end()) {
            if(in[i] == 0) gs.insert(in[i]);
            else r++;
        }
        else {
            if(in[i] < 5){
                gs.erase(gs.find(in[i] - 1));
                gs.insert(in[i]);
            }
            else {
                gs.erase(gs.find(in[i] - 1));
            }
        }
    } 
    
    for(auto i = gs.begin(); i != gs.end(); i++) {
        r += *i + 1;
    }
    cout << r;
    return 0;
}