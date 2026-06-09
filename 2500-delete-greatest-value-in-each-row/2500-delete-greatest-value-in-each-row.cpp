class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }
        
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int j = n - 1; j >= 0; --j) {
            int mx = 0;
            for (int i = 0; i < m; ++i) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        
        return ans;
    }
};