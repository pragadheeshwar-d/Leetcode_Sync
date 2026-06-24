class Solution {
private:
    const int MOD = 1e9 + 7;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        vector<vector<long long>> T(size, vector<long long>(size, 0));
        
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < y; ++x) {
                T[y][m + x] = 1; 
            }
        }

        for (int y = 0; y < m; ++y) {
            for (int x = y + 1; x < m; ++x) {
                T[m + y][x] = 1;
            }
        }

        T = power(T, n - 1, size);

        long long total_arrays = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                total_arrays = (total_arrays + T[i][j]) % MOD;
            }
        }

        return total_arrays;
    }
};