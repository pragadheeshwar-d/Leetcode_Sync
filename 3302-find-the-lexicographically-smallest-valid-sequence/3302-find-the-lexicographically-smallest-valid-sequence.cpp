class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> last(m, -1);
        int p = m - 1;
        for (int i=n-1;i>=0&&p>=0;--i) {
            if (word1[i] == word2[p]) {
                last[p] = i;
                p--;
            }
        }
        vector<int> ans;
        bool used = false;
        int j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!used) {
                if (j == m - 1 || last[j + 1] > i) {
                    ans.push_back(i);
                    used = true;
                    j++;
                }
            }
        }
        return ans.size() == m ? ans : vector<int>();
    }
};