#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
#define cerr cerr << "debug: "

constexpr int N = 3e5 + 10;


long long fen[N << 1];

void add(int i, long long x) {
    for (++i; i < N; i += i & -i) {
        fen[i] += x;
    }
}

long long query(int i) {
    long long res = 0;
    for (++i; i > 0; i -= i & -i) {
        res += fen[i];
    }
    return res;
}

long long query(int u, int v) {
    return query(v) - query(u - 1);
}

void zerro(int i) {
    add(i, -query(i, i));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> harbs(m);
    for (auto &i : harbs) {
        cin >> i.first;
    }
    for (auto &i : harbs) {
        cin >> i.second;
    }
    sort(harbs.begin(), harbs.end());

    map<int, long long> harbours;
    for (auto [x, v] : harbs) {
        harbours[x] = v;
    }


    auto x2 = [](long long x) {
        return x <= 0 ? 0 : x * (x - 1) / 2;
    };

    for (int i = 1; i < m; ++i) {
        add(harbs[i].first, x2(harbs[i].first - harbs[i - 1].first) * harbs[i - 1].second);
    }
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            long long v;
            cin >> x >> v;
            auto p = harbours.lower_bound(x);
            int nx = p->first;
            assert(p != harbours.begin());
            if (p != harbours.begin()) {
                zerro(nx);
                add(x, x2(x - prev(p)->first) * prev(p)->second);
                add(nx, x2(nx - x) * v);
            }
            harbours[x] = v;

        } else {
            int u, v;
            cin >> u >> v;
            long long res = query(u, v);
            auto p = harbours.lower_bound(v + 1);
            auto q = harbours.lower_bound(u);
            if (q->first > v) {
              q = prev(q);
              res += q->second * (x2(p->first - u + 1) - x2(p->first - v));
            } else {
              if (p != harbours.end()) {
                res += prev(p)->second * (x2(p->first - prev(p)->first) - x2(p->first - v));
              }
              if (q != harbours.begin()) {
                q = prev(q);
                res -= q->second * (x2(next(q)->first - q->first) - x2(next(q)->first - u + 1));
              }
            }
            cout << res << '\n';
        }
    }
  return 0;
}
