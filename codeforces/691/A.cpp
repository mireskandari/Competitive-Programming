#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << (x) << endl
#define getarr(arr, y) for(int i = 0; i < (y); i++) cin >> (arr)[i]
#define printarr(arr, y) for(int i = 0; i < (y); i++) cerr << i << " = " << (arr)[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    int n, o = 0;
    cin >> n;
    bool temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        o += (temp ? 0 : 1);
        if(o > 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << (((o == 1 and n > 1) || (o == 0 and n == 1))? "YES" : "NO");
    return 0;
}