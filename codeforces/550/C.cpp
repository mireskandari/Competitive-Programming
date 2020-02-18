#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

string divs[1000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int sd = 0;
    for(int i = 0; i < 1000; i += 8, sd++) {
        divs[sd] = to_string(i);
        // cout << divs[sd] << '\n';
    }
    string n;
    cin >> n;
    forn(0, sd, i) {
        int index = 0;
        forn(0, n.size(), j) {
            if(n[j] == divs[i][index]) {
                if(index == divs[i].size() - 1) {
                    cout << "YES\n" << divs[i];
                    return 0;
                }
                else {
                    index++;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}