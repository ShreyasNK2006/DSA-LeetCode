/*
 * Problem 2342: Max Sum of a Pair With Equal Sum of Digits
 * URL     : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
 * Solved  : 2026-05-07
 * Runtime : 92 ms
 * Memory  : 90.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int x:nums)
        {
            int d=0;
            int temp=x;
            while(temp)
            {
                d+=(temp%10);
                temp/=10;
            }
            mp[d].push_back(x);
        }
        int m=-1;
        for(auto it:mp)
        {
            if(it.second.size()>=2)
            {
                sort(it.second.rbegin(),it.second.rend());
                m=max(m,it.second[0]+it.second[1]);
            }
        }
        return m;
    }
};