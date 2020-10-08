#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 1e5 + 10;

int a[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    double low = 0, high = l;
    for (int it = 0; it < 100; ++it) {
      double mid = 0.5 * (low + high), x1, x2;
      {
        double rm = mid, last = 0, speed = 1;
        for (int i = 0; i < n; ++i) {
          double tt = (a[i] - last) / speed;
          if (tt <= rm) {
            rm -= tt;
            last = a[i];
            speed++;
          } else {
            break;
          }
        }
        last += speed * rm;
        x1 = last;
      }
      {
        double rm = mid, last = l, speed = 1;
        for (int i = n - 1; i >= 0; --i) {
          double tt = (last - a[i]) / speed;
          if (tt <= rm) {
            rm -= tt;
            last = a[i];
            speed++;
          } else {
            break;
          }
        }
        last -= speed * rm;
        x2 = last;
      }
      /*if (it == 99) {
        err("%.6lf %.6lf\n", x1, x2);
      }*/
      if (x1 < x2) {
        low = mid;
      } else {
        high = mid;
      }
    }
    printf("%.15lf\n", 0.5 * (high + low));
  }
  return 0;
}
