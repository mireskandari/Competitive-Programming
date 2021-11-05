#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e6 + 10, SQ = 1e3;

struct Point {
	int x, y, i;
	
	Point(int x_, int y_, int i_) : x(x_), y(y_), i(i_) {}
};

int n;
vector<Point> ps[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ps[x / SQ].push_back(Point(x, y, i));
	}
	
	vector<int> ans;

	for (int i = 0, c = 0; i < N; ++i) {
		if (ps[i].empty()) {
			continue;
		}
		if (c) {
			sort(ps[i].begin(), ps[i].end(), [](const Point &l, const Point &r) {
				return l.y > r.y;
			});
		} else {
			sort(ps[i].begin(), ps[i].end(), [](const Point &l, const Point &r) {
				return l.y < r.y;
			});
		}
		c ^= 1;
		for (auto &point : ps[i]) {
			ans.push_back(point.i);
		}
	}

	for (auto &i : ans) {
		cout << i + 1 << ' ';
	}
}