class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>>s;
        for(int i = 0; i<n ; i++){
            s.push_back({score[i],i});
        }
        sort(s.rbegin(),s.rend());
        vector<string>ans(n);
        ans[s[0].second]="Gold Medal";
        if(n>1){
            ans[s[1].second]="Silver Medal";
        }
        if(n>2){
            ans[s[2].second]="Bronze Medal";
        }
        for(int i = 3; i<n;i++){
            ans[s[i].second] = to_string(i+1);
        }
        return ans;
    }
};