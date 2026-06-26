#include <vector>

class Solution {
private:
    int max_val;
    std::vector<int> bit;

    void update(int idx, int val) {
        while (idx < max_val) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int s = 0;
        while (idx > 0) {
            s += bit[idx];
            idx -= idx & (-idx);
        }
        return s;
    }

public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 1;
        max_val = 2 * n + 2;
        bit.assign(max_val, 0);

        long long ans = 0;
        int current_pref = 0;

        update(0 + offset, 1);

        for (int num : nums) {
            if (num == target) {
                current_pref += 1;
            } else {
                current_pref -= 1;
            }

            ans += query(current_pref + offset - 1);
            update(current_pref + offset, 1);
        }

        return ans;
    }
};