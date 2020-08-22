#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define debug(a) cerr << "fuck " << a << '\n'

typedef long long ll;

int constexpr N = 5e4 + 10;

int n;
char s[N];
int dp[N][105];
bool isin[N][105];
vector<int> pos[30];
string ans;

inline void fill_pos() {
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'].emplace_back(i);
  }
  for (int i = 0; i < 30; ++i) {
    pos[i].emplace_back(n + 100000);
  }
}

inline int get(int i, char c) {
  return *lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), i);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  n = strlen(s);
  fill_pos();
  
  fill(dp[n], dp[n] + 104, n);
  dp[n][0] = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    dp[i][0] = i - 1; dp[i][1] = i;
    isin[i][1] = true;
    for (int j = 2; j < 105; ++j) {
      int rhs = get(dp[i + 1][j - 2] + 1, s[i]);
      dp[i][j] = min(dp[i + 1][j], rhs);
      isin[i][j] = dp[i + 1][j] > rhs;
    }
  }
  
  int len;
  for (int i = 100; i >= 0; --i) {
    if (dp[0][i] < n) {
      len = i;
      break;
    }
  }
  

  int i = 0, j = len;
  char last = 0;
  while (i < n && j > 0) {
    if (isin[i][j]) {
      if (j == 1) {
        last = s[i];
        break;
      } else {
        ans += s[i];
      }
      ++i; j -= 2;
    } else {
      ++i;
    }
  }

  string tmp = ans;
  reverse(tmp.begin(), tmp.end());
  if (last) ans += last;
  ans += tmp;
  cout << ans;
  return 0;
}

