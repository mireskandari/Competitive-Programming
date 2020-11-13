#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a)
			cin >> i;
		if (len(set<int>(a.begin(), a.end())) != n)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
	return 0;
}

