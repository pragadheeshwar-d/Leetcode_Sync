class Solution {
public:
    char nextGreatestLetter(vector<char>& lt, char target) {
        int l=0,h=lt.size()-1;
        while(l<=h){
            int m = l +(h-l)/2;
            if(lt[m] <= target){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return lt[l%lt.size()];
    }
};