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
    ll n, k;
    ll all;
    
    str s, ok;
    vector<ll> pos_b;
    cin >> n >> k >> s;
    all = 0;
    for(int i = 0; i < k; i ++){
        char temp;
        cin >> temp;
        ok += temp;
    }
    pos_b.push_back(-1);
    for(int i = 0; i < n; i ++){
        if(ok.find(s[i]) == str::npos){
            pos_b.push_back(i);
        }
    }
    pos_b.push_back(s.length());
    // printarr(pos_b, pos_b.size());
    
    for(int i = 0; i < pos_b.size()-1; i ++){
        all += (pos_b[i+1] - pos_b[i] - 1) * (pos_b[i+1] - pos_b[i]) / 2;
        // debug(all);
    }
    // if(pos_b.size() > 0) all += (s.length() - pos_b[pos_b.size()-1] - 1) * (s.length() - pos_b[pos_b.size()-1]) / 2;
    cout << all;
}