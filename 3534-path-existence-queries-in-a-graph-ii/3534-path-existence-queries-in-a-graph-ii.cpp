class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {nums[i], i};
        }
        sort(a.begin(), a.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[a[i].second] = i;
        }

        int K = 20; 
        vector<vector<int>> up(n, vector<int>(K));
        
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && a[r].first - a[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r - 1;
        }

        for (int j = 1; j < K; ++j) {
            for (int i = 0; i < n; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans(queries.size());
        for (int q = 0; q < queries.size(); ++q) {
            int u = queries[q][0];
            int v = queries[q][1];
            
            if (u == v) {
                ans[q] = 0;
                continue;
            }

            int p1 = pos[u];
            int p2 = pos[v];
            if (p1 > p2) swap(p1, p2);

            int curr = p1;
            int steps = 0;

            for (int j = K - 1; j >= 0; --j) {
                if (up[curr][j] < p2) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }

            if (up[curr][0] >= p2) {
                ans[q] = steps + 1;
            } else {
                ans[q] = -1;
            }
        }

        return ans;
    }
};