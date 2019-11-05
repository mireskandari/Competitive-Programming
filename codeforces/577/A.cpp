#include <iostream>
using namespace std;
int main(){
    long long int n, a, t;
    cin >> n >> a;
    t = 0;
    for(int i = 1; i <= n; i++){
        if(a % i != 0){
            continue;
        }
        if(i > a){
            break;
        }
        for(int j = 1; j <= n; j++){
            if(j > a){
                break;
            }
            if(i * j == a){
                t++;
            }
        }
    }
    cout << t << endl;
}