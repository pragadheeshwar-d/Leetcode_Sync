class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int current_id = 0;
        
        // Populate the connected component IDs
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            comp[i] = current_id;
        }
        
        int q = queries.size();
        vector<bool> ans(q);
        
        // Answer each query in O(1)
        for (int i = 0; i < q; ++i) {
            ans[i] = (comp[queries[i][0]] == comp[queries[i][1]]);
        }
        
        return ans;
    }
};