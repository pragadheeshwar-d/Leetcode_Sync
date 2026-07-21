#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int a = 0;
        for (char c : s) {
            if (c == '1') a++;
        }

        string t = "1" + s + "1";
        vector<pair<char, int>> b;
        int n = t.length();
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) {
                j++;
            }
            b.push_back({t[i], j - i});
            i = j;
        }

        int c = 0;
        int m = b.size();

        for (int k = 1; k < m - 1; k++) {
            if (b[k].first == '1') {
                int d = b[k - 1].second + b[k + 1].second;
                c = max(c, d);
            }
        }

        return a + c;
    }
};