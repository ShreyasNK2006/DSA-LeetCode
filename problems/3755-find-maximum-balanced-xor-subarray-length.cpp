/*
 * Problem 3755: Find Maximum Balanced XOR Subarray Length
 * URL     : https://leetcode.com/problems/find-maximum-balanced-xor-subarray-length/
 * Solved  : 2026-05-23
 * Runtime : 878 ms
 * Memory  : 440 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int diff=0,n=nums.size();
        unordered_map<long long,unordered_map<int,int>> mp;
        mp[0][0]=0;
        int maxlen=0;
        long long xorres=0;
        for(int i=0;i<n;i++)
        {
            xorres^=nums[i];
            if(nums[i]%2==0)
            diff++;
            else
            diff--;
            if(diff==0 && xorres==0)
            maxlen=i+1;
            if(mp.find(xorres)!=mp.end() && mp[xorres].find(diff)!=mp[xorres].end())
            {
                maxlen=max(maxlen,i-mp[xorres][diff]);
            }
            else
            {
                mp[xorres][diff]=i;
            }
        }
        return maxlen;
    }
};