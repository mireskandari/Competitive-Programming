// godfather of debugging

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

template <class T> 
int size(const T& a) { return a.size(); }
using ll = long long;

void Unique(vector<int>& a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
}

void FixSegs(vector<pair<int, int>>& a) {
	vector<pair<int, int>> ps(2 * size(a));
	for (int i = 0; i < size(ps); i += 2) {
		ps[i] = {a[i >> 1].first, 0};
		ps[i + 1] = {a[i >> 1].second, 1};
	}
	sort(ps.begin(), ps.end());
	vector<pair<int, int>> nw;
	int open = 0;
	int loc;
	for (auto& p : ps) {
		if (p.second == 0) {
			if (open > 0) {
				if (p.first - 1 >= loc)
					nw.emplace_back(loc, p.first - 1);
			}
			loc = p.first;
			open++;
		} else {
			nw.emplace_back(loc, p.first);
			open--;
			if (open > 0)
				loc = p.first + 1;
		}
	}
	sort(nw.begin(), nw.end());
	nw.resize(unique(nw.begin(), nw.end()) - nw.begin());
	swap(a, nw);}

const int N = 1e6 + 10;

int fen[N];

void Update(int i, int add) {
	for (++i; i < N; i += i & -i)
		fen[i] += add;
}

int Query(int i) {
	int ret = 0;
	for (++i; i > 0; i -= i & -i)
		ret += fen[i];
	return ret;
}

int Query(int u, int v) {
	return Query(v) - Query(u - 1);
}

int a[N][2][2];
vector<pair<int, int>> by_x[N];
vector<pair<int, int>> by_y[N];

int main() {
	int n;
	scanf("%d", &n);
	
	vector<int> x_axis, y_axis;
	for (int i = 0; i < n; ++i) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		a[i][0][0] = x;
		a[i][0][1] = y;
		a[i][1][0] = xx;
		a[i][1][1] = yy;
		x_axis.push_back(x);
		x_axis.push_back(xx);
		y_axis.push_back(y);
		y_axis.push_back(yy);
	}	
	Unique(x_axis);
	Unique(y_axis);

	for (int i = 0; i < n; ++i) {
		if (a[i][0][0] == a[i][1][0]) {
			int x = lower_bound(x_axis.begin(), x_axis.end(), a[i][0][0]) - x_axis.begin();
			by_x[x].emplace_back(min(a[i][0][1], a[i][1][1]), max(a[i][0][1], a[i][1][1]));
		} else {
			int y = lower_bound(y_axis.begin(), y_axis.end(), a[i][0][1]) - y_axis.begin();
			by_y[y].emplace_back(min(a[i][0][0], a[i][1][0]), max(a[i][0][0], a[i][1][0]));
		}
	}
	
	ll total = 0;
	
//	puts("horizontal");
	for (int i = 0; i < N; ++i) {
		if (!by_x[i].empty()) {
			FixSegs(by_x[i]);
			for (auto& p : by_x[i]) {
//				printf("%d %d %d\n", i, p.first, p.second);
				total += p.second - p.first + 1;
				p.first = lower_bound(y_axis.begin(), y_axis.end(), p.first) - y_axis.begin();
				p.second = lower_bound(y_axis.begin(), y_axis.end(), p.second) - y_axis.begin();
			}
		}
	}
//	puts("vertical");
	for (int i = 0; i < N; ++i) {
		if (!by_y[i].empty()) {
			FixSegs(by_y[i]);
			for (auto& p : by_y[i]) {
//				printf("%d %d %d\n", i, p.first, p.second);
				total += p.second - p.first + 1;
				p.first = lower_bound(x_axis.begin(), x_axis.end(), p.first) - x_axis.begin();
				p.second = lower_bound(x_axis.begin(), x_axis.end(), p.second) - x_axis.begin();
			}
		}
	}
	
	vector<tuple<int, int, int>> all; // second arg is (open, horizontal, close)
	for (int i = 0; i < N; ++i) {
		if (!by_x[i].empty())
			all.emplace_back(i, 1, -1);
	}
	for (int i = 0; i < N; ++i) {
		for (auto& p : by_y[i]) {
			all.emplace_back(p.first, 0, i);
			all.emplace_back(p.second, 2, i);
		}
	}
	sort(all.begin(), all.end());
	
	ll inter = 0;

	for (auto& p : all) {
		int x, type, y;
		tie(x, type, y) = p;
		if (type == 0) {
			Update(y, 1);
		} else if (type == 1) {
			for (auto& p : by_x[x])
				inter += Query(p.first, p.second);
		} else {
			Update(y, -1);
		}
	}

	printf("%lld", total - inter);
	return 0;
}
