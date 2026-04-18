/*
 * Problem 0740: Delete and Earn
 * URL     : https://leetcode.com/problems/delete-and-earn/
 * Solved  : 2026-04-03
 * Runtime : 9 ms
 * Memory  : 16.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int pcost=0,currcost=0;
        int pos=0,prev=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int temp=currcost;
            if(pos==0)
            pcost=(it->first)*(it->second);
            else if(pos==1)
            {
                if(it->first-prev>1)
                currcost=pcost+(it->first)*(it->second);
                else
                currcost=max(pcost,(it->first)*(it->second));
            }
            else
            {
                if(it->first-prev==1)
                currcost=max(pcost+((it->first)*(it->second)),currcost);
                else
                currcost=currcost+((it->first)*(it->second));
            }
            pos++;
            prev=it->first;
            if(pos>2)
            pcost=temp;
        }
        return max(currcost,pcost);
    }
};