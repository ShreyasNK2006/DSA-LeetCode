/*
 * Problem 4044: Count Good Cyclic Rotations
 * URL     : https://leetcode.com/problems/count-good-cyclic-rotations/
 * Solved  : 2026-09-06
 * Runtime : 11 ms
 * Memory  : 119.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n= nums.size();
        vector<long long> prefix(2*n,0);
        for(int i=0;i<2*n;i++)
        {
            prefix[i]=nums[i%n];
            if(i>0)
            prefix[i]+=prefix[i-1];
        }
        long long t= prefix[n-1];
        int c=0;
        for(int i=0;i<n;i++)
        {
            long long b =0;
            if(i>0)
            b=prefix[i-1];
            if(t<2*(prefix[i+n/2-1]-b))
            c++;
            //cout<<(prefix[i+n/2-1]-b)<<endl;
        }
        return c;
    }
};