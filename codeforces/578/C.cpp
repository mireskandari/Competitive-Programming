#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr long double EPS = 1e-7;

long double MaxSubarray(const vector<long double>& a) {
	long double best = -1e8;
	long double cur = 0.0;
	for (auto& i : a) {
		cur = max((long double) 0, cur + i);	
		best = max(best, cur);
	}
	return best;
}

long double MinSubarray(const vector<long double>& a) {
	long double best = 1e8;
	long double cur = 0.0;
	for (auto& i : a) {
		cur = min((long double) 0, cur + i);
		best = min(best, cur);
	}
	return best;
}

long double Check(const vector<long double>& a, long double x) {
	vector<long double> new_a(a.size());
	for (int i = 0; i < len(a); ++i) {
		new_a[i] = (long double) a[i] - x;
	}
	return max(abs(MaxSubarray(new_a)), abs(MinSubarray(new_a)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(6);
	int n;
	cin >> n;
	vector<long double> a(n);
	for (auto& i : a)
		cin >> i;
	long double l = -1e4 - 10, r = 1e4 + 10;
	for (int step = 0; step < 200; ++step) {
		long double m1 = l + (r - l) / 3.0;
		long double m2 = r - (r - l) / 3.0;
		if (Check(a, m1) - Check(a, m2) > EPS) {
			l = m1;
		} else {
			r = m2;
		}
	}
	cout << Check(a, l);
	return 0;
}

