#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

constexpr int N = 1e5 + 10, M = 101;

struct Mat {
	vector<vector<int>> a;
	
	Mat() : a(M, vector<int>(M)) {}
	
	vector<int> &operator[](int x) {
		return a[x];
	}

	Mat operator*(Mat o) {
		Mat res = Mat();
		for (int i = 0; i < M; ++i) {
			for (int k = 0; k < M; ++k) {
				for (int j = 0; j < M; ++j) {
					add(res[i][j], mult(a[i][k], o[k][j]));
				}
			}
		}
		return res;
	}
};

Mat power(Mat a, int k) {
	Mat res = Mat();
	for (int i = 0; i < M; ++i) {
		res[i][i] = 1;
	}
	for (; k; k >>= 1, a = a * a) {
		if (k & 1) {
			res = res * a;
		}
	}
	return res;
}

int n, x, dp[M], cnt[N];
Mat m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int y;
		cin >> y;
		cnt[y]++;
		m[99][100 - y]++;
		m[100][100 - y]++;
	}
	for (int i = 0; i < 99; ++i) {
		m[i][i + 1] = 1;
	}
	m[100][100]++;
	
	dp[0] = 1;
	if (x == 0) {
		cout << 1;
		exit(0);
	}
	int sum = 1;
	for (int i = 1; i < 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (i - j >= 0) {
				add(dp[i], mult(cnt[j], dp[i - j]));
			}
		}
		add(sum, dp[i]);
		if (x < 100 && i == x) {
			cout << sum;
			exit(0);
		}
	}

	m = power(m, x - 99);
	
	int ans = sum;
	for (int i = 0; i < 100; ++i) {
		add(ans, mult(m[100][i], dp[i]));
	}

	cout << ans;
}