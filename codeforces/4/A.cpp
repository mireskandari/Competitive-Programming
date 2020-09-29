#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if ((n - 2) % 2 != 0 || n == 2) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}