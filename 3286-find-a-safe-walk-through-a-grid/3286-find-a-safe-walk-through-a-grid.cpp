class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> min_loss(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        min_loss[0][0] = grid[0][0];
        dq.push_front({0, 0});
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    if (min_loss[r][c] + weight < min_loss[nr][nc]) {
                        min_loss[nr][nc] = min_loss[r][c] + weight;
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return health - min_loss[m - 1][n - 1] >= 1;
    }
};