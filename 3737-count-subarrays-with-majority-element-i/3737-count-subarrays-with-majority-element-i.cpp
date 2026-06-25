class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(2 * n + 1, 0);
        f[n] = 1;
        
        int s = 0;
        int ans = 0;
        int cur = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                cur += f[s + n];
                s++;
            } else {
                s--;
                cur -= f[s + n];
            }
            ans += cur;
            f[s + n]++;
        }

        return ans;
    }
};