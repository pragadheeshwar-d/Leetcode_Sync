#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    int memo[101][101];
    vector<int> suffixSum;
    int solve(int i, int M, int n) {
        if (i >= n) 
            return 0;
        if (i + 2 * M >= n) 
            return suffixSum[i];
        if (memo[i][M] != 0) 
            return memo[i][M];

        int maxStones = 0;
        for (int X = 1; X <= 2 * M; ++X) {
            maxStones = max(maxStones, suffixSum[i] - solve(i + X, max(M, X), n));
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        suffixSum.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        return solve(0, 1, n);
    }
};