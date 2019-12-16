#include <bits/stdc++.h>
using namespace std;

#define fast_io          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep              ' '
#define debug(x)         cerr << #x << " = " << x << endl
#define getarr(arr, y)   for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    int x = 0, y = 0, z = 0, n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        x += t1; y += t2; z += t3;
    }
    cout << (x == 0 && y == 0 && z == 0 ? "YES" : "NO");
    return 0;
}