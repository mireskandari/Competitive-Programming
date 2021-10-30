#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

void cor(int &a, const int MOD2) {
	if (a >= MOD2) {
		a -= MOD2;
	}
}

int mult(int a, int b, const int MOD2) {
	return 1ll * a * b % MOD2;
}

constexpr int M = 5;

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
					cor(res[i][j] += mult(a[i][k], o[k][j], MOD - 1), MOD - 1);
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

int power(int a, long long k) {
	int res = 1;
	for (; k; k >>= 1, a = mult(a, a, MOD)) {
		if (k & 1) {
			res = mult(res, a, MOD);
		}
	}
	return res;
}

Mat mat;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<bool> prime(1e5, true);
	for (int i = 2; i < (int) prime.size(); ++i) {
		if (prime[i]) {
			for (long long j = 1ll * i * i; j < (int) prime.size(); j += i) {
				prime[j] = false;
			}
		}
	}

	mat[0] = {0, 1, 0, 0, 0}; // f[i]
	mat[1] = {0, 0, 1, 0, 0}; // f[i + 1]
	mat[2] = {1, 1, 1, 0, 1}; // f[i + 2]
	mat[3] = {0, 0, 0, 1, 0}; // c
	mat[4] = {0, 0, 0, 2, 1}; // c ^ (2 * (i + 3) - 6)
	
	long long n;
	cin >> n;
	int f[4];
	for (int i = 0; i < 4; ++i) {
		cin >> f[i];
	}

	set<int> primes;
	for (int i = 0; i < 4; ++i) {
		int tmp = f[i];
		for (int j = 2; 1ll * j * j < f[i]; ++j) {
			if (prime[j] && tmp % j == 0) {
				primes.insert(j);
				while (tmp % j == 0) {
					tmp /= j;
				}
			}
		}
		if (tmp > 1) {
			primes.insert(tmp);
		}
	}
	
	mat = power(mat, n - 3);
	int ans = 1;
	for (auto &p : primes) {
		vector<int> base(5);
		for (int i = 0; i < 4; ++i) {
			int cnt = 0, tmp = f[i];
			while (tmp % p == 0) {
				cnt++;
				tmp /= p;
			}
			base[i] = cnt;
		}
		base[4] = 2 * base[3];
		int pwr = 0;
		for (int i = 0; i < 5; ++i) {
			cor(pwr += mult(mat[2][i], base[i], MOD - 1), MOD - 1);
		}
		ans = mult(ans, power(p, pwr), MOD);
	}

	cout << ans;
}