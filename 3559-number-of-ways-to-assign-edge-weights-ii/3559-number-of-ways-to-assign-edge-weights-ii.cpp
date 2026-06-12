
class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> pow2;
    int LOG;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[u][i - 1] == -1 ? -1 : up[up[u][i - 1]][i - 1];
            } else {
                up[u][i] = -1;
            }
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;

        adj.assign(n + 1, vector<int>());
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(1, -1, 0);

        int q = queries.size();
        vector<int> answer(q);

        for (int i = 0; i < q; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (u == v) {
                answer[i] = 0;
            } else {
                int lca = getLCA(u, v);
                int pathLength = depth[u] + depth[v] - 2 * depth[lca];
                answer[i] = pow2[pathLength - 1];
            }
        }

        return answer;
    }
};