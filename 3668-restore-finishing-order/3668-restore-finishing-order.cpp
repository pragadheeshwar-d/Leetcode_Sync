class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>s(friends.begin(),friends.end());
        vector<int>r;
        for(int n:order){
            if(s.count(n)){
                r.push_back(n);
            }
        }
        return r;
    }
};