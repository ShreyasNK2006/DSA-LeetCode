/*
 * Problem 2958: Length of Longest Subarray With at Most K Frequency
 * URL     : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
 * Solved  : 2026-08-12
 * Runtime : 1112 ms
 * Memory  : 302.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,queue<int>> mp;
        unordered_map<int,int> fq;
        int maxlen=0;
        int n=nums.size();
        int st=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(fq[nums[i]]<k)
            fq[nums[i]]++;
            else
            {
                st=mp[nums[i]].front()+1;
                mp[nums[i]].pop();
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    c++;
                    while(!mp[it->first].empty() && mp[it->first].front()<st)
                    {
                        mp[it->first].pop();
                        fq[it->first]--;
                    }
                }
            }
            mp[nums[i]].push(i);
            maxlen=max(maxlen,i-st+1);
        }
        return maxlen;
    }
};