/*
 * Problem 4038: Count Integers Appearing in a Single Block
 * URL     : https://leetcode.com/problems/count-integers-appearing-in-a-single-block/
 * Solved  : 2026-08-30
 * Runtime : 0 ms
 * Memory  : 20.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        unordered_map<int,int> fq;
        for(int i=0;i<n;i++)
            {
                fq[nums[i]]++;
            }
        int curr=nums[0];
        int f=1;
        if(f==fq[nums[0]])
            c++;
        for(int i=1;i<n;i++)
            {
                if(curr==nums[i])
                    f++;
                else
                {
                    f=1;
                    curr=nums[i];
                }
                if(f==fq[nums[i]])
                {
                    c++;
                }
            }
        return c;
    }
};