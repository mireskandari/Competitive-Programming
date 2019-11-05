#include <iostream>
using namespace std;

int event[100000];
int main() {
    int n, x, y;
    x = 0;
    y = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> event[i]; 
        if(event[i] > 0){
            x += event[i];
        }
        else{
            if(x == 0){
                y++;
            }
            else{
                x--;
            }
        }
    }
    cout << y << endl;
    
}