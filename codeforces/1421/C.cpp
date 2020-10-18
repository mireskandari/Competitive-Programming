#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

int main() {
  static char s[112345];
  scanf("%s", s);
  int n = (int) strlen(s);
  printf("3\nL %d\nR %d\nR %d", n - 1, n - 1, 2 * n - 1);
  return 0;
}
