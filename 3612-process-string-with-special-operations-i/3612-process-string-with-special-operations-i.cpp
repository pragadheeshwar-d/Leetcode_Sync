class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } 
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (ch == '#') {
                result += result;
            } 
            else if (ch == '%') {
                int left = 0;
                int right = result.length() - 1;
                while (left < right) {
                    char temp = result[left];
                    result[left] = result[right];
                    result[right] = temp;
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};