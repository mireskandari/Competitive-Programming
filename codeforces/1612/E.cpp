#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

vector<int> adj[N + 10];
int idx[N + 10], coeff[N + 10];

bool operator<(const pair<int, int> &l, const pair<int, int> &r) {
	return 1ll * l.first * r.second < 1ll * r.first * l.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> m(n), k(n);
	for (int i = 0; i < n; ++i) {
		cin >> m[i] >> k[i];
		adj[m[i]].push_back(i);
	}

	pair<int, int> best = {0, 1};
	for (int i = 0; i < 20; ++i) {
		memset(coeff, 0, sizeof(coeff));
		for (int j = 0; j < n; ++j) {
			coeff[m[j]] += min(i + 1, k[j]);
		}
		iota(idx, idx + N, 1);
		sort(idx, idx + N, [&](int l, int r) {
			return coeff[l] > coeff[r];
		});
		
		int ans = 0;
		for (int j = 0; j <= i; ++j) {
			ans += coeff[idx[j]];
		}
		if (best < make_pair(ans, i + 1)) {
			best = make_pair(ans, i + 1);
		}
	}

	memset(coeff, 0, sizeof(coeff));
	for (int i = 0; i < n; ++i) {
		coeff[m[i]] += k[i];
	}
	iota(idx, idx + N, 1);
	sort(idx, idx + N, [&](int l, int r) {
		return coeff[l] > coeff[r];
	});
	
	int up = 0;
	for (int i = 20; i < N; ++i) {
		up += coeff[idx[i]];
		if (i < 20) {
			continue;
		}
		if (best < make_pair(up, i + 1)) {
			best = make_pair(up, i + 1);
		}
	}
	
	memset(coeff, 0, sizeof(coeff));
	for (int j = 0; j < n; ++j) {
		coeff[m[j]] += min(best.second, k[j]);
	}
	iota(idx, idx + N, 1);
	sort(idx, idx + N, [&](int l, int r) {
		return coeff[l] > coeff[r];
	});

	cout << best.second << '\n';
	for (int i = 0; i < best.second; ++i) {
		cout << idx[i] << ' ';
	}
}