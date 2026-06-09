class Solution {
    int lcsrec(string& s1,string& s2,int m,int n,vector<vector<int>>& dp){
        if(n==0||m==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return dp[m][n]=1+lcsrec(s1,s2,m-1,n-1,dp);
        }
        return dp[m][n]=max(lcsrec(s1,s2,m,n-1,dp),lcsrec(s1,s2,m-1,n,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int m=s.size();
        int n=r.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        lcsrec(s,r,m,n,dp);
        return dp[m][n];
    }
};