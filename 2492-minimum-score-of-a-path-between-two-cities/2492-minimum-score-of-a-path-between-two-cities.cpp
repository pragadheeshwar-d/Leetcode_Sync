class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        queue<int> q;
        vector<bool> visited(n + 1, false);
        int min_score = INT_MAX;
        
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (const auto& [neighbor, distance] : graph[curr]) {
                min_score = min(min_score, distance);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return min_score;
    }
};