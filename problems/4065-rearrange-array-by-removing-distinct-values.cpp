/*
 * Problem 4065: Rearrange Array by Removing Distinct Values
 * URL     : https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/
 * Solved  : 2026-09-27
 * Runtime : 11 ms
 * Memory  : 37.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(auto it:nums)
            {
                mp[it]++;
            }
        int uniq=mp.size();
        while(uniq!=0)
        {
            map<int,int> cp= mp;
            for(auto  it:cp)
                {
                    ans.push_back(it.first);
                    mp[it.first]--;
                    if(mp[it.first]==0)
                    mp.erase(it.first);
                }
            uniq=mp.size();
        }
        return ans;
    }
};