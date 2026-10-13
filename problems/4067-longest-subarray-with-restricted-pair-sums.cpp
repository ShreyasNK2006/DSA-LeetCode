/*
 * Problem 4067: Longest Subarray With Restricted Pair Sums
 * URL     : https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/
 * Solved  : 2026-09-27
 * Runtime : 632 ms
 * Memory  : 29.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp,mp2,prev;
        int st=0;
        int maxlen=1;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=500;k++)
            {
                auto it1 = mp.find(k);
                auto it2 = mp.find(nums[i]-k);
                int limit;
                if(nums[i]>k && it1!=mp.end() && it2!=mp.end() && !(nums[i]==2*k && mp2[k]==1))
                {
                    //cout<<st<<'a';
                    if(2*k == nums[i])
                    {
                        limit = prev[k];
                    }
                    else
                    limit = min(it1->second,it2->second);
                    for(int j=st;j<=limit;j++)
                    {
                        mp2[nums[j]]--;
                        if(mp2[nums[j]]==0)
                        mp.erase(nums[j]);
                    }
                    st=limit+1;
                }
                it1 = mp.find(k);
                auto it3 = mp.find(k+nums[i]);
                if(it1!=mp.end() && it3!=mp.end())
                {
                    //cout<<st<<'b';
                    limit = min(it1->second,it3->second);
                    for(int j=st;j<=limit;j++)
                    {
                        mp2[nums[j]]--;
                        if(mp2[nums[j]]==0)
                        mp.erase(nums[j]);
                    }
                    st=limit+1;
                }
            }
            maxlen = max(maxlen,i-st+1);
            mp2[nums[i]]++;
            if(mp.count(nums[i])>0)
            prev[nums[i]]=mp[nums[i]];
            mp[nums[i]]=i;
        }
        return maxlen;
    }
};