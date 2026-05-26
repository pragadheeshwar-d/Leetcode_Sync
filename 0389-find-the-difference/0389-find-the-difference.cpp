class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (v[t[i] - 'a'] == 0) {
                return t[i];
            }
            v[t[i] - 'a']--;
        }
        return ' ';
    }
};