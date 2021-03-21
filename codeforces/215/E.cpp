#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }


int least(long long n, int idx, vector<int> &v) {
	int sz = __lg(n) + 1;
	int ans = sz;
	for (auto d : v) {
		bool bad = false;
		for (int i = sz - d - 1; i > idx; --i) {
			if (((n >> i) & 1) != ((n >> (i + d)) & 1)) {
				bad = true;
				break;
			}
		}
		if (!bad) {
			ans = min(ans, d);
		}
	}
	return ans;
}

int least(long long n, int idx) {
	int sz = __lg(n) + 1;
	vector<int> v;
	for (int i = 1, sq = sqrt(sz); i <= sq; ++i) {
		if (sz % i == 0) {
			v.push_back(i);
			if (sz / i != i) {
				v.push_back(sz / i);
			}
		}
	}
	return least(n, idx, v);
}

long long g(long long n, int idx) {
	static int rec_level;
	rec_level++;
	//cerr << string(rec_level, ' ') << ' ' << bitset<15>(n).to_string() << ' ' << idx << '\n';
	if (n == 0) {
		return 0;
	}
	int sz = __lg(n) + 1;
	vector<int> v;
	for (int i = 1, sq = sqrt(sz); i <= sq; ++i) {
		if (sz % i == 0) {
			v.push_back(i);
			if (sz / i != i) {
				v.push_back(sz / i);
			}
		}
	}
	long long res = 1ll << (idx + 1);
	
	set<long long> tmp;
	for (auto d : v) {
		if (d == sz) {
			continue;
		}
		if (sz - 1 - idx >= d) {
			long long m = n;
			for (int i = sz - 1 - d; i >= 0; --i) {
				if ((n >> (i + d) & 1) != ((n >> i) & 1) && i > idx) {
					goto bad;
				}
				if ((m >> (i + d)) & 1) {
					m |= 1ll << i;
				} else {
					m &= ~(1ll << i);
				}
			}
			tmp.insert(m);
bad:;
		} else {
			res -= g(n >> (sz - d), idx - (sz - d));
		}
	}
	res -= len(tmp);
	//cerr << string(rec_level, ' ') << ' ' << res << '\n';
	//rec_level--;
	return res;
}

long long f(long long n) {
	if (n == 1) {
		return 0;
	}
	//cerr << "DOING SHIT " << n << '\n';
	int sz = __lg(n) + 1;
	vector<int> v;
	for (int i = 1, sq = sqrt(sz); i <= sq; ++i) {
		if (sz % i == 0) {
			v.push_back(i);
			if (sz / i != i) {
				v.push_back(sz / i);
			}
		}
	}

	long long res = n - (1ll << (sz - 1)) + 1;
	for (int i = sz - 2; i > 0; --i) {
		if ((n >> i) & 1) {
			res -= g(n ^ (1ll << i), i - 1);
		}
	}
	res -= least(n, -1, v) == sz;
	if (n & 1) {
		res -= least(n ^ 1, -1, v) == sz;
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cerr << g(0b100010000000, 5);
	long long l, r;
	cin >> l >> r;
	long long ans = 0;
	for (int i = 0, ll = __lg(r); i < ll; ++i) {
		ans += f((1ll << (i + 1)) - 1);
	}
	ans += f(r);
	if (l == 1) {
		cout << ans;
		exit(0);
	}
	for (int i = 0, ll = __lg(l - 1); i < ll; ++i) {
		ans -= f((1ll << (i + 1)) - 1);
	}
	ans -= f(l - 1);
	
	cout << ans;	
	/*int real_ans = 0;
	for (int i = 1; i < 4096; ++i) {
		if (__builtin_popcount(i) == 1) {
			real_ans = 0;
		}
		vector<int> v;
		for (int j = 1; j <= __lg(i) + 1; ++j) {
			if ((__lg(i) + 1) % j == 0) {
				v.push_back(j);
			}
		}
		real_ans += (least(i, -1, v) != __lg(i) + 1);
		long long ret = f(i);
		cerr << bitset<32>(i).to_string() << ' ' << ret << ' ' << real_ans << '\n';
		if (ret != real_ans) {
			//cout << "FUCK" << ' ' << __lg(i) + 1 << ' ' << ' ' << least(i, -1, v) << ' ' << bitset<32>(i).to_string() << ' ' << f(i) << ' ' << real_ans << '\n';
			exit(0);
		}
	}*/
}