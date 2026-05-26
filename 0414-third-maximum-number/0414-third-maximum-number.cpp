class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> distinct(nums.begin(), nums.end());
        vector<int> sorted(distinct.rbegin(), distinct.rend());
        if (sorted.size() >= 3) 
		    return sorted[2];
        return sorted[0];

    }
};