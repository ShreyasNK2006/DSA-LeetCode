/*
 * Problem 2540: Minimum Common Value
 * URL     : https://leetcode.com/problems/minimum-common-value/
 * Solved  : 2026-05-19
 * Runtime : 0 ms
 * Memory  : 54.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(nums1[i]==nums2[j])
            return nums1[i];
            else if(nums1[i]>nums2[j])
            j++;
            else
            i++;
        }
        return -1;
    }
};