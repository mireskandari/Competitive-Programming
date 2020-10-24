#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int Wtf(char c) {
	int a = isdigit(c) ? (int)(c - '0') : ((int)(c - 'A') + 10);
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		if ((a >> i) & 1) {
			ret ^= (1 << (3 - i));
		}
	}
	return ret;
}

vector<int> GetDivs(int n) {
	vector<int> ret;
	for (int64 i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (n / i != i) {
				ret.push_back(n / i);
			}
		}
	}
	return ret;
}

constexpr int N = 5210;

int n;
int a[N][N];
int prefix[N][N];

void Init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			prefix[i][j] = prefix[i][j - 1] + a[i][j];
		}
		if (i > 1) {
			for (int j = 1; j <= n; ++j) {
				prefix[i][j] += prefix[i - 1][j];
			}
		}
	}
}
int Prefix(int i, int j, int sz) {
	return prefix[i + sz - 1][j + sz - 1] - prefix[i - 1][j + sz - 1] - prefix[i + sz - 1][j - 1] + prefix[i - 1][j - 1];
}
		
int main() {
	scanf("%d", &n);
	auto divs = GetDivs(n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; j += 4) {
			char c;
			scanf(" %c", &c);
			int ret = Wtf(c);
			for (int k = j / 4; k < j / 4 + 4; ++k) {
				a[i][j + (k - j / 4)] = (ret >> (k - j / 4)) & 1;
			}
		}
	}
/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ERR("%d ", a[i][j]);
		}
		ERR("\n");
	}
*/
	Init();
	int best = 1;
	for (auto& d : divs) {
		bool ok = true;
		for (int i = 1; i <= n; i += d) {
			for (int j = 1; j <= n; j += d) {
//				ERR("Prefix(%d, %d, %d) = %d\n", i, j, d, Prefix(i, j, d));
				if (Prefix(i, j, d) != d * d && Prefix(i, j, d) != 0) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
		if (ok) {
			best = max(best, d);
		}
	}
	printf("%d", best);
	return 0;
}
