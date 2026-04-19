/*
 * Problem 0239: Sliding Window Maximum
 * URL     : https://leetcode.com/problems/sliding-window-maximum/
 * Solved  : 2026-04-03
 * Runtime : 337 ms
 * Memory  : 175.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res(n-k+1);
        map<int,int> mp;
        for(int i=0;i<k-1;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=k-1;i<nums.size();i++)
        {
            mp[nums[i]]++;
            auto it = mp.rbegin();
            res[i-k+1]=it->first;
            mp[nums[i-k+1]]--;
            if(mp[nums[i-k+1]]==0)
            mp.erase(nums[i-k+1]);
        }
        return res;
    }
};