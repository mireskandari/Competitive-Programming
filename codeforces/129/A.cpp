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
    int n, t1 = 0, t2 = 0, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        t1 += temp % 2 == 0 ? 1 : 0;
        t2 += temp % 2 != 0 ? 1 : 0;
    }
    cout << (t2 % 2 == 0 ? t1 : t2);
    return 0;
}