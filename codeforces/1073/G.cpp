// not again
#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n;
string s;
int rnk[20][N], l;

bool cmp(int i, int j) {
	if (rnk[l - 1][i] != rnk[l - 1][j]) {
		return rnk[l - 1][i] < rnk[l - 1][j];
	}
	i += (1 << (l - 1));
	j += (1 << (l - 1));
	if (max(i, j) >= n) {
		return i > j;
	}
	return rnk[l - 1][i] < rnk[l - 1][j];
}

void build_sa() {
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int i, int j) {
		return s[i] < s[j];
	});
	rnk[0][p[0]] = 0;
	for (int i = 1; i < n; ++i) {
		rnk[0][p[i]] = rnk[0][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	}
	for (l = 1; l < 20; ++l) {
		sort(p.begin(), p.end(), cmp);
		rnk[l][p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			rnk[l][p[i]] = rnk[l][p[i - 1]] + cmp(p[i - 1], p[i]);
		}
	}
	--l;
}

int lcp(int i, int j) {
	int ret = 0;
	for (int x = max(__lg(n - i), __lg(n - j)); x >= 0; --x) {
		if (max(i, j) >= n) {
			return ret;
		}
		if (rnk[x][i] == rnk[x][j]) {
			ret += (1 << x);
			i += (1 << x);
			j += (1 << x);
		}
	}
	return ret;
}

long long calc(vector<pair<int, bool>> all) {
	long long ret = 0, sum = 0;
	int last = n;
	map<int, int> cnt;
	
	for (int i = 0; i < (int) all.size(); ++i) {
		auto &x = all[i];
		if (i) {
			auto &y = all[i - 1];
			last = min(last, lcp(x.first, y.first));
			//cerr << last << ' ' << lcp(x.first, y.first) << '\n';
		}
		long long tmp = 0;
		while (!cnt.empty() && cnt.rbegin()->first > last) {
			sum -= 1ll * cnt.rbegin()->first * cnt.rbegin()->second;
			tmp += cnt.rbegin()->second;
			cnt.erase(prev(cnt.end()));
		}
		cnt[last] += tmp;
		sum += 1ll * last * tmp;
		//cerr << sum << '\n';
		if (x.second) {
			ret += sum;
		} else {
			cnt[n - x.first]++;
			sum += (n - x.first);
			last = n - x.first;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	int q;
	cin >> q;
	cin >> s;
	
	build_sa();
	while (q--) {
		int x, y;
		cin >> x >> y;
		vector<pair<int, bool>> all;
		while (x--) {
			int a;
			cin >> a;
			all.push_back({--a, false});
		}
		while (y--) {
			int a;
			cin >> a;
			all.push_back({--a, true});
		}
		sort(all.begin(), all.end(), [&](const pair<int, bool> &i, const pair<int, bool> &j) {
			return make_pair(rnk[l][i.first], i.second) < make_pair(rnk[l][j.first], j.second);
		});
		long long ans = calc(all);
		/*for (auto &pr : all) {
			cout << "{" << pr.first << "," << pr.second << "} ";
		}
		cout << '\n';*/
		reverse(all.begin(), all.end());
		ans += calc(all);

		cout << ans << '\n';
	}
}