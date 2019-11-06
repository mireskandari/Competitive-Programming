#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;
typedef string str;

int a, b, q, n;
ll s;
str ans[10000];
int main(){
    fast_io;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b >> n >> s;
        if(a >= (s / n)){
            ans[i] = (s - ((s / n) * n)) <= b ? "YES" : "NO";
        }
        else{
            ans[i] = (s - (a * n)) <= b ? "YES" : "NO";
        }
        
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }

    return 0;
}