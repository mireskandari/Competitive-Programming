#include <bits/stdc++.h>
using namespace std;
#define long long long int
#define err(a...) fprintf(stderr, a)

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", max({a, b, c}));
  }
  return 0;
}
