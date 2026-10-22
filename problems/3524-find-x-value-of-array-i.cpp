/*
 * Problem 3524: Find X Value of Array I
 * URL     : https://leetcode.com/problems/find-x-value-of-array-i/
 * Solved  : 2026-09-21
 * Runtime : 166 ms
 * Memory  : 142.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k,0);
        vector<int> f(k,0);
        long long prod=1;
        for(int i=0;i<n;i++)
        {
            prod = nums[i];
            prod%=k;
            vector<int> temp(k,0);
            temp[prod]++;
            for(int j=0;j<k;j++)
            temp[(j*prod) %k]+=f[j];
            for(int j=0;j<k;j++)
            {
                f[j]=temp[j];
                res[j]+=f[j];
            }
        }
        return res;
    }
};