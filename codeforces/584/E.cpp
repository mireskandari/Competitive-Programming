#include <bits/stdc++.h>

#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2000 + 100;

int n, p[N], q[N];

vector <pii> sw;

int a[N];

void f(){
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j <= a[i]; ++j){
			if(a[j] <= i){
				swap(p[i], p[j]);
				sw.PB(MP(i, j));
				swap(a[i], a[j]);
			}
		}
	}
}

bool g(){
	for(int i = 0; i < n; ++i)
		if(p[i] != q[i]) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> p[i];
	for(int i = 0; i < n; ++i) cin >> q[i];
	ll ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(p[i] == q[j])
				ans += abs(i - j), a[i] = j;
	cout << ans / 2 << "\n";
	for (int i = 0; i < 5000; i++) {
    f();
  }
	cout << SZ(sw) << "\n";
	for(int i = 0; i < SZ(sw); ++i){
		cout << sw[i].X + 1 << " " << sw[i].Y + 1 << "\n";
	}
	return 0;
}

