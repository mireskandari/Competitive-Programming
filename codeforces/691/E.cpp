#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

void cor(int &a) {
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

constexpr int M = 110;

struct Mat {
	vector<vector<int>> a;

	Mat() : a(M, vector<int>(M)) {}

	vector<int> &operator[](int i) {
		return a[i];
	}

	Mat operator*(Mat o) {
		Mat res;
		for (int i = 0; i < M; ++i) {
			for (int k = 0; k < M; ++k) {
				for (int j = 0; j < M; ++j) {
					cor(res[i][j] += mult(a[i][k], o[k][j]));
				}
			}
		}
		return res;
	}
};

Mat power(Mat a, long long k) {
	Mat res;
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

int n;
long long k, a[M];
Mat mat;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) {
				mat[i][j] = 1;
			}
		}
	}
	mat = power(mat, k - 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cor(ans += mat[i][j]);
		}
	}
	cout << ans;
}