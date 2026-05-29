class Solution {
public:
    int minElement(vector<int>& nums) {
        int n =nums.size();
        for(int i =0;i<n;i++){
            int s=0;
            while(nums[i]>0){
                s+=nums[i]%10;
                nums[i]=nums[i]/10;
            }
            nums[i]=s;
        }
        int a = *min_element(nums.begin(),nums.end());
        return a;
    }
};