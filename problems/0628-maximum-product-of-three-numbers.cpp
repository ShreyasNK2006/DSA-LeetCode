/*
 * Problem 0628: Maximum Product of Three Numbers
 * URL     : https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Solved  : 2026-07-26
 * Runtime : 11 ms
 * Memory  : 34.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> pos, neg;
        int c=0;
        for(auto x:nums)
        {
            if(x>=0)
            pos.push_back(x);
            else if (x<0)
            neg.push_back(x);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        int np=1,pp=1;
        int n1= pos.size(),n2=neg.size();
        if(n2>=2)
        np=neg[0]*neg[1];
        if(n1>=2)
        pp=pos[n1-1]*pos[n1-2];
        int ans=INT_MIN;
        if(n1>2)
        {
            ans=max(ans,pp*pos[n1-3]);
        }
        if(n2>2 && n1>0)
        {
            ans=max(ans,np*pos[n1-1]);
        }
        if(n1>1 && n2>0)
        {
            ans=max(ans,pos[0]*pos[1]*neg[n2-1]);
        }
        if(n2>2)
        {
            ans= max(ans,neg[n2-1]*neg[n2-2]*neg[n2-3]);
        }
        if(n1>0 && n2 >1)
        {
            ans= max(ans,np*pos[n1-1]);
        }
        return ans;
    }
};