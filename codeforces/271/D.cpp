#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 98765431, MOD1 = 1000 * 1000 * 1000 + 9, B = 37;

void add(int &a, int b, int md) {
	a += b;
	if (a >= md) {
		a -= md;
	}
}

int mult(int a, int b, int md) {
	return 1ll * a * b % md;
}

constexpr int N = 15e2 + 10;

string s;
int n;
bool bad[30];
int k;

set<pair<int, int>> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	string s;
	cin >> s;
	int n = (int) s.size();
	string bb;
	cin >> bb;
	for (int i = 0; i < 26; ++i) {
		bad[i] = 1 - (bb[i] - '0');
	}
	cin >> k;

	for (int i = 0; i < n; ++i) {
		int hsh = 0, hsh1 = 0;
		int p = 1, p1 = 1;
		int c = 0;
		for (int j = i; j < n; ++j) {
			add(hsh, mult(p, s[j] - 'a' + 1, MOD), MOD);
			add(hsh1, mult(p1, s[j] - 'a' + 1, MOD1), MOD1);
			p = mult(p, B, MOD);
			p1 = mult(p1, B, MOD1);
			if (bad[s[j] - 'a']) {
				++c;
			}
			if (c <= k) {
				st.insert({hsh, hsh1});
			}
		}
	}
	
	cout << st.size();
}