class Solution {
private:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int m = 0;
        for (int x : nums) {
            m = max(m, x);
        }

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> next_dp = dp;

            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= m; ++j) {
                    int v = dp[i][j];
                    if (v == 0) continue;

                    int ni = (i == 0) ? x : gcd(i, x);
                    next_dp[ni][j] = (next_dp[ni][j] + v) % MOD;

                    int nj = (j == 0) ? x : gcd(j, x);
                    next_dp[i][nj] = (next_dp[i][nj] + v) % MOD;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp[i][i]) % MOD;
        }

        return ans;
    }
};