class Solution {
    long long nCr(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        double res = 1.0;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > cap) return cap;
        }
        return res;
    }

    long long countWays(vector<int>& cnt, long long cap) {
        int total = 0;
        for (int c : cnt) total += c;
        long long ways = 1;
        for (int c : cnt) {
            if (c > 0) {
                ways *= nCr(total, c, cap);
                if (ways >= cap) return cap;
                total -= c;
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) 
            cnt[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2 != 0) mid = 'a' + i;
        }

        if (countWays(half, k + 1) < k) return "";

        int m = s.length() / 2;
        string left = "";

        for (int i = 0; i < m; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half, k + 1);

                if (ways >= k) {
                    left += (char)('a' + c);
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        
        return (s.length() % 2 != 0) ? left + mid + right : left + right;
    }
};