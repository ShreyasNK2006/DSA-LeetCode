/*
 * Problem 1340: Jump Game V
 * URL     : https://leetcode.com/problems/jump-game-v/
 * Solved  : 2026-05-24
 * Runtime : 11 ms
 * Memory  : 20 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void findmaxjumps(vector<int>& arr, vector<int>& lb, vector<int>& rb,
                      vector<int>& dp, int i) {
        if (dp[i] != -1)
            return;
        dp[i] = 1;

        int l = lb[i], r = rb[i];

        for (int j = l; j <= r; j++) {
            if (i != j) {
                if (dp[j] == -1) {
                    findmaxjumps(arr, lb, rb, dp, j);
                }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> dp(n, -1);
        vector<int> lb(n), rb(n);
        stack<int> st1;
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                st1.pop();
            }
            lb[i] = st1.empty() ? max(0, i - d) : max(i - d, st1.top() + 1);
            st1.push(i);
        }
        stack<int> st2;
        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && nums[st2.top()] < nums[i]) {
                st2.pop();
            }
            rb[i] = st2.empty() ? min(n - 1, i + d) : min(i + d, st2.top() - 1);
            st2.push(i);
        }

        int maxjump = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                findmaxjumps(nums, lb, rb, dp, i);
            }
            maxjump = max(maxjump, dp[i]);
        }

        return maxjump;
    }
};