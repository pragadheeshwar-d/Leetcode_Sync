#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> distToThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    distToThief[r][c] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && distToThief[nr][nc] == -1) {
                    distToThief[nr][nc] = distToThief[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<int>> maxSafeness(n, vector<int>(n, -1));

        maxHeap.push({distToThief[0][0], {0, 0}});
        maxSafeness[0][0] = distToThief[0][0];

        while (!maxHeap.empty()) {
            auto [safeness, cell] = maxHeap.top();
            auto [r, c] = cell;
            maxHeap.pop();

            if (r == n - 1 && c == n - 1) {
                return safeness;
            }

            if (safeness < maxSafeness[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int nextSafeness = min(safeness, distToThief[nr][nc]);
                    
                    if (nextSafeness > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = nextSafeness;
                        maxHeap.push({nextSafeness, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};