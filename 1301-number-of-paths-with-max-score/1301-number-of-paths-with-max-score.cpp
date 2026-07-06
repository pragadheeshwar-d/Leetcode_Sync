class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }
                
                int max_score = -1;
                int path_count = 0;
                
                vector<pair<int, int>> neighbors = {{i + 1, j}, {i, j + 1}, {i + 1, j + 1}};
                
                for (auto& neighbor : neighbors) {
                    int r = neighbor.first;
                    int c = neighbor.second;
                    
                    if (r < n && c < n && dp[r][c].first != -1) {
                        if (dp[r][c].first > max_score) {
                            max_score = dp[r][c].first;
                            path_count = dp[r][c].second;
                        } else if (dp[r][c].first == max_score) {
                            path_count = (path_count + dp[r][c].second) % MOD;
                        }
                    }
                }
                
                if (max_score != -1) {
                    int cell_value = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp[i][j] = {max_score + cell_value, path_count};
                }
            }
        }
        
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        
        return {dp[0][0].first, dp[0][0].second};
    }
};