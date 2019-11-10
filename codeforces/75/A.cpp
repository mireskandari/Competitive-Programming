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


int main(){
    fast_io;
    ull sum_, sum__;
    str a, b, sum;
    cin >> a >> b;
    sum_ = stoull(a) + stoull(b);
    sum = to_string(sum_);
    while(sum.find('0') != sum.npos) sum.erase(sum.find('0'), 1);
    while(a.find('0') != a.npos) a.erase(a.find('0'), 1);
    while(b.find('0') != b.npos) b.erase(b.find('0'), 1);
    sum__ = stoull(a) + stoull(b);
    sum_ = stoull(sum);
    // debug(sum_);
    // debug(a);
    // debug(b);
    cout << (sum_ == sum__ ? "YES" : "NO");
    return 0;
}