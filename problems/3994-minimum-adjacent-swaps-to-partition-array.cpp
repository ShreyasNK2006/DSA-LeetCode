/*
 * Problem 3994: Minimum Adjacent Swaps to Partition Array
 * URL     : https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
 * Solved  : 2026-08-06
 * Runtime : 12 ms
 * Memory  : 160.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod  1000000007
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int l=0;
        // case 1 lesser than a
        int swaps=0;
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<a)
            {
                swaps=(swaps + i-l)%mod;
                l++;
            }
            else
            {
                temp.push_back(nums[i]);
            }
        }
        l=0;
        for(int i=0;i<temp.size();i++)
        {
            
            if(temp[i]<=b)
            {
                swaps=(swaps+i-l)%mod;
                l++;
            }
        }
        return swaps;
    }
};