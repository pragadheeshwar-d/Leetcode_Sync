#include <vector>

class Solution {
public:
    int countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> pref(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }
        
        return mergeSortAndCount(pref, 0, n);
    }

private:
    int mergeSortAndCount(std::vector<int>& pref, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = 0;
        
        count += mergeSortAndCount(pref, left, mid);
        count += mergeSortAndCount(pref, mid + 1, right);
        count += mergeAndCount(pref, left, mid, right);
        
        return count;
    }
    
    int mergeAndCount(std::vector<int>& pref, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; ++i) {
            while (j <= right && pref[j] <= pref[i]) {
                j++;
            }
            count += (right - j + 1);
        }
        
        std::vector<int> temp;
        int p1 = left, p2 = mid + 1;
        while (p1 <= mid && p2 <= right) {
            if (pref[p1] <= pref[p2]) {
                temp.push_back(pref[p1++]);
            } else {
                temp.push_back(pref[p2++]);
            }
        }
        while (p1 <= mid) 
            temp.push_back(pref[p1++]);
        while (p2 <= right) 
            temp.push_back(pref[p2++]);
        
        for (int i = 0; i < temp.size(); ++i) {
            pref[left + i] = temp[i];
        }
        
        return count;
    }
};