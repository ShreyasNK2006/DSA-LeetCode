/*
 * Problem 3960: Frequency Balance Subarray
 * URL     : https://leetcode.com/problems/frequency-balance-subarray/
 * Solved  : 2026-06-20
 * Runtime : 1618 ms
 * Memory  : 473.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int getLength(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> f,f2;
            for(int j=i;j<n;j++)
            {
                if(f2.find(nums[j])!=f2.end())
                {
                    f[f2[nums[j]]]--;
                    if(f[f2[nums[j]]]==0)
                    f.erase(f2[nums[j]]);
                    f2[nums[j]]++;
                    f[f2[nums[j]]]++;
                }
                else
                {
                    f2[nums[j]]++;
                    f[f2[nums[j]]]++;
                }
                if(f2.size()==1)
                c=max(c,j-i+1);
                else if(f.size()==2)
                {
                    auto it=f.begin();
                    int v=it->first,v2;
                    v2=(++it)->first;
                    if(v==2*v2 || v2==2*v)
                    c=max(c,j-i+1);
                }
            }
        }
        return c;
    }
};