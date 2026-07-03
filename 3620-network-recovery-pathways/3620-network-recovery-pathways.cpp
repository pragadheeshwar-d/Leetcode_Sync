class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
            }
        }

        auto check = [&](int min_edge_cost) -> bool {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            vector<long long> dist(n, -1);
            
            dist[0] = 0;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > dist[u]) continue;
                if (u == n - 1) return d <= k;
                
                for (const auto& [v, cost] : adj[u]) {
                    if (cost >= min_edge_cost) {
                        if (dist[v] == -1 || d + cost < dist[v]) {
                            dist[v] = d + cost;
                            pq.push({dist[v], v});
                        }
                    }
                }
            }
            
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };

        int low = 0, high = 1e9, ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};