class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 2; i <= n; ++i) {
            for (int x = 1; x * x <= i; ++x) {
                if (i % x == 0) {
                    if (!dp[i - x]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};