#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
typedef long double ld;

namespace cool_bullshit {

void computeLPSArray(int* pat, int M, int* lps); 
  
// Prints occurrences of txt[] in pat[] 
int KMPSearch(int N, int M, int* pat, int* txt) 
{ 
  int cnt = 0;

  // create lps[] that will hold the longest prefix suffix 
  // values for pattern 
  int lps[M]; 
  
  // Preprocess the pattern (calculate lps[] array) 
  computeLPSArray(pat, M, lps); 
  
  int i = 0; // index for txt[] 
  int j = 0; // index for pat[] 
  while (i < N) { 
    if (pat[j] == txt[i]) { 
      j++; 
      i++; 
    } 
  
    if (j == M) { 
      cnt++;
      j = lps[j - 1]; 
    } 
  
    // mismatch after j matches 
    else if (i < N && pat[j] != txt[i]) { 
      // Do not match lps[0..lps[j-1]] intacters, 
      // they will match anyway 
      if (j != 0) 
        j = lps[j - 1]; 
      else
        i = i + 1; 
    } 
  } 
  return cnt;
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(int* pat, int M, int* lps) 
{ 
  // length of the previous longest prefix suffix 
  int len = 0; 
  
  lps[0] = 0; // lps[0] is always 0 
  
  // the loop calculates lps[i] for i = 1 to M-1 
  int i = 1; 
  while (i < M) { 
    if (pat[i] == pat[len]) { 
      len++; 
      lps[i] = len; 
      i++; 
    } 
    else // (pat[i] != pat[len]) 
    { 
      // This is tricky. Consider the example. 
      // AAACAAAA and i = 7. The idea is similar 
      // to search step. 
      if (len != 0) { 
        len = lps[len - 1]; 
  
        // Also, note that we do not increment 
        // i here 
      } 
      else // if (len == 0) 
      { 
        lps[i] = 0; 
        i++; 
      } 
    } 
  } 
} 

} // cool_bullshit

using cool_bullshit::KMPSearch;

int constexpr N = 2e5 + 10;

int pat[N], a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> b(w);
  for (auto &i : b) cin >> i;
  if (w > n) {
    cout << 0;
    return 0;
  }
  if (w == 1) {
    cout << n;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    a[i] = c[i + 1] - c[i];
  }
  for (int i = 0; i < w - 1; i++) {
    pat[i] = b[i + 1] - b[i];
  }
  cout << KMPSearch(n - 1, w - 1, pat, a);
  return 0;
}
