class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s=0;
        for(int x:nums){
            s+=x;
        }
        return s%k;
    }
};