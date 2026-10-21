/*
 * Problem 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum
 * URL     : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * Solved  : 2026-09-17
 * Runtime : 310 ms
 * Memory  : 202.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int,int> mp,mp1;
        int n = arr.size();
        vector<int> valid(n,INT_MAX);
        int curr=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            curr+=arr[i];
            if(curr>=target)
            {
                auto it = mp.find(curr-target);
                if(it!=mp.end())
                {
                    valid[i]=i-it->second;
                }
            }
            mp[curr]=i;
        }
         vector<int> valid2(n,INT_MAX);
        curr=0;
        mp1[0]=n;
        for(int i=n-1;i>=0;i--)
        {
            curr+=arr[i];
            if(curr>=target)
            {
                auto it = mp1.find(curr-target);
                if(it!=mp.end())
                {
                    valid2[i]=it->second-i;
                }
            }
            mp1[curr]=i;
        }
        vector<int>minend(n,INT_MAX);
        minend[n-1]=valid2[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minend[i]=min(minend[i+1],valid2[i]);
        }
        int curmin=INT_MAX;
        int ans=INT_MAX;
        bool ch=false;
        for(int i=0;i<n-1;i++)
        {
            curmin=min(curmin,valid[i]);
            if(curmin!=INT_MAX && minend[i+1]!=INT_MAX)
            {
                ch =true;
                ans = min(ans,curmin+minend[i+1]);
            }
        }
        if(ch)
        return ans;
        return -1;
    }
};