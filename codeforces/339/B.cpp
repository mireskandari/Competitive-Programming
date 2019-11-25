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

ll work[100000];
int main(){
    fast_io;
    ll n, m, now = 1, wtd, i = 0, c = 0;
    cin >> n >> m;
    getarr(work, m);
    wtd = m;
    while(wtd != 0){
        if(now != work[i]){
            int a;
            a = work[i] - now;
            now += a;
            c += a < 0 ? n + a : a;
//            cout << "hello" << endl;
        }
        if(now == work[i]){
            wtd--;
            i++;
        }
//        debug(now);
//        debug(wtd);
//        debug(c);
    }
    cout << c;
    return 0;
}

