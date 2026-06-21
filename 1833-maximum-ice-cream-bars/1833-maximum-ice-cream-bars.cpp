class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(), costs.end());
        vector<int> f(m + 1, 0);
        for (int x : costs) {
            f[x]++;
        }
        
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            if (f[i] > 0) {
                int buy = min(f[i], coins / i);
                ans += buy;
                coins -= buy * i;
                if (buy == 0) break;
            }
        }
        return ans;
    }
};