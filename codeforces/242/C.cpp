#include <bits/stdc++.h>

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int x0, y0, x1, y1;
        std::cin >> x0 >> y0 >> x1 >> y1;
        
        int n;
        std::cin >> n;
        
        std::set<std::pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
                int a, b, r;
                std::cin >> r >> a >> b;
                for (int j = a; j <= b; ++j) {
                        st.insert({r, j});
                }
        }
        
        std::set<std::pair<long long, std::pair<int, int>>> pq;
        std::map<std::pair<int, int>, long long> dist;
       	std::set<std::pair<int, int>> used;

        pq.insert({0, {x0, y0}});
        dist[{x0, y0}] = 0;
        used.insert({x0, y0});

        auto change = [&](long long d, std::pair<int, int> v) {
                if (!st.count(v) || used.count(v)) {
                        return;
                }
                if (!dist.count(v)) {
                        dist[v] = d + 1;
                        pq.insert({d + 1, v});
                } else if (dist[v] > d + 1) {
                        pq.erase({dist[v], v});
                        dist[v] = d + 1;
                        pq.insert({d + 1, v});
                }
        };

        while (!pq.empty()) {
                int x = pq.begin()->second.first;
                int y = pq.begin()->second.second;
                long long d = pq.begin()->first;
                pq.erase(pq.begin());

		if (x == x1 && y == y1) {
			std::cout << d;
			std::exit(0);
		}

                for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                                if (i != 0 || j != 0) {
                                        change(d, {x + i, y + j});
                                }
                        }
                }
        }

	std::cout << -1;
}
