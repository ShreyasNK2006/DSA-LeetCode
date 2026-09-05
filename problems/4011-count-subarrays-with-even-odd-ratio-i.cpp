/*
 * Problem 4011: Count Subarrays With Even Odd Ratio I
 * URL     : https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
 * Solved  : 2026-08-12
 * Runtime : 37 ms
 * Memory  : 31.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int> oc(n+1,0);
        for(int i=0;i<n;i++)
            {
                if(nums[i]%2==1)
                    oc[i+1]++;
                    oc[i+1]+=oc[i];
            }
        int c=0;
        double comp = (1.0*a)/b;
        //cout<<comp<<endl;
        for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<=n;j++)
                    {
                        int o = oc[j]-oc[i];
                        if(o>0 && ((1.0*j-i-o)/o <=comp))
                        {
                            //cout<<(1.0*j-i-o)/o<<endl;
                            c++;
                        }
                    }
            }
        return c;
    }
};