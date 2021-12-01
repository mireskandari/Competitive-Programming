#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		long long x1, x2, p1, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		string s1, s2;
		while (x1 > 0) {
			s1 += (char) (x1 % 10 + '0');
			x1 /= 10;
		}
		while (x2 > 0) {
			s2 += (char) (x2 % 10 + '0');
			x2 /= 10;
		}
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		if (s1.size() + p1 != s2.size() + p2) {
			cout << (s1.size() + p1 < s2.size() + p2 ? "<\n" : ">\n");
			continue;
		}
		if (s1.size() < s2.size()) {
			int c = s2.size() - s1.size();
			for (int i = 0; i < min<int>(p1, c); ++i) {
				s1 += '0';
			}
		} else {
			int c = s1.size() - s2.size();
			for (int i = 0; i < min<int>(p2, c); ++i) {
				s2 += '0';
			}
		}
		if (s1 == s2) {
			cout << "=\n";
		} else {
			cout << (s1 < s2 ? "<\n" : ">\n");
		}
	}
}