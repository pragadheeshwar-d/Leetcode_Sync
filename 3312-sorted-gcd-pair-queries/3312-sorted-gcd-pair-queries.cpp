class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = 0;
        for (int num : nums) mx = max(mx, num);
        
        vector<long long> count(mx + 1, 0);
        for (int num : nums) count[num]++;
        
        vector<long long> gcdPairsCount(mx + 1, 0);
        for (int i = 1; i <= mx; ++i) {
            long long totalDivisible = 0;
            for (int j = i; j <= mx; j += i) {
                totalDivisible += count[j];
            }
            gcdPairsCount[i] = (totalDivisible * (totalDivisible - 1)) / 2;
        }
        
        for (int i = mx; i >= 1; --i) {
            for (int j = 2 * i; j <= mx; j += i) {
                gcdPairsCount[i] -= gcdPairsCount[j];
            }
        }
        
        vector<long long> prefixSum(mx + 1, 0);
        for (int i = 1; i <= mx; ++i) {
            prefixSum[i] = prefixSum[i - 1] + gcdPairsCount[i];
        }
        
        vector<int> ans;
        for (long long q : queries) {
            auto it = upper_bound(prefixSum.begin(), prefixSum.end(), q);
            ans.push_back(distance(prefixSum.begin(), it));
        }
        
        return ans;
    }
};