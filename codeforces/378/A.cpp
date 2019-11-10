#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl
#define getarr(arr, y) for(int i = 0; i < y; i++) cin >> arr[i]

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    int a, b, c1 = 0, c2 = 0, c3 = 0;
    cin >> a >> b;
    for(int i = 1; i <= 6; i++){
        c1 += abs(a - i) > abs(b - i) ? 1 : 0;
        c2 += abs(a - i) == abs(b - i) ? 1 : 0;
        c3 += abs(a - i) < abs(b - i) ? 1 : 0;
    }
    cout << c3 << sep << c2 << sep << c1;
    return 0;
}