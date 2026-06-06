class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        int rs=0;
        for(int n:nums){
            rs+=n;
        }
        int ls=0;

        for(int i=0;i<n;i++){
            rs-=nums[i];
            ans[i]=abs(ls-rs);
            ls+=nums[i];
        }
        return ans;
    }
};