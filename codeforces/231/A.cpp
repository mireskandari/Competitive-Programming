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
    int n, t = 0;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int c = 0;
        for(int j = 0; j < 3; j ++){
            int a;
            cin >> a;
            c += a;
        }
        t += (c >= 2 ? 1 : 0);
    }
    cout << t;
    return 0;
}