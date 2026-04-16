/*
 * Problem 0015: 3Sum
 * URL     : https://leetcode.com/problems/3sum/
 * Solved  : 2026-04-02
 * Runtime : 72 ms
 * Memory  : 29.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int a=nums[i];
            int lt=i+1;
            int rt=n-1;
            while(lt<rt)
            {
                int sum=(a+nums[lt]+nums[rt]);
                if(sum==0)
                {
                    res.push_back({a,nums[lt],nums[rt]});
                    lt++;
                    rt--;
                }
                else if(sum<0)
                lt++;
                else
                rt--;
                while(lt<rt && lt>i+1 && nums[lt-1]==nums[lt])
                lt++;
                while(lt<rt && rt<n-1 && nums[rt]==nums[rt+1])
                rt--;
            }
        }
        return res;
    }
};