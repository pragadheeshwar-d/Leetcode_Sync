class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) count[c - 'a']++;
        
        string res = "";
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;
            
            while (!res.empty() && res.back() > c && count[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return res;
    }
};