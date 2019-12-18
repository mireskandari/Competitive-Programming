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

vector<int> nx;
int main(){
    fast_io;
    int n;
    str a;
    cin >> n >> a;
    nx.push_back(-1);
    for(int i = 0; i < n; i ++){
        if(a[i] != 'x') nx.push_back(i);
    }
    int t = 0;
    nx.push_back(n);
    for(int i = 1; i < nx.size(); i ++){
        t += (nx[i] - nx[i-1] - 1 >= 3 ? nx[i] - nx[i-1] - 1 - 2 : 0);
    }
    cout << t;
    return 0;
}