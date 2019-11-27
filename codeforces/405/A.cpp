#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << (x) << endl
#define getarr(arr, y) for(int i = 0; i < (y); i++) cin >> (arr)[i]
#define printarr(arr, y) for(int i = 0; i < (y); i++) cout << (arr)[i] << sep

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

int box[100];
int main(){
    fast_io;
    int n;
    cin >> n;
    getarr(box, n);
    sort(box, box+n);
    printarr(box, n);
    return 0;
}