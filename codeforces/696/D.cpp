#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr long long INF = 1e17;
constexpr int N = 1e6 + 10;

struct Mat {
	vector<vector<long long>> a;

	Mat(int sz) : a(sz, vector<long long>(sz, -INF)) {}

	vector<long long> &operator[](int x) {
		return a[x];
	}

	Mat operator*(Mat o) {
		Mat res(a.size());
		for (int i = 0; i < (int) a.size(); ++i) {
			for (int j = 0; j < (int) a.size(); ++j) {
				for (int k = 0; k < (int) a.size(); ++k) {
					res[i][j] = max(res[i][j], a[i][k] + o[k][j]);
				}
			}
		}
		return res;
	}
};

Mat power(Mat x, long long k) {
	Mat res(x.a.size());
	res.a[0][0] = 0;
	for (; k > 0; k >>= 1, x = x * x) {
		if (k & 1) {
			res = res * x;
		}
	}
	return res;
}

int n, a[N], b[N];
long long l;
int f[N], nxt[N][26], treesize = 1;

void build_aho() {
	queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (nxt[0][i]) {
			q.push(nxt[0][i]);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		a[v] += a[f[v]];
		for (int i = 0; i < 26; ++i) {
			if (nxt[v][i]) {
				f[nxt[v][i]] = nxt[f[v]][i];
				q.push(nxt[v][i]);
			} else {
				nxt[v][i] = nxt[f[v]][i];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	cin >> n >> l;
	
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int p = 0;
		for (auto &c : s) {
			if (nxt[p][c - 'a']) {
				p = nxt[p][c - 'a'];
			} else {
				nxt[p][c - 'a'] = treesize;
				p = treesize++;
			}
		}
		a[p] += b[i];
	}
	build_aho();

	Mat mat(treesize);
	for (int i = 0; i < treesize; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (nxt[i][j] == 0) {
				continue;
			}
			mat[i][nxt[i][j]] = a[nxt[i][j]];
		}
	}

	mat = power(mat, l);

	long long ans = -INF;
	for (int i = 0; i < treesize; ++i) {
		ans = max(ans, mat[0][i]);
	}
	cout << ans;
}