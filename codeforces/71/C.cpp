#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define err(a...) fprintf(stderr, a)

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  auto Check = [&, n](int x) {
    for (int i = 0; i < x; ++i) {
      bool ok = true;
      int cnt = 0;
      for (int j = i; j < n; j += x) {
        if (a[j] == 0) {
          ok = false;
          break;
        }
        ++cnt;
        if (j + x >= n) {
          if ((j + x) % n != i) {
            ok = false;
            break;
          }
        }
      }
      if (ok && cnt > 2) {
        return true;
      }
    }
    return false;
  };
  auto Bye = [](bool b) {
    if (b) {
      puts("YES");
      exit(0);
    }
  };
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      Bye(Check(i));
      if (i * i != n) Bye(Check(n / i));
    }
  }
  puts("NO");
  return 0;
}