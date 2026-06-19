class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0;
        int c=0;
        for(int x:gain){
            c+=x;
            m=max(m,c);
        }
        return m;
    }
};