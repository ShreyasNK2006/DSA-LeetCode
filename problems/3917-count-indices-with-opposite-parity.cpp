/*
 * Problem 3917: Count Indices With Opposite Parity
 * URL     : https://leetcode.com/problems/count-indices-with-opposite-parity/
 * Solved  : 2026-05-03
 * Runtime : 7 ms
 * Memory  : 33.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n,0);
        for(int i=n-1;i>=0;i--)
            {
                if(nums[i]%2==1)
                    odd[i]++;
                if(i<n-1)
                    odd[i]+=odd[i+1];
            }
        vector<int> score(n,0);
        for(int i=0;i<n-1;i++)
            {
                if(nums[i]%2==0)
                {
                    score[i]=odd[i];
                }
                else
                    score[i]=(n-i-1-odd[i+1]);
            }
        return score;
    }
};