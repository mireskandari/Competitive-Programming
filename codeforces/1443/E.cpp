#include <bits/stdc++.h>
using namespace std;

#define SZ(a) ((int) a.size())
using ll = long long;

const int M = 2e5 + 10;
const int N = 16;

int f[N];
long long fact[N];
bool used[N + 1];

void MakePerm(int n, long long k) {
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i) {
		int add = k / fact[n - i - 1];
		k %= fact[n - i - 1];
		int choice = 1;
		while (used[choice] || add > 0) {
			if (!used[choice])
				--add;
			choice++;
		}
		used[choice] = true;
		f[i] = choice;
	}
}

long long Sum(int n) {
	if (n < 0) 
		return 0;
	return (1ll * n * (n + 1)) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	iota(f, f + N, 1);
	long long now = 0;
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			--l, --r;
			if (n <= N) {
				long long sum = 0;
				for (; l <= r; ++l)
					sum += f[l];
				cout << sum << '\n';
				continue;
			}
			if (r < n - N) {
				cout << Sum(r + 1) - Sum(l) << '\n';
			} else {
				long long sum = 0;
				r -= n - N;
				if (l < n - N) {
					sum += Sum(n - N) - Sum(l);
				}
				l = max(0, l - (n - N));
				sum += (r - l + 1) * (n - N);
				for (; l <= r; ++l)
					sum += f[l];
				cout << sum << '\n';
			}	
		} else {
			int x;
			cin >> x;
			now += x;
			MakePerm(min(n, N), now);
		}
	}
	return 0;
}
