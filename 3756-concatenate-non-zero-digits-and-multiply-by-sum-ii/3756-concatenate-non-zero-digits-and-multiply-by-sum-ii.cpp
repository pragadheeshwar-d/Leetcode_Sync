#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1000000007;
        
        vector<int> nz_digits;
        vector<int> nz_indices;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                nz_digits.push_back(s[i] - '0');
                nz_indices.push_back(i);
            }
        }
        
        int n = nz_digits.size();
        if (n == 0) {
            return vector<int>(queries.size(), 0);
        }
        
        vector<long long> P(n);
        vector<long long> pref_sum(n);
        vector<long long> pow10(n + 1, 1);
        
        for (int i = 0; i < n; ++i) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            if (i == 0) {
                P[i] = nz_digits[i] % MOD;
                pref_sum[i] = nz_digits[i];
            } else {
                P[i] = (P[i - 1] * 10 + nz_digits[i]) % MOD;
                pref_sum[i] = pref_sum[i - 1] + nz_digits[i];
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            auto lit = lower_bound(nz_indices.begin(), nz_indices.end(), l);
            auto rit = upper_bound(nz_indices.begin(), nz_indices.end(), r);
            
            if (lit == nz_indices.end() || lit >= rit) {
                answer.push_back(0);
                continue;
            }
            
            int L = distance(nz_indices.begin(), lit);
            int R = distance(nz_indices.begin(), rit) - 1;
            
            long long x = P[R];
            if (L > 0) {
                x = (x - P[L - 1] * pow10[R - L + 1]) % MOD;
                if (x < 0) x += MOD;
            }
            
            long long current_sum = pref_sum[R];
            if (L > 0) {
                current_sum -= pref_sum[L - 1];
            }
            
            long long ans = (x * (current_sum % MOD)) % MOD;
            answer.push_back(ans);
        }
        
        return answer;
    }
};