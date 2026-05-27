class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> l, u, s;
        for (char c : word) {
            if (islower(c)) {
                if (u.count(toupper(c))) {
                    s.insert(c);
                }
                l.insert(c);
            } else {
                u.insert(c);
            }
        }
        int special_count = 0;
        for (char c : l) {
            if (u.count(toupper(c)) && !s.count(c)) {
                special_count++;
            }
        }
        return special_count;
    }
};