/*
 * Problem 3548: Equal Sum Grid Partition II
 * URL     : https://leetcode.com/problems/equal-sum-grid-partition-ii/
 * Solved  : 2026-03-26
 * Runtime : 1003 ms
 * Memory  : 433.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rs(m, 0), cs(n, 0);
        unordered_map<long long, int> mp1;
        long long totalsum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalsum += grid[i][j];
                cs[j] += grid[i][j];
                mp1[grid[i][j]]++;
            }
            rs[i] = totalsum;
        }
        unordered_map<long long, int> mp2, mp3;
        mp3 = mp1;
        if (2 * rs[0] == totalsum)
            return true;
        {
            for (int j = 0; j < n; j++) {
                mp2[grid[0][j]]++;
                mp1[grid[0][j]]--;
            }
            if (2 * rs[0] > totalsum &&
                ((rs[0] - grid[0][0] == (totalsum - rs[0])) ||
                 (rs[0] - grid[0][n - 1] == (totalsum - rs[0]))))
                return true;
            if (m > 2 && n > 1 && 2 * rs[0] < totalsum &&
                mp1.find(totalsum - 2 * rs[0]) != mp1.end() &&
                mp1[totalsum - 2 * rs[0]] > 0)
                return true;
            else if (m > 2 && n == 1 && 2 * rs[0] < totalsum &&
                     ((totalsum - rs[0] - grid[1][0]) == rs[0] ||
                      (totalsum - rs[0] - grid[m - 1][0]) == rs[0]))
                return true;
            else if (m == 2 && 2 * rs[0] < totalsum &&
                     (((totalsum - rs[0] - grid[m - 1][0]) == (rs[0])) ||
                      ((totalsum - rs[0] - grid[m - 1][n - 1]) == rs[0])))
                return true;
        }
        for (int i = 1; i < m - 2; i++) {
            if (2 * rs[i] == totalsum)
                return true;
            for (int j = 0; j < n; j++) {
                mp2[grid[i][j]]++;
                mp1[grid[i][j]]--;
            }
            if (2 * rs[i] > totalsum) {
                if (n > 1 && mp2.find(2 * rs[i] - totalsum) != mp2.end() &&
                    mp2[2 * rs[i] - totalsum] > 0)
                    return true;
                else if (n == 1 &&
                         ((rs[i] - (totalsum - rs[i])) == grid[0][0] ||
                          (rs[i] - (totalsum - rs[i])) == grid[i][0]))
                    return true;
            } else if (2 * rs[i] < totalsum) {
                if (n > 1 && mp1.find(totalsum - 2 * rs[i]) != mp1.end() &&
                    mp1[totalsum - 2 * rs[i]] > 0)
                    return true;
                else if (n == 1 &&
                         ((totalsum - rs[i] - rs[i]) == grid[i + 1][0] ||
                          (totalsum - rs[i] - rs[i]) == grid[m - 1][0]))
                    return true;
            }
        }
        if (m > 2 && 2 * rs[m - 2] == totalsum)
            return true;
        if (m > 2) {
            for (int j = 0; j < n; j++) {
                mp2[grid[m - 2][j]]++;
                mp1[grid[m - 2][j]]--;
            }
            if (2 * rs[m - 2] > totalsum) {
                if (n > 1 && mp2.find(2 * rs[m - 2] - totalsum) != mp2.end() &&
                    mp2[2 * rs[m - 2] - totalsum] > 0)
                    return true;
                else if (n == 1 &&
                         ((rs[m - 2] - (totalsum - rs[m - 2])) == grid[0][0] ||
                          (rs[m - 2] - (totalsum - rs[m - 2])) ==
                              grid[m - 2][0]))
                    return true;
            } else if (2 * rs[m - 2] < totalsum) {
                if (n > 1 &&
                    (((totalsum - rs[m - 2] - grid[m - 1][0]) == (rs[m - 2])) ||
                     ((totalsum - rs[m - 2] - grid[m - 1][n - 1]) ==
                      rs[m - 2])))
                    return true;
                else if (n == 1 &&
                         ((totalsum - rs[m - 2] - grid[m - 1][0]) == rs[m - 2]))
                    return true;
            }
        }
        unordered_map<long long, int> mp4;
        if (2 * cs[0] == totalsum)
            return true;
        {
            for (int j = 0; j < m; j++) {
                mp4[grid[j][0]]++;
                mp3[grid[j][0]]--;
            }
            if (2 * cs[0] > totalsum &&
                (((cs[0] - grid[0][0]) == (totalsum - cs[0])) ||
                 (cs[0] - grid[m - 1][0] == (totalsum - cs[0]))))
                return true;
            if (n > 2 && m > 1 && 2 * cs[0] < totalsum &&
                mp3.find(totalsum - 2 * cs[0]) != mp3.end() &&
                mp3[totalsum - 2 * cs[0]] > 0)
                return true;
            else if (n > 2 && m == 1 && 2 * cs[0] < totalsum &&
                     ((totalsum - cs[0] - grid[0][1]) == cs[0] ||
                      (totalsum - cs[0] - grid[0][n - 1]) == cs[0]))
                return true;
            else if (n == 2 && 2 * cs[0] < totalsum &&
                     (((totalsum - cs[0] - grid[0][n - 1]) == (cs[0])) ||
                      ((totalsum - cs[0] - grid[m - 1][n - 1]) == cs[0])))
                return true;
        }
        for (int i = 1; i < n - 2; i++) {
            cs[i] += cs[i - 1];
            if (2 * cs[i] == totalsum)
                return true;
            for (int j = 0; j < m; j++) {
                mp4[grid[j][i]]++;
                mp3[grid[j][i]]--;
            }
            if (2 * cs[i] > totalsum) {
                if (m > 1 && mp4.find(2 * cs[i] - totalsum) != mp4.end() &&
                    mp4[2 * cs[i] - totalsum] > 0)
                    return true;
                else if (m == 1 &&
                         ((cs[i] - (totalsum - cs[i])) == grid[0][0] ||
                          (cs[i] - (totalsum - cs[i])) == grid[0][i]))
                    return true;
            } else if (2 * cs[i] < totalsum) {
                if (m > 1 && mp3.find(totalsum - 2 * cs[i]) != mp3.end() &&
                    mp3[totalsum - 2 * cs[i]] > 0)
                    return true;
                else if (m == 1 &&
                         ((totalsum - cs[i] - cs[i]) == grid[0][i + 1] ||
                          (totalsum - cs[i] - cs[i]) == grid[0][n - 1]))
                    return true;
            }
        }
        if (n > 2) {
            cs[n - 2] += cs[n - 3];
        } else
            return false;
        if (2 * cs[n - 2] == totalsum)
            return true;
        {
            for (int j = 0; j < m; j++) {
                mp4[grid[j][n - 2]]++;
                mp3[grid[j][n - 2]]--;
            }
            if (2 * cs[n - 2] > totalsum) {
                if (m > 1 && mp4.find(2 * cs[n - 2] - totalsum) != mp4.end() &&
                    mp4[2 * cs[n - 2] - totalsum] > 0)
                    return true;
                else if (m == 1 &&
                         ((cs[n - 2] - (totalsum - cs[n - 2])) == grid[0][0] ||
                          (cs[n - 2] - (totalsum - cs[n - 2])) ==
                              grid[0][n - 2]))
                    return true;
            } else if (2 * cs[n - 2] < totalsum) {
                if (m > 1 &&
                    (((totalsum - cs[n - 2] - grid[0][n - 1]) == (cs[n - 2])) ||
                     ((totalsum - cs[n - 2] - grid[m - 1][n - 1]) ==
                      cs[n - 2])))
                    return true;
                else if (m == 1 &&
                         ((totalsum - cs[n - 2] - grid[0][n - 1]) == cs[n - 2]))
                    return true;
            }
        }
        return false;
    }
};