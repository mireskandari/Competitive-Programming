#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 300;

int n, a[N], c[N];
deque<int> d[N], b[N];

int pop(int i) {
	if (d[i].back() == b[i].back()) {
		d[i].pop_back();
	}
	int x = b[i].back();
	b[i].pop_back();
	return x;
}

void push(int i, int x) {
	while (!d[i].empty() && a[d[i].front()] <= a[x]) {
		d[i].pop_front();
	}
	d[i].push_front(x);
}

void recalc(int i) {
	d[i].clear();
	for (int j = (int) b[i].size() - 1; j >= 0; --j) {
		push(i, b[i][j]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> c[i];
	}

	int en = 0;
	push(0, 0);
	b[0].push_back(0);
	for (int i = 1; i < n; ++i) {
		int j = en, nowc = 0;
		while (j >= 0 && a[d[j].back()] <= a[i] && nowc + (int) b[j].size() < c[i]) {
			nowc += (int) b[j].size();
			--j;
		}
		
		int start;
		if (j < 0) {
			push(0, i);
			b[0].push_front(i);
			start = 1;
		} else {
			int pos = (int) b[j].size();
			for (int x = (int) b[j].size() - 1; x >= 0; --x) {
				if (a[b[j][x]] > a[i] || nowc + 1 > c[i]) {
					break;
				}
				nowc++;
				--pos;
			}
			b[j].insert(b[j].begin() + pos, i);
			recalc(j);
			start = j + 1;
		}
		for (int x = start, lm = ((i + SQ - 1) / SQ) + 1; x < lm; ++x) {
			if ((int) b[x - 1].size() > SQ) {
				int y = pop(x - 1);
				push(x, y);
				b[x].push_front(y);
			} else {
				break;
			}
		}
		en = i / SQ;
		//cerr << a[d[0].back()] << ' ' << j << "\n\n";
	}

	for (int i = 0; i < n; ++i) {
		for (auto &j : b[i]) {
			cout << j + 1 << ' ';
		}
	}
}