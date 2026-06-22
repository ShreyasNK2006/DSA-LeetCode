/*
 * Problem 3936: Minimum Swaps to Move Zeros to End
 * URL     : https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
 * Solved  : 2026-05-28
 * Runtime : 0 ms
 * Memory  : 31.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int c=0;
        int i=0,j=nums.size()-1;
        while(i<j)
            {
                if(j>0 && nums[j]==0)
                    j--;
                if(i<j && nums[i]!=0)
                    i++;
                if(nums[i]==0 && nums[j]!=0)
                {
                    swap(nums[i],nums[j]);
                    c++;
                    i++;
                    j--;
                }  
            }
        return c;
    }
};