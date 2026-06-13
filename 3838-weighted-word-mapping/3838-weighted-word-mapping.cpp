class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            int t = 0;
            
            for (char c : word) {
                t += weights[c - 'a'];
            }
            
            int rem = t % 26;
            char m = 'z' - rem;
            
            result += m;
        }
        
        return result;
    }
};