/*
 * Problem 3524: Find X Value of Array I
 * URL     : https://leetcode.com/problems/find-x-value-of-array-i/
 * Solved  : 2026-09-22
 * Runtime : 172 ms
 * Memory  : 151.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k,0);
        vector<long long> prev(k,0);
        for(int i=0;i<n;i++)
        {
            vector<long long> curr(k,0);
            long long prod = nums[i]%k;
            curr[prod]++;
            for(int j=0;j<k;j++)
            {
                curr[(prod*j)%k]+=prev[j];
            }
            for(int j=0;j<k;j++)
            {
                prev[j]=curr[j];
                res[j]+=curr[j];
            }
        }
        return res;
    }
};