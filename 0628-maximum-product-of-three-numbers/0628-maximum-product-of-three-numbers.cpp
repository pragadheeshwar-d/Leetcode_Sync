#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int option1 = nums[0] * nums[1] * nums[2];
        int option2 = nums[n - 1] * nums[n - 2] * nums[0];
        return max(option1, option2);
    }
};