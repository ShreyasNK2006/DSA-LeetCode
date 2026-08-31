/*
 * Problem 0042: Trapping Rain Water
 * URL     : https://leetcode.com/problems/trapping-rain-water/
 * Solved  : 2026-08-01
 * Runtime : 4 ms
 * Memory  : 27.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lmax(n+1,0),rmax(n+1,0);
        for(int i=0;i<n;i++)
        {
            lmax[i+1]=max(lmax[i],height[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],height[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=res+max(0,(min(rmax[i],lmax[i])-height[i]));
        }
        return res;
    }
};