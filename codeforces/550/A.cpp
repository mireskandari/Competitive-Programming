#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

char s[100001];

set<int> pos1, pos2;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> s;
    int n = strlen(s);
    bool fab = false;
    for(int i = 0; i < n - 1;) {
        if(fab && s[i] == 'B' && s[i + 1] == 'A') {
            cout << "YES";
            return 0;
        }
        if(!fab && s[i] == 'A' && s[i + 1] == 'B') {
            fab = true;
            i++;
        }
        i++;
    }
    fab = false;
    for(int i = 0; i < n - 1;) {
        if(fab && s[i] == 'A' && s[i + 1] == 'B') {
            cout << "YES";
            return 0;
        }
        if(!fab && s[i] == 'B' && s[i + 1] == 'A') {
            fab = true;
            i++;
        }
        i++;
    }
    cout << "NO";
    return 0;
}