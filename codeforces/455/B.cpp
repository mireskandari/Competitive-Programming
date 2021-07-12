#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 27 * 100010;

int n, k;
bool can_finish[N], can_remain[N];
int num[N], m;
vector<vector<int>> ch;

void add(string s) {
	int it = 0;
	for (int i = 0; i < len(s); ++i) {
		int x = s[i] - 'a';
		if (ch[it][x] == -1) {
			ch.push_back(vector<int>(27, -1));
			ch[it][x] = m;
			num[m] = x;
			++m;
		}
		it = ch[it][x];
	}
}

void dfs(int v) {
	bool has_ch = false;
	for (int i = 0; i < 27; ++i) {
		if (ch[v][i] != -1) {
			has_ch = true;
			dfs(ch[v][i]);
			if (!can_finish[ch[v][i]]) {
				can_finish[v] = true;
			}
			if (!can_remain[ch[v][i]]) {
				can_remain[v] = true;
			}
		}
	}
	if (!has_ch) {
		can_finish[v] = false;
		can_remain[v] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	m = 1;
	ch.push_back(vector<int>(27, -1));

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		add(s);
	}

	dfs(0);

	bool finish = can_finish[0], remain = can_remain[0];
	
	if (!finish) {
		cout << "Second";
		exit(0);
	}
	if (remain) {
		cout << "First";
	} else {
		cout << (k & 1 ? "First" : "Second");
	}
}