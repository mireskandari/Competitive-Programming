#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr int N = 2e5 + 10;

int a[N], start[N];
int ptr[2], cnt[2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  set<int> used;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    start[i] = a[i];
    if (used.count(a[i])) {
      a[i] = -1;
    } else {
      used.insert(a[i]);
      cnt[a[i] % 2]++;
    }
  }
  ptr[0] = 2, ptr[1] = 1;
  auto update = [&](int &pointer) {
    while (pointer <= m && used.count(pointer) == 1) {
      pointer += 2;
    }
    if (pointer > m) {
      puts("-1");
      exit(0);
    }
  };
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      int who = cnt[0] < cnt[1] ? 0 : 1;
      update(ptr[who]);
      cnt[who]++;
      a[i] = ptr[who];
      used.insert(a[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    int who = a[i] % 2;
    if (cnt[who] > cnt[1 - who]) {
      who = 1 - who;
      update(ptr[who]);
      cnt[who]++;
      cnt[1 - who]--;
      a[i] = ptr[who];
      used.insert(a[i]);
    }
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != start[i]) ++answer;
  }
  printf("%d\n", answer);
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
