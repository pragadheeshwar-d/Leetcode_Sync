class Solution {
public:
    int cal(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int mini = 2e9, ans = 2e9;
        for (int i = 0; i < a.size(); i++) 
            mini = min(mini, a[i] + b[i]);
        for (int i = 0; i < c.size(); i++) 
            ans = min(ans, max(mini, c[i]) + d[i]);
        return ans;
    }
    int earliestFinishTime(vector<int>& lS, vector<int>& lD, vector<int>& wS, vector<int>& wD) {
        return min(cal(lS, lD, wS, wD), cal(wS, wD, lS, lD));
    }
};