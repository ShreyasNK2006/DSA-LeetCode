/*
 * Problem 1846: Maximum Element After Decreasing and Rearranging
 * URL     : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
 * Solved  : 2026-06-28
 * Runtime : 7 ms
 * Memory  : 55.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int maxe=1;
        int n=arr.size();
        arr[0]=1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]>1)
            arr[i+1]=arr[i]+1;
            maxe=max(maxe,arr[i+1]);
        }
        return maxe;
    }
};