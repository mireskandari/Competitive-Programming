#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int n, n_, p, t;
    int m;
    cin >> n;
    n_ = n;
    m = 0;
    t = 0;
    p = 1;
    while(n_ != 0){
        m++;
        n_ /= 10;
    }

    for(int i = 1; i < m; i++){
        t += 9 * p * i;
        p *= 10;
        // cout << t << endl;
        // cout << p << endl;
    }
    t += (n - p + 1) * m;

    cout << t << endl;
}