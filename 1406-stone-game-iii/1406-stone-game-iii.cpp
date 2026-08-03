class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int n = v.size();
        int a = 0, b = 0, c = 0, d = 0;

        for (int i = n - 1; i >= 0; --i) {
            int m = INT_MIN;
            int s = 0;

            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                s += v[i + k - 1];
                int prev = (k == 1) ? a : (k == 2) ? b : c;
                m = max(m, s - prev);
            }

            d = c;
            c = b;
            b = a;
            a = m;
        }

        if (a > 0) return "Alice";
        if (a < 0) return "Bob";
        return "Tie";
    }
};