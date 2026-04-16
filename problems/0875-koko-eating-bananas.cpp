/*
 * Problem 0875: Koko Eating Bananas
 * URL     : https://leetcode.com/problems/koko-eating-bananas/
 * Solved  : 2026-04-03
 * Runtime : 6 ms
 * Memory  : 22.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minn=0,maxn=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            maxn=max(maxn,piles[i]);
        }
        int t=0;
        int ans=maxn;
        while(minn<=maxn)
        {
            t=0;
            int mid=(minn+maxn)/2;
            if(mid==0)
            break;
            for(int i=0;i<n;i++)
            {
                t+=(piles[i]/mid);
                if(piles[i]%mid!=0)
                t++;
            }
            if(t<=h)
            {
                maxn=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                minn=mid+1;
            }
        }
        return ans;
    }
};