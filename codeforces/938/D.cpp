#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n, m;
        cin >> n >> m;
        
        vector<vector<pair<int, long long>>> g(n);
        for (int i = 0; i < m; ++i) {
                int v, u;
                long long w;
                cin >> v >> u >> w;
                w *= 2;
                g[--v].push_back({--u, w});
                g[u].push_back({v, w});
        }
        
        vector<long long> dist(n);
        for (int i = 0; i < n; ++i) {
                cin >> dist[i];
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < n; ++i) {
                pq.push({dist[i], i});
        }
        
        while (!pq.empty()) {
                int v = pq.top().second;
                long long d = pq.top().first;
                pq.pop();
                if (d != dist[v]) {
                        continue;
                }
                
                for (auto &e : g[v]) {
                        int u = e.first;
                        long long w = e.second;
                        if (dist[u] > dist[v] + w) {
                                dist[u] = dist[v] + w;
                                pq.push({dist[u], u});
                        }
                }
        }
        
        for (int i = 0; i < n; ++i) {
                cout << dist[i] << ' ';
        }
}