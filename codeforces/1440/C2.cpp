#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 110;
constexpr int SUM = '0' + '1';

char a[N][N];
int n, m;
using T = tuple<int, int, int, int, int, int>;
vector<T> ans;

void Move(const T& m) {
	ans.push_back(m);
	int x[3], y[3];
	tie(x[0], y[0], x[1], y[1], x[2], y[2]) = m;
	--x[0], --y[0], --x[1], --y[1], --x[2], --y[2];
	a[x[0]][y[0]] = SUM - a[x[0]][y[0]];
	a[x[1]][y[1]] = SUM - a[x[1]][y[1]];
	a[x[2]][y[2]] = SUM - a[x[2]][y[2]];
}

void Solve1(int x, int y) {
	vector<vector<int>> tt;
	if (a[x][y] == '1') {
		tt = {{x + 1, y + 1}, {x + 1, y + 2}, {x + 2, y + 2}, {x + 2, y + 1}};
	} else if (a[x][y + 1] == '1') {
		tt = {{x + 1, y + 2}, {x + 2, y + 2}, {x + 2, y + 1}, {x + 1, y + 1}};
	} else if (a[x + 1][y + 1] == '1') {
		tt = {{x + 2, y + 2}, {x + 2, y + 1}, {x + 1, y + 1}, {x + 1, y + 2}};
	} else {
		tt = {{x + 2, y + 1}, {x + 1, y + 1}, {x + 1, y + 2}, {x + 2, y + 2}};
	}
	Move(make_tuple(tt[0][0], tt[0][1], tt[1][0], tt[1][1], tt[2][0], tt[2][1]));
	Move(make_tuple(tt[0][0], tt[0][1], tt[2][0], tt[2][1], tt[3][0], tt[3][1]));
	Move(make_tuple(tt[0][0], tt[0][1], tt[1][0], tt[1][1], tt[3][0], tt[3][1]));
}

void Solve4(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 2; ++i) {
		for (int j = y; j < y + 2; ++j) {
			if (a[i][j] == '1')
				cnt++;
		}
	}
	if (cnt == 0) {
		return;
	} else if (cnt == 1) {
		Solve1(x, y);
	} else if (cnt == 2) {
		if (a[x][y] == '1' && a[x + 1][y + 1] == '1') {
			Move(make_tuple(x + 1, y + 1, x + 1, y + 2, x + 2, y + 2));
			Solve1(x, y);
			return;
		}
		if (a[x + 1][y] == '1' && a[x][y + 1] == '1') {
			Move(make_tuple(x + 1, y + 2, x + 2, y + 2, x + 2, y + 1));
			Solve1(x, y);
			return;
		}
		if (a[x][y] == '1' && a[x + 1][y] == '1') {
			Move(make_tuple(x + 1, y + 1, x + 2, y + 1, x + 2, y + 2));
		} else if (a[x][y] == '1' && a[x][y + 1] == '1') {
			Move(make_tuple(x + 1, y + 1, x + 1, y + 2, x + 2, y + 2));
		} else if (a[x + 1][y] == '1' && a[x + 1][y + 1] == '1') {
			Move(make_tuple(x + 1, y + 2, x + 2, y + 2, x + 2, y + 1));
		} else {
			Move(make_tuple(x + 1, y + 2, x + 2, y + 2, x + 2, y + 1));
		}
		Solve1(x, y);
	} else if (cnt == 3) {
		if (a[x][y] == '0') {
			Move(make_tuple(x + 1, y + 2, x + 2, y + 2, x + 2, y + 1));
		} else if (a[x + 1][y] == '0') {
			Move(make_tuple(x + 1, y + 1, x + 1, y + 2, x + 2, y + 2));
		} else if (a[x + 1][y + 1] == '0') {
			Move(make_tuple(x + 1, y + 1, x + 2, y + 1, x + 1, y + 2));
		} else {
			Move(make_tuple(x + 1, y + 1, x + 2, y + 1, x + 2, y + 2));
		}	
	} else {
		Move(make_tuple(x + 1, y + 1, x + 1, y + 2, x + 2, y + 2));
		Solve1(x, y);
	}
}

void SolveRow(int x, int y, int l) {
	for (int j = y; j < y + l - 1; ++j) {
		if (a[x][j] == '1') {
			Move(make_tuple(x + 1, j + 1, x + 2, y + 1, x + 2, y + 2));
		}
	}
	if (a[x][y + l - 1] == '1') {
		Move(make_tuple(x + 1, y + l - 1 + 1, x + 2, y + l - 1 + 1, x + 2, y + l - 1));
	}
}

void SolveCol(int x, int y, int l) {
	for (int i = x; i < x + l - 1; ++i) {
		if (a[i][y] == '1') {
			Move(make_tuple(i + 1, y + 1, i + 2, y + 1, i + 2, y + 2));
		}
	}
	if (a[x + l - 1][y] == '1') {
		Move(make_tuple(x + l - 1 + 1, y + 1, x + l - 1 + 1, y + 2, x + l - 1, y + 2));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		ans.clear();
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < m - 2; ++i) {
			SolveCol(0, i, n);
		}
		for (int i = 0; i < n - 2; ++i) {
			SolveRow(i, m - 2, 2);
		}
		Solve4(n - 2, m - 2);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == '1') 
					++cnt;
			}
		}
		assert(len(ans) <= n * m);
		cout << len(ans) << '\n';
		for (auto& aa : ans) {
			int x[3], y[3];
			tie(x[0], y[0], x[1], y[1], x[2], y[2]) = aa;
			cout << x[0] << ' ' << y[0] << ' ' << x[1] << ' ' << y[1] << ' ' << x[2] << ' ' << y[2] << '\n';
		}
		assert(cnt == 0);
	}
	return 0;
}

