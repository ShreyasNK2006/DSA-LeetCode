/*
 * Problem 2948: Make Lexicographically Smallest Array by Swapping Elements
 * URL     : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
 * Solved  : 2026-08-29
 * Runtime : 117 ms
 * Memory  : 145.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> pr(n);
        for(int i=0;i<n;i++)
        {
            pr[i]={nums[i],i};
        }
        sort(pr.begin(),pr.end());
        vector<int> res(n);
        vector<pair<int,int>> grp;
        int l=0,r=0;
        for(int i=1;i<n;i++)
        {
            if(pr[i].first-pr[i-1].first<=limit)
            r=i;
            else
            {
                grp.push_back({l,r});
                l=r=i;
            }
        }
        grp.push_back({l,r});
        for(auto it:grp)
        {
            vector<int> ind;
            for(int l=it.first;l<=it.second;l++)
            {
                ind.push_back(pr[l].second);
            }
            sort(ind.begin(),ind.end());
            int j=0;
            for(int l=it.first;l<=it.second;l++,j++)
            {
                res[ind[j]]=pr[l].first;
            }
        }
        return res;
    }
};