class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end());
        int b = *min_element(nums.begin(), nums.end());
        return 1LL * (a - b) * k; 
    }
};