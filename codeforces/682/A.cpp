#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl
#define getarr(arr, y) for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

ll nn[5];
ll mm[5];
int main(){
    fast_io;
    int n, m;
    ll t = 0;
    fill(nn, nn+5, 0);
    fill(mm, mm+5, 0);
    cin >> n >> m;
    if(n < m) swap(n, m);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 5; j++){
            nn[j] += i % 5 == j ? 1 : 0;
            mm[j] += (i % 5 == j && i <= m) ? 1 : 0;
        }
    }
    // printarr(nn, 5);
    // printarr(mm, 5);
    t += nn[0] * mm[0];
    t += nn[1] * mm[4];
    t += nn[2] * mm[3];
    t += nn[3] * mm[2];
    t += nn[4] * mm[1];
    cout << t;
    return 0;
}