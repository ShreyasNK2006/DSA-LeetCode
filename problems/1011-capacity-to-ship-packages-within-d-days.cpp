/*
 * Problem 1011: Capacity To Ship Packages Within D Days
 * URL     : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Solved  : 2026-09-27
 * Runtime : 13 ms
 * Memory  : 35.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int cap;
    void binsearch(vector<int> &weights, int l, int r,int days)
    {
        int n = weights.size();
        while(l<=r)
        {
            int mid = (l+r)/2;
            //bool valid = true;
            int d =1;
            int c=0;
            for(int i=0;i<n;i++)
            {
                if((c+weights[i])<=mid)
                {
                    c+=weights[i];
                    continue;
                }
                else
                {
                    c=weights[i];
                    d++;
                }
            }
            if(d<=days)
            {
                cap=min(cap,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mind = 0,maxd=0;
        for(auto it:weights)
        {
            maxd+=it;
            mind = max(mind,it);
        }
        cap = maxd;
        binsearch(weights,mind,maxd,days);
        return cap;
    }
};