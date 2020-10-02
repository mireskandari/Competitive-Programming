#include <bits/stdc++.h>
using namespace std;
#define long long long int
#define err(a...) fprintf(stderr, a)

int main() {
  int k;
  scanf("%d", &k);
  if (k > 2 * 18) {
    puts("-1");
    exit(0);
  }
  while (k > 1) {
    putchar('8');
    k -= 2;
  }
  if (k != 0) 
    putchar('9');
  return 0;
}
