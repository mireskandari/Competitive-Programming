#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T& a) { return a.size(); }
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int a[3] = {};
	while (s.back() == '|') {
		++a[0];
		s.pop_back();
	}
	s.pop_back();
	while (s.back() == '|') {
		++a[1];
		s.pop_back();
	}
	s.pop_back();
	while (!s.empty() && s.back() == '|') {
		++a[2];
		s.pop_back();
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			--a[i];
			++a[j];
			if (a[i] > 0 && a[0] + a[1] == a[2]) {
				cout << string(a[0], '|') << '+' << string(a[1], '|') << '=' << string(a[2], '|');
				exit(0);
			}
			++a[i];
			--a[j];
		}
	}
	cout << "Impossible";
	return 0;
}

