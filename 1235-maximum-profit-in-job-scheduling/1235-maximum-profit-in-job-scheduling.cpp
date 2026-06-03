class Job { 
    public: 
       int start, end, profit; 
};
class Solution {
    public:

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(),
            [](const Job& a, const Job& b) {
                return a.end < b.end;
            });

        vector<int> dp(n);
        dp[0] = jobs[0].profit;

        
for (int i = 1; i < n; i++) {
            long long take = jobs[i].profit;
            int low = 0, high = i - 1, last = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (jobs[mid].end <= jobs[i].start) {
                    last = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (last != -1) 
	take += dp[last];

            dp[i] = max(dp[i - 1], (int)take);
        }
        return dp[n - 1];
    }
};
