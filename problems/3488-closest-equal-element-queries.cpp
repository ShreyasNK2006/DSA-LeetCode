/*
 * Problem 3488: Closest Equal Element Queries
 * URL     : https://leetcode.com/problems/closest-equal-element-queries/
 * Solved  : 2026-04-16
 * Runtime : 238 ms
 * Memory  : 216.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end());
        }
        for (auto q : queries) {
            int num = nums[q];
            if (mp[num].size() == 1) {
                res.push_back(-1);
                continue;
            }
            auto& vec = mp[num];
            int mind = INT_MAX;
            auto it = lower_bound(vec.begin(), vec.end(), q);
            if (it != vec.end()) {
                int val = *it;
                if (val != q)
                    mind = min(mind, min(abs(val - q), n - abs(val - q)));
            }
            if(*it==q && it+1!=vec.end())
            {
                int val=*(it+1);
                 mind = min(mind, min(abs(val - q), n - abs(val - q)));
            }
            if (it != vec.begin()) {
                int val = *(it - 1);
                if (val != q)
                    mind = min(mind, min(abs(val - q), n - abs(val - q)));
            }
            int first = vec[0];
            int last = vec.back();

            if (first != q)
                mind = min(mind, min(abs(first - q), n - abs(first - q)));

            if (last != q)
                mind = min(mind, min(abs(last - q), n - abs(last - q)));
            res.push_back(mind);
        }
        return res;
    }
};