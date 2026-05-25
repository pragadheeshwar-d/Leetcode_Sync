class Solution {
public:
    int finalValueAfterOperations(vector<string>& o) {
        int s=0;
        for(auto x:o)
            s+=(x[1]=='+'? 1:-1);
        return s;
    }
};