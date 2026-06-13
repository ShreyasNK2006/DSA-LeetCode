/*
 * Problem 1848: Minimum Distance to the Target Element
 * URL     : https://leetcode.com/problems/minimum-distance-to-the-target-element/
 * Solved  : 2026-04-13
 * Runtime : 0 ms
 * Memory  : 13.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mind=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            mind=min(mind,abs(start-i));
        }
        return mind;
    }
};