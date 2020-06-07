#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector mp(n, vector(m, 0));
        set<int> ntakenr, ntakenc;
        for (int i = 0; i < n; i++) {
            ntakenr.emplace(i);
        }
        for (int j = 0; j < m; j++) {
            ntakenc.emplace(j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mp[i][j];
                if (mp[i][j]) {
                    ntakenr.erase(i);
                    ntakenc.erase(j);
                }
            }
        }
        cout << (min(size(ntakenc), size(ntakenr)) & 1 ? "Ashish" : "Vivek") << '\n';
    }
    return 0;
}